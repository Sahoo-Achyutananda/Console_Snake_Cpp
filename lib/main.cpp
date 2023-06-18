// Made by Achyutananda Sahoo
// 01-06-2023

#include<iostream>
#include<ctime>
#include<conio.h>
#include"..\include\ending_screen.h"
#include"..\include\loading_screen.h"
#include"..\lib\Food.cpp"
#include "..\lib\Snake.cpp"

using namespace std;
#define WIDTH 50
#define HEIGHT 25

// creating the snake object and assigning it to the centre of the board
Snake snake({WIDTH/2,HEIGHT/2}, 1);
vector<COORD> snake_body = snake.get_body();
// creating the food object
Food food;

int score;
int delay = 100;

void board()
{
    COORD snake_pos = snake.get_pos();
    COORD food_pos = food.get_pos();

    snake_body = snake.get_body();

    cout << "SCORE : " << score << "\n\n";

    for(int i = 0; i < HEIGHT; i++)
    {
        cout << "\t\t#";
        for(int j = 0; j < WIDTH - 2; j++)
        {   
            // printing the board boundry
            if(i == 0 || i == HEIGHT-1) cout << '#';
            // printing the snake head
            else if(i == snake_pos.Y && j+1 == snake_pos.X) cout << '0';
            // printing the food
            else if(i == food_pos.Y && j+1 == food_pos.X) cout << '@';
            // printing the body of the snake.
            else
            {
                bool isBodyPart = false;
                for(int k = 0; k < snake_body.size()-1; k++)
                {
                    if(i == snake_body[k].Y && j+1 == snake_body[k].X)
                    {
                        cout << '+';
                        isBodyPart = true;
                        break;
                    }
                }

                if(!isBodyPart) cout << ' ';
            }
        }
        cout << "#\n";
    }
}

void startGame(){
    system("cls");
    score = 0;    
    bool game_over = false;
    srand(time(NULL));
    food.gen_food();  
    while(!game_over){

        board();
        if(kbhit()){
            switch (getch())
            {
                case '8':
                    snake.change_dir('u');
                    break;
                case '2':
                    snake.change_dir('d');
                    break;
                case '4':
                    snake.change_dir('l');
                    break;
                case '6':
                    snake.change_dir('r');
                    break;
            }
        }

        if(snake.collided() || snake.bitten()){
            game_over = true;
            break;
        }

        if(snake.eaten(food.get_pos())){ // if the snake has eaten the food
            food.gen_food();                    // -> generate new food position
            snake.grow();                       // -> grow the snake
            score+=10;                          // -> increment the score by 10
        }

        snake.move_snake(delay);    // move the snake.

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0}); // moves the cursor to the start of the console (0,0)

    }
}

int main(){
    load_screen();
    while(1){
        startGame();
        end_screen(score);
        if(getch() == '1'){
            snake.setPos(WIDTH/2,HEIGHT/2);
            snake.clear_body();
            snake.setLen(1);
            //snake.setDir('n');
            snake.pushPos({WIDTH/2,HEIGHT/2});
            load_screen();
        }
        else{
            break;
        }
    }
    
}