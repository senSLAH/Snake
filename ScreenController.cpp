#include <iostream>
#include "sstream"
#include "ScreenController.h"
#include "Board.h"

ScreenController::ScreenController(GameMode mode)
:Menu(mode)
{
    start_time = 0;
}

void ScreenController::draw_menu(sf::RenderWindow &win)
{
    txt_vec.clear();
    if (current_state != RUNNING)
        win.draw(sprite_logo);

    if (current_state == RUNNING)
    {
        std::stringstream string_num;
        string_num << score << std::endl;

        txt_score_number.setString(string_num.str());
        win.draw(txt_score);
        win.draw(txt_score_number);
        draw_gameplay(win);
    }
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

void ScreenController::draw_gameplay(sf::RenderWindow &win)
{
    update();
    draw_snake(win);
    interval = (clock() - start_time);
    if(interval > 400000)
    {
        add_food();
        start_time = clock();
    }
    draw_food(win);
}

void ScreenController::handleEvent(sf::Event &event)
{
    if(event.type == sf::Event::MouseButtonPressed)
    {
//        std::cout << event.mouseButton.x;
//        std::cout << "\n";
//        std::cout << event.mouseButton.y;
//        std::cout << "\n";
//        std::cout << "\n";

        short temp = position_y(event.mouseButton.y);
        int y = event.mouseButton.y;
        int x = event.mouseButton.x;

        if (x < 105 && y < 43 )
            current_state = last_state;
        else
            set_state(temp);
    }
    if(event.type == sf::Event::KeyPressed && current_state == RUNNING)
    {
        short k = event.key.code;
        set_pressed_button(k);
    }
}

//short ScreenController::position_x(int x)
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
short ScreenController::position_y(int y)
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


