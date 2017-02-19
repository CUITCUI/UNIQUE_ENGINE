#include "UNIQUE_Window.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	UNIQUE_Windows myWindows;

	myWindows.Create(L"UNIQUE_Engine", 1024, 768);
	myWindows.Run();
	return 0;
}





