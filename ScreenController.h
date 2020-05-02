#ifndef SNAKE_SCREENCONTROLLER_H
#define SNAKE_SCREENCONTROLLER_H

#include "Menu.h"
#include <SFML/Graphics.hpp>



class ScreenController : public Menu{

    unsigned long interval;
    bool check_reset;

public:
    explicit ScreenController(GameMode mode);
    void draw_menu(sf::RenderWindow &win);
    void draw_gameplay(sf::RenderWindow &win);
    void handleEvent(sf::Event &e);
    int interval_food();
    void reset();
    short position_x();
    short position_y(int y);
};



#endif
