#include<stdio.h>
#include<windows.h>
void error()
{
	MessageBox(NULL, "KeyFile is not valid Sorry", "Key file ReverseMe", MB_OK);
}
int main()
{
	int ebx = 0;
	int esi = 0;
	BOOL flag = FALSE;
	LPCTSTR FileName = "C:\\Users\\bangiao\\Desktop\\demo\\demo\\first\\Keyfile.dat";
	HANDLE hFile = CreateFile(FileName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	//CreateFile(FileName,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
	DWORD FileSize = GetFileSize(hFile, NULL);
	char *buffer = new char[FileSize + 1];
	if (!hFile)
	{
		MessageBox(NULL, "Evaluation....", "Key File ReverseMe", MB_OK);
	}
	DWORD ReadSize;
	flag = ReadFile(hFile, buffer, 70, &ReadSize, NULL);
	buffer[FileSize] = 0;

	if (!flag)
	{
		error();
		return 0;
	}
	else
	{
		buffer[FileSize] = 0;
		if (ReadSize < 0x10)
		{
			error();
			return 0;
		}
		else
		{
			while (*buffer)
			{
				if (*buffer == 0x47)
				{
					esi++;
				}
				else
				{
					ebx++;
				}
				buffer++;
			}
			if (*buffer == 0)
			{
				if (esi >= 8)
				{
					MessageBox(NULL, "you really did it ", "KeyFile ReveserMe", MB_OK);
				}
			}
			else
			{
				error();
				return 0;
			}
		}
	}
	buffer -= ReadSize;
	delete[]buffer;
	CloseHandle(hFile);
}