//=============================================================================
//	THIS SOURCE CODE IS PROPRIETARY INFORMATION BELONGING TO INTERVIDEO, INC.
// 	ANY USE INCLUDING BUT NOT LIMITED TO COPYING OF CODE, CONCEPTS, AND/OR
//	ALGORITHMS IS PROHIBITED EXCEPT WITH EXPRESS WRITTEN PERMISSION BY THE 
//	COMPANY.
//
// 	THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
// 	KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// 	IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
// 	PURPOSE.
//
// 	Copyright (c) 1998 - 2005  InterVideo Corporation.  All Rights Reserved.
//
//-----------------------------------------------------------------------------

#ifndef _TS_H_
#define _TS_H_

#if defined(__linux__)
#define TS_STDCALL
#else
#define TS_STDCALL __stdcall
#endif

/**
// Timestamps are either signed or unsigned.
// A signed pts will sign extend/scale differently than an unsigned pts.
//		a) DVD is unsigned
//		b) DirectShow is signed
//
// Timestamps have a size between 2 bits and 64 bits.
// Get() will properly sign extend to 64 bits IF the timestamp is signed
// All arithmetic computation will be as if performed at the timestamp bit size.
//		a) DVD is 32 bits
//		b) Program stream is 33 bits
//		c) DirectShow is 64 bits
//
// Timestamps can be made invalid.
// The Valid/Invalid property can be set and retrieved.
// An invalid timestamp is always "less than" a valid timestamp.
// Two invalid timestamps are equal.
//
// All input functions take a signed input timestamp, not due to multiplication
// issues but due to division issues.
//
// CAVEAT:
//		a) There are no unsigned 64 bit Add/Subtract/Set capabilities at this time.
//		b) There may be precision problems with frequency conversion, we do our best to preserve precision.
//
*/

#include "..\..\Exports\Inc\IH264VDec.h"

using namespace H264VDecParam;

class CH264Ts : public H264_TS
{
public:
	CH264Ts(__int64 Ts, unsigned int Freq, unsigned int Tslength = 0, unsigned int Flags = 0)
	{
		freq = Freq;
		tslength = (unsigned char)(Tslength ? Tslength : 64);
		flags    = (unsigned char)Flags;
		ts = Ts & GetMask();
	}

	CH264Ts()
	{
		freq = 0;
		tslength = 64;
		flags = H264_TS_FLAG_INVALID;
		ts = 0;
	}

	inline unsigned __int64	Get(unsigned int Freq = 0) const;
	inline unsigned	int		GetFrequency() const;
	inline unsigned int		GetPrecision() const;
#ifdef USE_SIGMA
	inline void				SetPrecision(unsigned int Tslength);
#endif
	inline void				Set(__int64 Ts, unsigned int Freq = 0);
	inline void				Set(const CH264Ts& Ts);
	inline void				Add(__int64 Ts, unsigned int Freq = 0);
	inline void				Add(const CH264Ts& Ts);
	inline void				Sub(__int64 Ts, unsigned int Freq = 0);
	inline void				Sub(const CH264Ts& Ts);
	inline bool				operator >=(const CH264Ts& Ts) const;
	inline bool				operator <=(const CH264Ts& Ts) const;
	inline bool				operator >(const CH264Ts& Ts) const;
	inline bool				operator <(const CH264Ts& Ts) const;
	inline bool				operator ==(const CH264Ts& Ts) const;
	inline bool				operator !=(const CH264Ts& Ts) const;
	inline bool				IsInvalid() const;
	inline bool				IsValid() const;
	inline void				SetInvalid();
	inline void				SetValid();
	inline bool				IsSigned() const;
	inline bool				IsUnsigned() const;
	inline void				SetSigned();
	inline void				SetUnsigned();
	inline void				RoundTo(unsigned int Freq);
	static inline __int64 TS_STDCALL			ConvertTs(__int64 Ts, unsigned int fromFreq, unsigned int toFreq);
	static inline unsigned __int64 TS_STDCALL	ConvertTs(unsigned __int64 Ts, unsigned int fromFreq, unsigned int toFreq);
	static inline unsigned int TS_STDCALL		Gcd(unsigned int freq1, unsigned int freq2);

private:
	inline unsigned __int64 GetMask() const;
	inline unsigned __int64 GetSignBit() const;
	inline unsigned __int64 GetSignExtension() const;
	inline __int64			SignExtend(__int64 Ts) const;
};

inline CH264Ts	operator +(const CH264Ts& Ts1, const CH264Ts& Ts2);
inline CH264Ts	operator -(const CH264Ts& Ts1, const CH264Ts& Ts2);

unsigned __int64 CH264Ts::Get(unsigned int Freq) const
{
	if(IsSigned())
		return ConvertTs(SignExtend(ts),freq,Freq);
	else
		return ConvertTs(ts,freq,Freq);
}

unsigned int CH264Ts::GetFrequency() const
{
	return freq;
}

unsigned int CH264Ts::GetPrecision() const
{
	return tslength;
}

#ifdef USE_SIGMA
void CH264Ts::SetPrecision(unsigned int Tslength)
{
	tslength = Tslength;
}
#endif

void CH264Ts::Set(__int64 Ts, unsigned int Freq)
{
	ts = ConvertTs(Ts,Freq,freq);
	ts &= GetMask();
	freq = Freq;
	SetValid();
}

void CH264Ts::Set(const CH264Ts& Ts)
{
	ts = Ts.Get(freq) & GetMask();
	if(Ts.IsValid())
		SetValid();
	else
		SetInvalid();
}

void CH264Ts::Add(__int64 Ts, unsigned int Freq)
{
	ts += ConvertTs(Ts,Freq,freq);
	ts &= GetMask();
}

