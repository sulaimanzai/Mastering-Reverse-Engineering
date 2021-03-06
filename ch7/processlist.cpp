// processlist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "tlhelp32.h"

int main()
{
	HANDLE hSnapshot;
	PROCESSENTRY32 pe32;

	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	pe32.dwSize = sizeof(PROCESSENTRY32);

	if (Process32First(hSnapshot, &pe32))
	{
		printf("\nexecutable [pid]\n");
		do
		{
			printf("%ls [%d]\n", pe32.szExeFile, pe32.th32ProcessID);
		} while (Process32Next(hSnapshot, &pe32));
		CloseHandle(hSnapshot);
	}
    return 0;
}

