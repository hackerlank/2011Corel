#ifndef _VIDEO_PROCESSOR_YV12toYUY2_H_
#define _VIDEO_PROCESSOR_YV12toYUY2_H_

#include "VideoProcessorBase.h"

namespace VideoProcessor
{
	class CVideoProcessorYV12toYUY2 : public CVideoProcessorBase
	{
	public:
		CVideoProcessorYV12toYUY2();
		virtual ~CVideoProcessorYV12toYUY2();

	public:
		// IUnknown
		STDMETHOD(QueryInterface)(REFIID riid, void **ppv);
		STDMETHOD_(ULONG, AddRef)();
		STDMETHOD_(ULONG, Release)();

	protected:
		HRESULT _QueryVideoProcessorCaps( 
			/* [out] */ 
			VideoProcessorCaps **ppCaps);

		HRESULT _GetFilterPropertyRange( 
			/* [in] */ 
			VIDEO_FILTER VideoFilter,
			/* [out] */ 
			FilterValueRange* pFilterRange);

		HRESULT _GetProcAmpRange( 
			/* [in] */ 
			PROCAMP_CONTROL ProcAmpControl,
			/* [out] */ 
			ProcAmpValueRange* pProcAmpRange);

		HRESULT _SetVideoProcessorMode( 
			/* [in] */ 
			const VideoProcessorModes *pVPMode);

		HRESULT _GetVideoProcessorMode( 
			/* [out] */ 
			VideoProcessorModes *pVPMode);

		HRESULT _GetNumReferentSamples( 
			/* [out] */ 
			DWORD	*pNumBackwardRefSamples,
			/* [out] */ 
			DWORD	*pNumForwardRefSamples);

		HRESULT _VideoProcessBlt( 
			/* [in] */ 
			VideoBuffer *pRenderTarget,
			/* [in] */ 
			const VideoProcessBltParams *pBltParams,
			/* [size_is][in] */ 
			const VideoSample *pVideoSamples,
			/* [in] */ 
			UINT uNumSamples);

	private:
		/*
		void convert_weave_simple_b(int &i, int width, int stridey, int stridec, int pitch, int lines, const RECT &rect, TARGET_FRAME TargetFrame);
		void convert_weave_simple_bcs(int &i, int width, int stridey, int stridec, int pitch, int lines, const RECT &rect, TARGET_FRAME TargetFrame);
		void convert_average_simple_b(int &i, int width, int stridey, int stridec, int pitch, int lines, const RECT &rect);
		void convert_average_simple_bcs(int &i, int width, int stridey, int stridec, int pitch, int lines, const RECT &rect);
		*/

		void convert_weave_b(int &i, int width, int stridey, int stridec, int pitch, int lines, const RECT &rect, TARGET_FRAME TargetFrame);
		void convert_weave_bcs(int &i, int width, int stridey, int stridec, int pitch, int lines, const RECT &rect, TARGET_FRAME TargetFrame);
		void convert_weave_bcshg(int &i, int width, int stridey, int stridec, int pitch, int lines, const RECT &rect, TARGET_FRAME TargetFrame);
		void convert_average_b(int &i, int width, int stridey, int stridec, int pitch, int lines, const RECT &rect);
		void convert_average_bcs(int &i, int width, int stridey, int stridec, int pitch, int lines, const RECT &rect);
		void convert_average_bcshg(int &i, int width, int stridey, int stridec, int pitch, int lines, const RECT &rect);
		void convert_bob_b(int &i, int width, int stridey, int stridec, int pitch, int lines, const RECT &rect, TARGET_FRAME TargetFrame);
		void convert_bob_bcs(int &i, int width, int stridey, int stridec, int pitch, int lines, const RECT &rect, TARGET_FRAME TargetFrame);
		void convert_bob_bcshg(int &i, int width, int stridey, int stridec, int pitch, int lines, const RECT &rect, TARGET_FRAME TargetFrame);
		void convert_median_b(int &i, int width, int stridey, int stridec, int pitch, int lines, const RECT &rect, TARGET_FRAME TargetFrame);
		void convert_median_bcs(int &i, int width, int stridey, int stridec, int pitch, int lines, const RECT &rect, TARGET_FRAME TargetFrame);
		void convert_median_bcshg(int &i, int width, int stridey, int stridec, int pitch, int lines, const RECT &rect, TARGET_FRAME TargetFrame);

		unsigned char *m_y1, *m_uv;
		unsigned char *m_dst1;
		int m_voffs;

		// ColorEffect
		HRESULT	SetProcAmpValues(const ProcAmpValues* pProcAmpValues);
		unsigned char *m_adjust_up;
		unsigned char *m_adjust_down;
		short	*m_adjust_multiply_yuv;
		short	*m_adjust_offset_yuv;
		short	*m_adjust_hue_yuv;
		short	*m_adjust_gamma_yuv;
		
	};
}

#endif // _VIDEO_PROCESSOR_YV12toYUY2_H_