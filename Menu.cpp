#include <iostream>
#include "Menu.h"


Menu::Menu(GameMode &mode)
{
    Mode = mode;
    current_state = START_SCREEN;
    if (!font.loadFromFile("../Fonts/Arial.ttf"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    if (!logo_cute_snake.loadFromFile("../IMG/cute_snake.png"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    if (!logo_angry_snake.loadFromFile("../IMG/viper_head.png"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    if (!keyboard_arrows.loadFromFile("../IMG/arrows.png"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }

    start_screen();

    txt_back_button.setFont(font);
    txt_back_button.setFillColor(sf::Color(220, 103, 30));
    txt_back_button.setString("< Back");
    txt_back_button.setPosition(10,10);

}

std::string Menu::get_string_mode(GameMode & mode) const
{
    switch (mode)
    {
        case 0:
            return "NORMAL";
        case 1:
            return "HERO";
        case 2:
            return "GOD";
    }
}

void Menu::set_state(short &state)
{
    if(current_state == SETTINGS)
    {
        Mode = static_cast<GameMode>(state);
        current_state = last_state;
    } else{
        last_state = current_state;
        current_state = static_cast<GameState>(state);
    }

}

void Menu::start_screen()
{
    //sf::Color(148,0,0)

    if(Mode != GOD)
        sprite_logo.setTexture(logo_cute_snake);
    else
        sprite_logo.setTexture(logo_angry_snake);

    sprite_logo.setPosition(283, 0);

    txt.setFont(font);
    txt.setFillColor(sf::Color::Green);
    txt.setString("START");
    txt.setPosition(360,300);

    txt_vec.push_back(txt);

    txt.setString("SETTINGS");
    txt.setPosition(335,350);

    txt_vec.push_back(txt);

    txt.setFillColor(sf::Color(113, 217, 157));
    txt.setString("How to play?");
    txt.setPosition(332,400);

    txt_vec.push_back(txt);

    if(Mode == GOD)
        txt.setFillColor(sf::Color::Red);
    txt.setFillColor(sf::Color::Yellow);
    txt.setString("Mode: " + get_string_mode(Mode));
    txt.setPosition(10,555);

    txt_vec.push_back(txt);
}

void Menu::settings()
{
    txt.setFont(font);
    txt.setFillColor(sf::Color::Black);
    txt.setString("Select mode:");
    txt.setPosition(330,255);

    txt_vec.push_back(txt);

    txt.setFillColor(sf::Color::Green);
    txt.setString("NORMAL");
    txt.setPosition(350,300);

    txt_vec.push_back(txt);

    txt.setFillColor(sf::Color::Yellow);
    txt.setString("HERO");
    txt.setPosition(367,350);

    txt_vec.push_back(txt);

    txt.setFillColor(sf::Color::Red);
    txt.setString("GOD");
    txt.setPosition(373,400);

    txt_vec.push_back(txt);

    txt.setFillColor(sf::Color::Yellow);
    txt.setString("Mode: " + get_string_mode(Mode));
    txt.setPosition(10,555);

    txt_vec.push_back(txt);
}

void Menu::how_to_play()
{
    sprite_keyboard_arrows.setTexture(keyboard_arrows);
    sprite_keyboard_arrows.setPosition(300,300);
}

void Menu::game_play()
{

}

GameState Menu::get_state() const
{
    return current_state;
}
