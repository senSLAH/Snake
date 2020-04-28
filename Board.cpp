#include <iostream>
#include "Board.h"

Board::Board(GameMode mode) : Menu(mode)
{
}

void Board::draw(sf::RenderWindow &win)
{
    txt_vec.clear();
    if (current_state != RUNNING)
        win.draw(sprite_logo);

    if (current_state != START_SCREEN)
        win.draw(txt_back_button);

    if (current_state == START_SCREEN)
    {
        start_screen();

    }
    if (current_state == SETTINGS)
    {
        settings();
    }
    if (current_state == HOW_TO_PLAY)
    {
        how_to_play();
        win.draw(sprite_keyboard_arrows);
    }
    for (const auto & i : txt_vec)
    {
        win.draw(i);
    }
}

void Board::handleEvent(sf::Event &event)
{
    if(event.type == sf::Event::MouseButtonPressed)
    {
        std::cout << event.mouseButton.x;
        std::cout << "\n";
        std::cout << event.mouseButton.y;
        std::cout << "\n";
        std::cout << "\n";

        short temp = position_y(event.mouseButton.y);
        short y = event.mouseButton.y;
        short x = event.mouseButton.x;

        if (x < 105 && y < 43 )
            current_state = last_state;
        else
            set_state(temp);
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
        if (y < 20 && y > 0)
            return i;
        else
        {
            y -= 50;
        }
    }
    return 2;
}