void CH264Ts::Add(const CH264Ts& Ts)
{
	ts += Ts.Get(freq);
	ts &= GetMask();
}

void CH264Ts::Sub(__int64 Ts, unsigned int Freq)
{
	ts -= ConvertTs(Ts,Freq,freq);
	ts &= GetMask();
}

void CH264Ts::Sub(const CH264Ts& Ts)
{
	ts -= Ts.Get(freq);
	ts &= GetMask();
}

bool CH264Ts::operator >=(const CH264Ts& Ts) const
{	// check against top bit of GetMask()
	return !(*this < Ts); 
}

bool CH264Ts::operator <=(const CH264Ts& Ts) const
{	// check against top bit of GetMask()
	return !(*this > Ts); 
}

bool CH264Ts::operator <(const CH264Ts& Ts) const
{	// check against top bit of GetMask()
	if(IsValid())
	{
		if(IsInvalid())
			return false;	// VALID<INVALID is false.
		else
			return (ts-Ts.Get(freq) & GetSignBit()) != 0;
	}
	else
		return Ts.IsValid(); // INVALID<INVALID is false, INVALD<VALID is true
}

bool CH264Ts::operator >(const CH264Ts& Ts) const
{	// check against top bit of GetMask()
	__int64 val;
	if(IsValid())
	{
		if(IsInvalid())
			return true;	// VALID>INVALID is false.
		else
		{
			val = ts-Ts.Get(freq);
			return val!=0 && (val&GetSignBit())==0;
		}
	}
	else
		return false; // INVALID>INVALID is false, INVALD>VALID is false
}

bool CH264Ts::operator ==(const CH264Ts& Ts) const
{
	return IsValid() && Ts.IsValid() && (ts-Ts.Get(freq) & GetMask())==0 || IsInvalid() && Ts.IsInvalid();
}

bool CH264Ts::operator !=(const CH264Ts& Ts) const
{
	return !(*this==Ts);
}

CH264Ts operator +(const CH264Ts& Ts1, const CH264Ts& Ts2)
{
	CH264Ts tmp_ts = Ts1;

	tmp_ts.Add(Ts2);
	return tmp_ts;
}

CH264Ts operator -(const CH264Ts& Ts1, const CH264Ts& Ts2)
{
	CH264Ts tmp_ts = Ts1;

	tmp_ts.Sub(Ts2);
	return tmp_ts;
}

bool CH264Ts::IsInvalid() const
{
	return (flags&H264_TS_FLAG_INVALID)!=0;
}

bool CH264Ts::IsValid() const
{
	return (flags&H264_TS_FLAG_INVALID)==0;
}

void CH264Ts::SetInvalid()
{
	flags |= H264_TS_FLAG_INVALID;
}

void CH264Ts::SetValid()
{
	flags &= ~H264_TS_FLAG_INVALID;
}

bool CH264Ts::IsSigned() const
{
	return (flags&H264_TS_FLAG_SIGNED)!=0;
}

bool CH264Ts::IsUnsigned() const
{
	return (flags&H264_TS_FLAG_SIGNED)==0;
}

void CH264Ts::SetSigned()
{
	flags |= H264_TS_FLAG_SIGNED;
}

void CH264Ts::SetUnsigned()
{
	flags &= ~H264_TS_FLAG_SIGNED;
}

//
// RoundTo() rounds to the nearest common multiple of ticks in a different Freq. 
// This will disambiguate comparisons during frequency conversion.
//
void CH264Ts::RoundTo(unsigned int Freq)
{
	int uncommon;

	if(Freq==0 || freq==0 || Freq==freq)
		return;
	uncommon = Freq/Gcd(Freq,freq);	// uncommon factors
	if(IsSigned())					// align to uncommon factor.
		ts = ((__int64)ts)/uncommon*uncommon;	
	else
		ts = ts/uncommon*uncommon;
}

unsigned __int64 CH264Ts::GetMask() const
{
	if(tslength>=64)
		return (unsigned __int64)-1;
	return ((unsigned __int64)1<<tslength)-1;
}

unsigned __int64 CH264Ts::GetSignBit() const
{
	return (unsigned __int64)1<<(tslength-1);
	//return (GetMask()>>1)+1;
}

unsigned __int64 CH264Ts::GetSignExtension() const
{
	return ((unsigned __int64)-1) - GetMask();
}

__int64 CH264Ts::SignExtend(__int64 Ts) const
{
	if(Ts & GetSignBit())
		return Ts | GetSignExtension();
	return Ts;
}

__int64	TS_STDCALL CH264Ts::ConvertTs(__int64 Ts, unsigned int fromFreq, unsigned int toFreq)
{
	int gcd;

	if(toFreq==0 || fromFreq==0 || toFreq==fromFreq)
		return Ts;
	gcd = Gcd(fromFreq,toFreq);
	return Ts*(__int64)(toFreq/gcd)/(__int64)(fromFreq/gcd);
}

unsigned __int64 TS_STDCALL CH264Ts::ConvertTs(unsigned __int64 Ts, unsigned int fromFreq, unsigned int toFreq)
{
	int gcd;

	if(toFreq==0 || fromFreq==0 || toFreq==fromFreq)
		return Ts;
	gcd = Gcd(fromFreq,toFreq);
	return Ts*(unsigned __int64)(toFreq/gcd)/(unsigned __int64)(fromFreq/gcd);
}

unsigned int TS_STDCALL CH264Ts::Gcd(unsigned int freq1, unsigned int freq2)
{
	int rem;

	//DP("GCD: %d %d\n",freq1, freq2);
	if(freq1<freq2)
		return Gcd(freq2, freq1);
	if((rem = freq1%freq2)==0)
		return freq2;
	return Gcd(freq2,rem);
}

#endif
