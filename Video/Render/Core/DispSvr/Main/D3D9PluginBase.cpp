#include "stdafx.h"
#include "DispSvr.h"

#include <multimon.h>

#include "ResourceManager.h"
#include "D3D9PluginBase.h"

using namespace DispSvr;

CD3D9PluginBase::CD3D9PluginBase() : m_GUID(GUID_NULL), m_hwnd(0), m_pDevice(0), m_cRef(0), m_pDeviceEx(0)
{
	ZeroMemory(&m_rcMonitor, sizeof(m_rcMonitor));
	m_eWindowState = RESOURCE_WINDOW_STATE_WINDOWED;
}

CD3D9PluginBase::~CD3D9PluginBase()
{

}

STDMETHODIMP CD3D9PluginBase::GetResourceId(GUID *pGUID)
{
	CHECK_POINTER(pGUID);
	*pGUID = m_GUID;
	return S_OK;
}

STDMETHODIMP CD3D9PluginBase::ProcessMessage(RESOURCE_MESSAGE_TYPE msg, LPVOID ulParam)
{
	HRESULT hr = E_NOTIMPL;

	switch (msg)
	{
	case RESOURCE_MESSAGE_SETDEVICE:
		hr = _SetDevice(reinterpret_cast<IUnknown *> (ulParam));
		break;
	case RESOURCE_MESSAGE_RELEASEDEVICE:
		hr = _ReleaseDevice();
		break;
	case RESOURCE_MESSAGE_SETWINDOWHANDLE:
		hr = _SetWindow(reinterpret_cast<HWND> (ulParam));
		break;

	case RESOURCE_MESSAGE_SETWINDOWSTATE:
		if (!ulParam)
			return E_INVALIDARG;
		m_eWindowState = *static_cast<RESOURCE_WINDOW_STATE *> (ulParam);
		hr = S_OK;
		break;
	}
	return hr;
}

STDMETHODIMP CD3D9PluginBase::QueryInterface(REFIID riid, void **ppv)
{
	HRESULT hr = E_NOINTERFACE;

	if (riid == __uuidof(IDispSvrPlugin))
	{
		hr = GetInterface((IDispSvrPlugin *)this, ppv);
	}
	else if (riid == IID_IUnknown)
	{
		hr = GetInterface((IUnknown *)this, ppv);
	}
	return hr;
}

STDMETHODIMP_(ULONG) CD3D9PluginBase::AddRef()
{
	LONG lRef = 0;
	lRef = InterlockedIncrement(&m_cRef);
	ASSERT(lRef > 0);
	return lRef;
}

STDMETHODIMP_(ULONG) CD3D9PluginBase::Release()
{
	LONG lRef = InterlockedDecrement(&m_cRef);
	ASSERT(lRef >= 0);
	if (lRef == 0)
		delete this;
	return lRef;
}

STDMETHODIMP CD3D9PluginBase::_SetDevice(IUnknown *pDevice)
{
	HRESULT hr;
	IDirect3DDevice9 *pDevice9 = 0;

	CHECK_POINTER(pDevice);
	hr = pDevice->QueryInterface(IID_IDirect3DDevice9, (LPVOID *)&pDevice9);
	if (FAILED(hr))
		return hr;

	if (m_pDevice != 0)
	{
		pDevice9->Release();
		if (pDevice9 != m_pDevice)
		{
			ASSERT(0 && "CD3D9PluginBase: Setting device without releasing the old device!!");
			return E_FAIL;
		}
		return S_FALSE;
	}

	m_pDevice = pDevice9;
	hr = m_pDevice->QueryInterface(__uuidof(IDirect3DDevice9Ex), (void**)&m_pDeviceEx);
	if( hr != S_OK ) m_pDeviceEx = NULL;

	D3DDEVICE_CREATION_PARAMETERS param;
	hr = m_pDevice->GetCreationParameters(&param);
	if (FAILED(hr))
		return hr;

	hr = _SetWindow(param.hFocusWindow);
	return hr;
}

STDMETHODIMP CD3D9PluginBase::_ReleaseDevice()
{
	SAFE_RELEASE(m_pDevice);
	SAFE_RELEASE(m_pDeviceEx);
	m_hwnd = 0;
	return S_OK;
}

STDMETHODIMP CD3D9PluginBase::_SetWindow(HWND hwnd)
{
	if (!IsWindow(hwnd))
		return E_INVALIDARG;

	if (hwnd == m_hwnd)
		return S_FALSE;

	HMONITOR hMonitor = MonitorFromWindow(hwnd, (hwnd) ? MONITOR_DEFAULTTONEAREST : MONITOR_DEFAULTTOPRIMARY);
	MONITORINFOEX MonInfo;
	ZeroMemory(&MonInfo, sizeof(MONITORINFOEX));
	MonInfo.cbSize = sizeof(MONITORINFOEX);
	if (GetMonitorInfo(hMonitor, &MonInfo) == TRUE)
	{
		m_rcMonitor = MonInfo.rcMonitor;
	}
	else if (m_pDevice)
	{
		// We will have trouble to get the {x,y} of 2nd monitor.
		ASSERT(0);
		D3DDISPLAYMODE D3DDisplayMode;
		HRESULT hr = m_pDevice->GetDisplayMode(0, &D3DDisplayMode); ASSERT(SUCCEEDED(hr));
		m_rcMonitor.top = 0;
		m_rcMonitor.left = 0;
		m_rcMonitor.right = D3DDisplayMode.Width;
		m_rcMonitor.bottom = D3DDisplayMode.Height;
	}

	m_hwnd = hwnd;
	return S_OK;
}
