#ifndef _DISPSVR_NVAPI_VIDEO_PRESENTER_
#define _DISPSVR_NVAPI_VIDEO_PRESENTER_

#include "D3D9VideoPresenterBase.h"
#include "Imports/ThirdParty/nVIDIA/NvAPI/nvapi.h"
#include "DriverExtensionHelper.h"

using namespace DispSvr;

class CNvAPIDeviceExtensionAdapter : public IDriverExtensionAdapter
{
public:
	virtual ~CNvAPIDeviceExtensionAdapter();
	static HRESULT GetAdapter(IDirect3DDevice9 *pDevice9, IDriverExtensionAdapter **ppDeviceCapAdapter);

	//	IDriverExtensionAdapter
	virtual HRESULT QueryPresenterCaps(DWORD VideoDecodeCaps, PresenterCaps* pCaps);

private:
	CNvAPIDeviceExtensionAdapter(IDirect3DDevice9 *pDevice);
	NVAPI_VIDEO_SRC_INFO m_NvMainVideo_Info;
	IDirect3DDevice9 *m_pDevice9;
};

class CNvAPIPresenter : public CD3D9VideoPresenterBase
{
public:
	#define MAX_QUEUE_SIZE (NV_CV_MIN_OVERLAY_SURFACE_NUMBER+2)

	CNvAPIPresenter();
	virtual ~CNvAPIPresenter();

	STDMETHOD(SetDisplayRect)(const RECT *rcDst, const RECT *rcSrc);
	STDMETHOD(BeginRender)();
	STDMETHOD(Present)(const PresentHints *pHints);
	STDMETHOD(Clear)();
	STDMETHOD(SetColorKey)(const DWORD dwColorKey);
	STDMETHOD(SetGamutMetadata)(const DWORD dwFormat, void *pGamutMetadata);

protected:
	STDMETHOD(_SetDevice)(IUnknown *pDevice);
	STDMETHOD(_ReleaseDevice)();
	STDMETHOD(_QueryCaps)(PresenterCaps* pCaps);
	virtual HRESULT CreateOverlay(D3DSURFACE_DESC *desc, NV_DX_CREATE_VIDEO_PARAMS *CVParams);
	void ReleaseOverlay();

	HRESULT InitNvAPI();
	HRESULT CreateNvAPI();
	HRESULT DestroyNvAPI();
	HRESULT PresentVideo(const NvSBox *pNvSrc, const NvSBox *pNvClip, const NvSBox *pNvDst);
	HRESULT PresentVideo60i(const NvSBox *pNvSrc, const NvSBox *pNvClip, const NvSBox *pNvDst);
	HRESULT ClearGamutMetadata();
	HRESULT UpdateDisplayProperty();

protected:

	bool m_bIsPrimaryDisplay;
	bool m_bIsInterlacedDisplay;
	bool m_bNvPresentBusy;
	bool m_bHalfResOnInterlaced;
	bool m_bGamutDataSent;
	bool m_bIsHDMIInfoSet;
	bool m_bIsHDMIColorSpaceChanged;
	DWORD m_dwFlipQueueHint;	// the queue hint for RGBoverlay
	DWORD m_dwMaxUseQueueSize;	// the max queue siz for optimized RGBoverlay
	DWORD m_dwQueueIdx;
	DWORD m_dwPVFlags;
	DWORD m_dwFlipTimes;
	DWORD m_dwLastPolarity;
	DWORD m_dwFrameProperty;
	RECT m_rcClip;
	PresentHints m_PresentHints;
	NvSBox m_NvSrc;
	NvSBox m_NvClip;
	NvSBox m_NvDst;

	NvU32  m_n32NV_DX_PRESENT_VIDEO_PARAMS_VER;	//Workarround : wait for Nvidia new Driver
	NVDX_ObjectHandle m_ObjHandle;
	NVDX_ObjectHandle m_hObj[MAX_QUEUE_SIZE];
	IDirect3DSurface9* m_pRT[MAX_QUEUE_SIZE];
	NV_HDMI_SUPPORT_INFO m_HDMIInfo;
	NV_GAMUT_METADATA m_MetaData;
	NvDisplayHandle m_hNvDisp;
	IDriverExtensionAdapter *m_pDeviceCap;
};

#endif
