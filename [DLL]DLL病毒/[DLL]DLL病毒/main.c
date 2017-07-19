#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

void message()
{
	MessageBox(NULL, TEXT("DLL已进入目标进程。"), TEXT("信息"), MB_ICONINFORMATION);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
	{
		message();
	}
	break;
	case DLL_PROCESS_DETACH:
	{
		MessageBox(NULL, TEXT("DLL已从目标进程卸载。"), TEXT("信息"), MB_ICONINFORMATION);
	}
	break;
	}
	return TRUE;
}
