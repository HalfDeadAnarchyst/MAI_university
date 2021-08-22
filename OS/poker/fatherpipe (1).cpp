#define _CRT_SECURE_NO_WARNINGS
#include <time.h> 
#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <tchar.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "Source.cpp"

typedef struct poker{
  int dices[5];      
};
int _tmain(int argc, _TCHAR* argv[])
{
   srand(time(NULL));
    int i;
    int number;
    poker pl1;
    int dice;
    printf("Waiting for next player\n");
	HANDLE Daddy;
	LPCSTR AdresNameFile = ("\\\\.\\pipe\\MyPipe");
	//LPWSTR AdresNameFile =TEXT ("C:\\Users\\Arkadii\\Desktop\\OS\\Data.txt");
	Daddy = CreateNamedPipe(AdresNameFile, PIPE_ACCESS_DUPLEX,
		PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
		1, 128, 128,
		PIPE_UNLIMITED_INSTANCES,
		NULL);
	if (Daddy == INVALID_HANDLE_VALUE)
	{
		printf("Daddy's PIPE doesn't createeeeeeeeee");
		printf("  NNNNNNOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
		system("pause");
		return GetLastError();
	}
	PROCESS_INFORMATION ProcessInfo; //This is what we get as an [out] parameter
	ZeroMemory(&ProcessInfo, sizeof(PROCESS_INFORMATION));
	STARTUPINFO StartupInfo; //This is an [in] parameter
	ZeroMemory(&StartupInfo, sizeof(StartupInfo));
	StartupInfo.cb = sizeof(STARTUPINFO); //Only compulsory field
	bool process = CreateProcess("C:\\Users\\L2(client).exe",
		NULL,
		NULL, NULL, true,
		CREATE_NEW_CONSOLE,// CREATE_NEW_CONSOLE|CREATE_SUSPENDED
		NULL, NULL,
		&StartupInfo,
		&ProcessInfo);
	WaitForSingleObject(ProcessInfo.hProcess, 5);
	bool connect = ConnectNamedPipe(Daddy, NULL);
	if(connect == true)
	{printf("We just find someone!\n");}
	if (connect == false)
	{
		int i = GetLastError();
		if (i == 997 || i == 536)
		{
		}
		else {
			return GetLastError();
		};
	};
	printf("Find your destiny!\n");
	printf("Here we go!\n");
	for(i=0;i<5;i++){
    pl1.dices[i]=rand() %6 +1;
    display(pl1.dices[i]);}
    res (combination(pl1.dices));
    printf("Do you want change some of them? 1/0 ");
    int ch;
    scanf("%d", &ch);
            // while (ch!=1 ||ch!=0){
   // scanf("%d", &ch);}
    if(ch==1)
    {printf("Which ones don't suit you? Enter number of items for change\n");
    scanf("%d", &number);
    
    for(int i=0;i<number;i++)
    {printf("Enter number: ");
            scanf("%d", &dice);
            dice--;
    pl1.dices[dice]=rand() %6 +1;
    }
    for(i=0;i<5;i++){
    display(pl1.dices[i]);}
    res (combination(pl1.dices));
}  
DWORD wr;
int a=(combination(pl1.dices));
WriteFile(Daddy, &a,sizeof(int), &wr , NULL);  
Sleep(100);
DWORD r; int z;
ReadFile(Daddy, &z,sizeof(int), &r , NULL);
if(z>(combination(pl1.dices)))
{printf("YOU LOOSE!\n");}
if(z<(combination(pl1.dices)))
{printf("YOU WIN!\n");}
if(z==(combination(pl1.dices)))
{printf("IT'S A DRAW!\n");}
getch();
/*              DWORD written;
	if (!WriteFile(Daddy, &z, sizeof(node), &written, NULL))
	{
		printf("Error! Can not write in file\n");
		system("pause");
		return GetLastError();
	}

		Sleep(1000);
	ReadFile(Daddy, &z,sizeof(node), &written , NULL);
	CloseHandle(Daddy);
	system("pause");*/
	return 0;
}

