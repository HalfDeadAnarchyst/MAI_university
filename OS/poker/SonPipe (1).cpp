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
    int z;
    poker pl1;
    int dice;
	HANDLE Son;
	LPCSTR AdresNameFile = "\\\\.\\pipe\\MyPipe";
	Sleep (12);
	Son = CreateFile(AdresNameFile, GENERIC_READ | GENERIC_WRITE , 0, NULL, OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL, NULL);
	if (Son == INVALID_HANDLE_VALUE)
	{
		printf("I'm Son.\n Daddy doesn't createeeeeeeeee");
		getchar();
		printf("NNNNNNOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
		return GetLastError();
	};
//	bool connect = ConnectNamedPipe(Son, &l);
	/*if (connect == false)
	{

		int i = GetLastError();
		if (i == 997 || i == 536)
		{
		}
		else {
			return GetLastError();
		};
	};*/
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
int a=(combination(pl1.dices)); 
DWORD in;
	if (!ReadFile(Son, &z,sizeof(int), &in , NULL))
	/*{
		printf("I CAN'T READ FILE");
		return GetLastError();
	};*/
	/*Son = CreateFile(AdresNameFile, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, TRUNCATE_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (Son == INVALID_HANDLE_VALUE)
	{
		printf("Son doesn't open file");
		getchar();
		printf("NNNNNNOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
		ExitProcess(1);
		return 1;

	};*/
printf("%d\n", &z);
if(z>a)
{printf("YOU LOOSE!\n");}
if(z<a)
{printf("YOU WIN!\n");}
if(a==z)
{printf("IT'S A DRAW!\n");}
DWORD wr;
WriteFile(Son, &a,sizeof(int), &wr , NULL);  
Sleep(100);
getch();
	ExitProcess(1);
	return 0;
}
LPCVOID Error(int i)
{
	LPCVOID Errors;
	if (i == 1)
	{
		Errors = TEXT("you bad write \n");
		return Errors;
	};
	return 0;
};





