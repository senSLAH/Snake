#include <iostream>
#include "Menu.h"


Menu::Menu(GameMode mode)
{
    Mode = mode;
    state = START_SCREEN;
    if (!font.loadFromFile("../Fonts/Arial.ttf"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    if (!logo.loadFromFile("../IMG/cute_snake.png"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    //sf::Color(148,0,0)
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

    txt.setFillColor(sf::Color::Yellow);
    txt.setString("Mode: " + get_string_mode(mode));
    txt.setPosition(620,550);

    txt_vec.push_back(txt);

    sprite_logo.setTexture(logo);
    sprite_logo.setPosition(283,0);

}

std::string Menu::get_string_mode(GameMode mode) const
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
