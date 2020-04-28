#include <iostream>
#include "Board.h"

Board::Board(GameMode mode) : Menu(mode)
{
}

void Board::draw(sf::RenderWindow &win) const
{
    if (state != RUNNING)
        win.draw(sprite_logo);

    if (state == START_SCREEN)
    {
        for (const auto & i : txt_vec)
        {
            win.draw(i);
        }
    }
    if (state == SETTINGS)
    {

    }
    if (state == HOW_TO_PLAY)
    {

    }

}

void Board::handleEvent(sf::Event &event)
{
    if(event.type == sf::Event::MouseButtonPressed)
    {
        std::cout<< event.mouseButton.x;
        std::cout<< "\n";
        std::cout<< event.mouseButton.y;
        std::cout<< "\n";
        std::cout<< "\n";
        position_y(event.mouseButton.y);
    }

}

//short Board::position_x(int x)
//{
//    x -= 270;
//    for (int i = 0; i < 5; ++i)
//    {
//        if(x <= 40)
//            return i;
//        else
//        {
//            x -= 50;
//        }
//    }
//}
//
short Board::position_y(int y)
{
    y -= 310;
    for (int i = 0; i < 3; ++i)
    {
        if(y > 0 && y <= 27)
        {
            std::cout << "Pos_y: " << i;
            std::cout<< "\n";

        }
        else
        {
            y -= 27;
        }
    }
}
