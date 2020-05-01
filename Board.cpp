#include <iostream>
#include "Board.h"

Board::Board()
{
    if (!apple_texture.loadFromFile("../IMG/green_apple.png"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    appple.setTexture(apple_texture);
    time = 0;
    food_count = 0;
}

void Board::add_food()
{
    if (food_count > 2)
    {
        remove_food();
        add_food();
    }
    else
    {
        f.food_position_x = rand() % 785 + 1;
        f.food_position_y = rand() % 585 + 1;
        f.type = APPLE;
        food.push_back(f);
        ++food_count;
    }
}

void Board::remove_food(int position)
{
    --food_count;
    food.erase(food.begin() + position);
}

void Board::draw_food(sf::RenderWindow &win)
{
    for (int i = 0; i < food_count; ++i)
    {
        appple.setPosition(food[i].food_position_x,food[i].food_position_y);
        win.draw(appple);
    }
    //std::cout << get_position_x(1);
}

int Board::get_position_x(int i)
{
    return food[i].food_position_x;
}
int Board::get_position_y(int i)
{
    return food[i].food_position_y;
}



