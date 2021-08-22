#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef void*(*Create_TList)(void);
int main()
{
    HMODULE hDll;
    hDll=LoadLibrary("DLL.dll");
    if(!hDll)
    {
     printf("ERROR: Dll can't connect\n");
		return GetLastError();
    };
    Create_TList Tree=(Create_TList)GetProcAddress(hDll,"tree");
    void* list = Tree();
   if (!list)
    {
		printf("ERROR: List can't create\n");
		return GetLastError();
	};
  return 0;
};

