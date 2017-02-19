#ifndef _UNIQUE_WINDOW_H_
#define _UNIQUE_WINDOW_H_
#include "ImportantLib.h"

class UNIQUE_Windows
{
public:
	UNIQUE_Windows();
	virtual ~UNIQUE_Windows();

	HRESULT    Create(LPCWSTR name, UINT width, UINT height, bool isFullScreen = false);
	HWND	   GetHWND();
	LPCWSTR	   GetName();
	UINT	   GetWidth();
	UINT	   GetHeight();
	HINSTANCE  GetHinstance();
	bool	   IsFullScreen();

	void Run();

protected:

private:
	HWND m_hwnd;
	LPCWSTR m_name;
	HINSTANCE m_hinstance;
	UINT m_width;
	UINT m_height;
	bool m_isFullScreen;

};

#endif






