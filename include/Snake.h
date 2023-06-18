#ifndef SNAKE_H
    #define SNAKE_H
#include<cstdlib>
#include<windows.h>
#include<vector>

/*
Snake attributes:
    1.position of the head
    2.lenghth of the snake
    3.speed of the head
    4.direction of the head
*/

class Snake{
    private:
        COORD pos;
        int len;
        int vel;
        char direction;
        std::vector<COORD> body;
    public:
        void setPos(int x, int y){
            this->pos.X = x;
            this->pos.Y = y;
        }
        void setLen(int l){
            this->len = l;
        }
        void setDir(char d){
            this->direction = d;
        }
        void pushPos(COORD p){
            this->body.push_back(p);
        }
        Snake(COORD pos, int vel); // constructor
        void change_dir(char direction);
        void move_snake(int delay);
        COORD get_pos();
        bool eaten(COORD food_pos);
        void grow();
        bool collided();
        bool bitten();
        std::vector<COORD> get_body();
        void clear_body(){
            this->body.clear();
        }
        ~Snake(){}
};

#endif