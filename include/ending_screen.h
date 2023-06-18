#ifndef ENDING_SCREEN_H
    #define ENDING_SCREEN_H

#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<conio.h>

void end_screen(int score){
    system("cls");
    system("color cf");   // c - white and f - light red
	
	char a = 176, b = 219;
	std::cout<<"\n\n\n\n\n\t\t\t\t   THE CLASSIC SNAKE GAME";
	std::cout<<"\n\t\t\t\t\tFrom Sahoo.io";
	std::cout<<"\n\n\n\t\t\t\t\tGame Over !!\n\n";
    std::cout<<"\t\t\t\t\tYOUR SCORE : " << score << std::endl;
    std::cout << "\n\n\t\t\t\t   Press 1 -------- Retry "<< std::endl;
    std::cout << "\t\t\t\t   Press 2 -------- Exit  "<< std::endl;
    std::cout << "\n\n\n\n\n";
}

#endif