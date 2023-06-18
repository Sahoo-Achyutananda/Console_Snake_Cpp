#ifndef LOADING_SCREEN_H
    #define LOADING_SCREEN_H

#include<iostream>
#include<windows.h>

using namespace std;

void load_screen()
{
	system("cls");
	//system("color 9F");
	
	char a = 176, b = 219;
	cout<<"\n\n\n\n\n\t\t\t\t   THE CLASSIC SNAKE GAME";
	cout<<"\n\t\t\t\t\tFrom Sahoo.io";
	cout<<"\n\n\n\t\t\t\t   Loading...\n";
	cout<<endl;
	cout<<"\t\t\t\t\t";
	
	for(int i = 0;i<26;i++)
        cout<<a;

	cout<<"\r";
	cout<<"\t\t\t\t\t";
	for(int i = 0; i < 26 ; i++)
	{
		cout<<b;
		Sleep(100);
	}
	
}

#endif
