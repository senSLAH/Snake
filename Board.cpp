#include <iostream>
#include "Board.h"

Board::Board()
{
    if (!apple_texture.loadFromFile("../IMG/green_apple.png"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    if (!mushroom_texture.loadFromFile("../IMG/mushroom.png"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    if (!TNT_texture.loadFromFile("../IMG/TNT.png"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }

    line[0] = sf::RectangleShape(sf::Vector2f(800, 5));
    line[1] = sf::RectangleShape(sf::Vector2f(5, 600));
    line[2] = sf::RectangleShape(sf::Vector2f(800, 5));
    line[3] = sf::RectangleShape(sf::Vector2f(5, 800));
    line[1].setPosition(795,0);
    line[2].setPosition(0,595);
    border_color = sf::Color::Green;

    appple.setTexture(apple_texture);
    mushroom.setTexture(mushroom_texture);
    tnt.setTexture(TNT_texture);
    time = 0;
    food_count = 0;
    start_time = 0;
    health = 3;
}

void Board::add_food()
{
    if (food_count > how_many_food())
    {
        remove_food();
        add_food();
    }
    else
    {
        f.food_position_x = rand() % 785 + 1;
        f.food_position_y = rand() % 585 + 1;

        if (Mode == NORMAL)
        {
            f.type = APPLE;
        }

        if (Mode == HERO)
        {
            if(rand() % 4 == 1)
                f.type = MUSHROOM;
            else
                f.type = APPLE;
        }

        if (Mode == GOD)
        {
            if(rand() % 2 == 1)
                f.type = MUSHROOM;
            else if(rand() % 2 == 1)
                f.type = TNT;
            else
                f.type = APPLE;
        }
        food.push_back(f);
        ++food_count;
    }
}

void Board::remove_food(int position)
{
    if (current_state != RUNNING)
    {
        food_count = 0;
        food.clear();
    }
    else
    {
        --food_count;
        food.erase(food.begin() + position);
    }
}

void Board::draw_food(sf::RenderWindow &win)
{
    for (int i = 0; i < food_count; ++i)
    {
        if (food[i].type == APPLE)
        {
            appple.setPosition(food[i].food_position_x, food[i].food_position_y);
            win.draw(appple);
        }

        if (food[i].type == MUSHROOM)
        {
            mushroom.setPosition(food[i].food_position_x, food[i].food_position_y);
            win.draw(mushroom);
        }

        if(food[i].type == TNT)
        {
            tnt.setPosition(food[i].food_position_x, food[i].food_position_y);
            win.draw(tnt);
        }
    }
}

void Board::set_state(GameState state)
{
    if(current_state != SETTINGS)
    {
        last_state = current_state;
        current_state = state;
    }
}

GameState Board::get_state() const
{
    return current_state;
}

int Board::how_many_food()
{
    if (Mode == NORMAL)
        return 2;
    if (Mode == HERO)
        return 6;
    if (Mode == GOD)
        return 10;
    return 0;
}



