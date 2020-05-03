#include <iostream>
#include "sstream"
#include "ScreenController.h"
#include "Board.h"

ScreenController::ScreenController(GameMode mode)
:Menu(mode)
{
    start_time = 0;
    check_reset = true;
}

void ScreenController::draw_menu(sf::RenderWindow &win)
{
    txt_vec.clear();
    if (current_state != RUNNING)
        win.draw(sprite_logo);

    if (current_state == RUNNING || current_state == FINISHED)
    {
        if (score < 0)
        {
            current_state = FINISHED;
        }
        else
        {
            std::stringstream string_num, string_health;
            string_num << score << std::endl;
            string_health << health << std::endl;
            txt_score_number.setString(string_num.str());
            txt_health_number.setString(string_health.str());
        }

        win.draw(txt_score);
        win.draw(txt_score_number);
        if (Mode != NORMAL && current_state == RUNNING)
        {
            win.draw(txt_health);
            win.draw(txt_health_number);
        }

        if (current_state != FINISHED)
        {
            draw_gameplay(win);
        }
        else
        {
            txt_score.setString("Your score :");
            txt_score.setPosition(290, 300);
            txt_score_number.setFillColor(sf::Color::Green);
            txt_score_number.setPosition(455,300);
        }
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
        win.draw(instruction);
    }

    for (const auto & i : txt_vec)
    {
        win.draw(i);
    }
}

void ScreenController::draw_gameplay(sf::RenderWindow &win)
{
    for (auto & i : line)
    {
        i.setFillColor(border_color);
        win.draw(i);
    }
    check_reset = false;
    update();
    draw_snake(win);
    interval = (clock() - start_time);

    if(interval > interval_food())
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
        short temp = position_y(event.mouseButton.y);
        int y = event.mouseButton.y;
        int x = event.mouseButton.x;

        if (x < 105 && y < 43)
        {
            current_state = START_SCREEN;
            if (!check_reset)
                reset();
        }
        else if (x > 328 && x < 512 && y > 304 && y < 436)
        {
            set_state(temp);
        }
    }

    if(event.type == sf::Event::KeyPressed && current_state == RUNNING)
    {
        short k = event.key.code;
        head_rotate_func(k);
    }
}

short ScreenController::position_y(int y)
{
    y -= 310;
    for (short i = 0; i < 3; ++i)
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

void ScreenController::reset()
{
    score = 0;
    length = 10;
    health = 3;
    Snake::snake_position_x_y[0] = 300;
    Snake::snake_position_x_y[1] = 300;
    Snake::position_x.clear();
    Snake::position_y.clear();
    Board::remove_food();
    head_rotate = RIGHT;
    key_pressed = 72;

    txt_score.setString("Score: ");
    txt_score.setPosition(665,10);
    txt_score_number.setPosition(760,10);
    txt_score_number.setFillColor(sf::Color::White);

    check_reset = true;
}

int ScreenController::interval_food()
{
    if (Mode == NORMAL)
        return 400000;
    if (Mode == HERO)
        return 200000;
    if (Mode == GOD)
        return 100000;
    return -1;
}


