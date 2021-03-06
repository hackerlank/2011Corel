//*****************************************************************************
//                               S3dxvaEncrypt.h
//
// Copyright (C) 2003-2007 S3 Graphics, Inc. All rights reserved. 
// 
// This is UNPUBLISHED PROPRIETARY SOURCE CODE of S3 Graphics, Inc.; 
// the contents of this file may not be disclosed to third parties, copied or 
// duplicated in any form, in whole or in part, without the prior written 
// permission of S3 Graphics, Inc. 
// 
// RESTRICTED RIGHTS LEGEND: 
// Use, duplication or disclosure by the Government is subject to restrictions 
// as set forth in subdivision (c)(1)(ii) of the Rights in Technical Data 
// and Computer Software clause at DFARS 252.227-7013, and/or in similar or 
// successor clauses in the FAR, DOD or NASA FAR Supplement. Unpublished - 
// rights reserved under the Copyright Laws of the United States. 
//
//  File Description:
//      This file contains data structures related to the S3GPPI
//

// 
//*****************************************************************************
#ifndef S3DXVA_Encrypt_H
#define S3DXVA_Encrypt_H
#include <windows.h>

#define S3_CRYPTO_FUNCTION                  0x3100
#define S3_BUSENCRYPTION_FUNCTION           0x3110
#define S3_OVERLAYPROTECTION_FUNCTION       0x3120

#define S3_CRYPTO_SUCCESS                   1
#define S3_CRYPTO_FAILURE                   0
#define S3_CRYPTO_NOT_IMPLEMENTED           0xFFFFFFFF // Old version driver
#define S3_CRYPTO_TOO_LARGE_KEYSIZE         0x80000000 // 

#define S3_VIDEOPROTECTION_SUCCESS          1
#define S3_VIDEOPROTECTION_FAILURE          0

#pragma pack(push, 4)
typedef struct _S3CryptoInput
{
    DWORD   dwISVId; // FourCC encode
    DWORD   dwKeySize;
}S3CryptoInput, *LPS3CryptoInput;
#pragma pack(pop)

#pragma pack(push, 8)

typedef enum _KEY_SIZE
{
    KEY_SIZE_32BIT,
    KEY_SIZE_64BIT,
    KEY_SIZE_128BIT,
    KEY_SIZE_256BIT,
    KEY_SIZE_512BIT,
    KEY_SIZE_1024BIT,
    KEY_SIZE_2048BIT,
}KEY_SIZE;

typedef enum
{
  CURR_KEY_SET,
  CURR_KEY_INVALID,
  NO_ENCRYPTION_NEEDED,
  CURR_DISPLAY_OVERLAY_ENABLE,
  CURR_DISPLAY_OVERLAY_UPDATE,
  CURR_DISPLAY_OVERLAY_FLIP,
  CURR_DISPLAY_OVERLAY_DISABLE,
}S3ENCRYPTION_VALIDATION;

typedef enum
{
  METHOD_UNKNOW          = 0x00, 
  METHOD_DXVA_1          = 0x01,
  METHOD_NONDXVA_1       = 0x02,
  METHOD_DISPLAY_OVERLAY = 0x04,
  METHOD_4               = 0x08,   //reserved
}S3ENCRYPTION_METHOD;

typedef union _S3G_OVERLAYFLAGS
{
   struct
   {
       WORD          DstColorKey     : 1; // 0x00000001
       WORD          SrcRectChanged  : 1; // 0x00000002
       WORD          DstRectChanged  : 1; // 0x00000004
       WORD          Reserved        : 13; 
   }Flags;
   WORD Value;
} S3G_OVERLAYFLAGS;


typedef struct _S3DXVA_Encrypt
{
   DWORD                    dwDecoderID;
   DWORD                    dwAcceleratorID;
   S3ENCRYPTION_VALIDATION  dwValidation;
   S3ENCRYPTION_METHOD      dwMethod; 
    union 
    {
        // METHOD_DXVA_1 and METHOD_NONDXVA_1
        struct
        {
           DWORD dwKey;
           DWORD dwNewKey;
           DWORD dwReserved[4];
        }Encrypt;
        struct
        {
           BYTE  Key[512];           
           DWORD dwReserved[4];
        }EnhancedEncrypt;
        struct
        {
           BYTE  ContentKey[16];           
           BYTE  Counter[16];
        }AESEncrypt;
        // METHOD_DISPLAY_OVERLAY
        struct
        {
            S3G_OVERLAYFLAGS  OverlayFlags;
            WORD              CurrBuffIndex;
            WORD              SrcRectTop;
            WORD              SrcRectLeft;
            WORD              SrcRectBottom;
            WORD              SrcRectRight;
            WORD              DstRectTop;
            WORD              DstRectLeft;
            WORD              DstRectBottom;
            WORD              DstRectRight;
            DWORD             DstColorKey;
        }Overlay;
        struct
        { 
            WORD        TargetBuffIndex;
            WORD        CurrBuffIndex;            
        }Flip;
    };
} S3DXVA_Encrypt, *LPS3DXVA_Encrypt;

#pragma pack(pop)


#ifdef __cplusplus
extern "C" {
#endif

VOID S3EncryptData(DWORD *pDataSrc,         // [in] Data to be encrypted
                   DWORD *pDatDst,          // [out] Encryped Data result
                   DWORD dwKey,             // [in] Key value
                   DWORD dwSize);           // [in] Data size

VOID S3EncryptKey(BYTE *pSessionKey,        // [in] Generated by driver
                  BYTE *pCurrContentKey,    // [in] Generated by ISV 
                  BYTE *pNewContentKey,     // [in] Generated by ISV
                  BYTE *pContentKeyOut,     // [out] Encrypted key, array size must be 512 bytes
                  KEY_SIZE KeySize);        // [in] Key size.

VOID S3EnhancedEncryptData(BYTE *pDataSrc,      // [in] Data to be encrypted
                           BYTE *pDataDst,      // [out] Encryped Data result
                           BYTE *pContentKey,   // [in] Key value.
                           DWORD dwSize,        // [in] Data size.
                           KEY_SIZE KeySize);   // [in] Key size.

int S3VideoExtEscape(DWORD nFunction, 
                     int nInBufSize, LPCSTR pInBuf,
                     int nOutBufSize, LPSTR pOutBuf );


#ifdef __cplusplus
}
#endif

#endif //#ifndef S3DXVA_Encrypt_H