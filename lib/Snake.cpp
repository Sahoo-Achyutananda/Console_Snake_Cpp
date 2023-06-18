#include "..\include\Snake.h"
#include<windows.h>

#define WIDTH 50
#define HEIGHT 25

Snake::Snake(COORD pos, int vel)
{
    this->pos = pos;
    this->vel = vel;
    len = 1;
    direction = 'n';

    body.push_back(pos);
}

void Snake::change_dir(char direction)
{
    this->direction = direction;
}

std::vector<COORD> Snake::get_body()
{
    return body;
}

void Snake::move_snake(int delay)
{
    switch (direction)
    {
    case 'u':
        pos.Y = pos.Y - vel;
        break;
    case 'd':
        pos.Y = pos.Y + vel;
        break;
    case 'l':
        pos.X = pos.X - vel;
        break;
    case 'r':
        pos.X = pos.X + vel;
        break;
    }
    body.push_back(pos);

    if (body.size() > len)
        body.erase(body.begin()); 
    // erase() is used to remove elements from a container from the specified position or range.
    
    Sleep(delay);
}

COORD Snake::get_pos()
{
    return this->pos;
}

bool Snake::eaten(COORD food_pos)
{
    if (food_pos.X == pos.X && food_pos.Y == pos.Y)
        return true;
    else
        return false;
}

void Snake::grow()
{
    len++;
}

bool Snake::collided()
{
    if (pos.X < 1 || pos.X > WIDTH-2 || pos.Y < 1 || pos.Y > HEIGHT-2)
        return true;
    return false;
}

bool Snake::bitten(){
    COORD head_pos = this->get_pos();
    std::vector<COORD> snake_body = this->get_body();

    for(int k = 0; k <snake_body.size() -1; k++){
        if(head_pos.Y == snake_body[k].Y && head_pos.X == snake_body[k].X){
            return true;
        }
    }
    
    return false;
}