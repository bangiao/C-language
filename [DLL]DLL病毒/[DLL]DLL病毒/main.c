#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

void message()
{
	MessageBox(NULL, TEXT("DLL�ѽ���Ŀ����̡�"), TEXT("��Ϣ"), MB_ICONINFORMATION);
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
		MessageBox(NULL, TEXT("DLL�Ѵ�Ŀ�����ж�ء�"), TEXT("��Ϣ"), MB_ICONINFORMATION);
	}
	break;
	}
	return TRUE;
}
