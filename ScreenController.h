#ifndef SNAKE_SCREENCONTROLLER_H
#define SNAKE_SCREENCONTROLLER_H

#include "Menu.h"
#include <SFML/Graphics.hpp>



class ScreenController : public Menu{
    int start_time;
    unsigned long interval;
public:
    explicit ScreenController(GameMode mode);
    void draw_menu(sf::RenderWindow &win);
    void draw_gameplay(sf::RenderWindow &win);
    void handleEvent(sf::Event &e);
    short position_x(int x);
    short position_y(int y);
};



#endif
