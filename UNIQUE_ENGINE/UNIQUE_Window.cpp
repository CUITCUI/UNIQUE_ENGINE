#include "UNIQUE_Window.h"


UNIQUE_Windows::UNIQUE_Windows()
{
	m_width        = 1024;
	m_height	   = 768;
	m_hwnd		   = nullptr;
	m_name		   = nullptr;
	m_hinstance    = nullptr;
	m_isFullScreen = false;
}

UNIQUE_Windows::~UNIQUE_Windows() 
{}


HWND UNIQUE_Windows::GetHWND()
{
	return m_hwnd;
}

LPCWSTR UNIQUE_Windows::GetName()
{
	return m_name;
}

HINSTANCE UNIQUE_Windows::GetHinstance()
{
	return m_hinstance;
}

UINT UNIQUE_Windows::GetWidth()
{
	return m_width;
}

UINT UNIQUE_Windows::GetHeight()
{
	return m_height;
}

bool UNIQUE_Windows::IsFullScreen()
{
	return m_isFullScreen;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam);

HRESULT UNIQUE_Windows::Create(LPCWSTR name, UINT width, UINT height, bool isFullScreen /* = false */)
{
	HRESULT hr = S_OK;

	m_width        = width;
	m_height       = height;
	m_name		   = name;
	m_isFullScreen = isFullScreen;

	WNDCLASSEX wcex = { 0 };

	m_hinstance = GetModuleHandle(NULL);

	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.hInstance = m_hinstance;
	wcex.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wcex.hIconSm = wcex.hIcon;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = m_name;
	wcex.lpfnWndProc = WndProc;
	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL, L"error", L"Warning", MB_OK);
	}

	m_hwnd = CreateWindowEx(WS_EX_APPWINDOW, m_name, m_name,
		WS_OVERLAPPEDWINDOW,
		0, 0, m_width, m_height, NULL, NULL, m_hinstance, NULL);

	ShowWindow(m_hwnd, SW_SHOW);
	SetForegroundWindow(m_hwnd);
	SetFocus(m_hwnd);
	return hr;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
{
	switch (umessage)
	{
		
		case WM_DESTROY:		
		case WM_CLOSE:
			PostQuitMessage(0);
			return 0;
		default:
			break;
	}
	return DefWindowProc(hwnd, umessage, wparam, lparam);
}


void UNIQUE_Windows::Run()
{
	MSG msg;
	bool isClose = false;
	ZeroMemory(&msg, sizeof(MSG));
	
	
	while (!isClose)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if (msg.message == WM_QUIT)
		{
			isClose = true;
		}
		else
		{
			//render
		}

	}
}