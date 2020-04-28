#include <iostream>
#include "Board.h"
#include <SFML/Graphics.hpp>

//
//to do:
//    position х

int main()
{
    srand(time(0));
    constexpr int screen_width = 800;
    constexpr int screen_height = 600;
    sf::RenderWindow win(sf::VideoMode(screen_width, screen_height), "Snake");
    win.setVerticalSyncEnabled(true);

    Board map(HERO);

    while (win.isOpen())
    {
        sf::Event event;
        while (win.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                win.close();
                continue;
            }
            map.handleEvent(event);
        }
        win.clear(sf::Color(105,105,105));
        map.draw(win);
        win.display();
    }

    return 0;
}
