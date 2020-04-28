#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H

#include "Menu.h"
#include <SFML/Graphics.hpp>



class Board : public Menu {
public:
    explicit Board(GameMode mode);
    void draw(sf::RenderWindow &win) const;
    void handleEvent(sf::Event &e);
    short position_x(int x);
    short position_y(int y);
};



#endif
