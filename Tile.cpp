#include "Tile.h"
#include <math.h>

Tile::Tile()
{
    color = BLACK;
    value = 0;
    length = 0;
}

Tile::~Tile(){

}

Tile& Tile::operator+=(const Tile& other){
    value += other.value;
    if(value <= 0)
    {
        color = BLACK;
        value = 0;
        length = 0;
    }
    else
    {
        length = ceil(log10(value+1));

        switch(value)
        {
        case 2:
            color = MAGENTA;
            break;
        case 4:
            color = LIGHTMAGENTA;
            break;
        case 8:
            color = BLUE;
            break;
        case 16:
            color = LIGHTBLUE;
            break;
        case 32:
            color = CYAN;
            break;
        case 64:
            color = LIGHTGRAY;
            break;
        case 128:
            color = GREEN;
            break;
        case 256:
            color = DARKGRAY;
            break;
        case 512:
            color = RED;
            break;
        case 1024:
            color = LIGHTRED;
            break;
        case 2048:
            color = BROWN;
            break;
         case 4096:
            color = MAGENTA;
            break;
        case 8192:
            color = LIGHTMAGENTA;
            break;

        }
    }


    return *this;
}

void Tile::setAll(int value)
{
    if(value <= 0)
    {
        this->color = BLACK;
        this->value = 0;
        this->length = 0;
    }
    else
    {
        this->value = value;

        this->length = ceil(log10(value+1));

        switch(this->value)
        {
        case 2:
            this->color = MAGENTA;
            break;
        case 4:
            this->color = LIGHTMAGENTA;
            break;
        case 8:
            this->color = BLUE;
            break;
        case 16:
            this->color = LIGHTBLUE;
            break;
        case 32:
            this->color = CYAN;
            break;
        case 64:
            this->color = LIGHTGRAY;
            break;
        case 128:
            this->color = GREEN;
            break;
        case 256:
            this->color = DARKGRAY;
            break;
        case 512:
            this->color = RED;
            break;
        case 1024:
            this->color = LIGHTRED;
            break;
        case 2048:
            this->color = BROWN;
            break;
         case 4096:
            this->color = MAGENTA;
            break;
        case 8192:
            this->color = LIGHTMAGENTA;
            break;
        }
    }
}

void Tile::setColor(COLORS color){ this->color = color;}
void Tile::setValue(int value){ this->value = value;}
void Tile::setLength(int length){ this->length = length;}
Tile::COLORS Tile::getColor(){ return this->color; }
int Tile::getValue(){ return this->value; }
int Tile::getLength(){ return this->length; }

