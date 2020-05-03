#include <iostream>
#include "ScreenController.h"
#include "Board.h"

#include <SFML/Graphics.hpp>




int main()
{
    srand(time(0));
    constexpr int screen_width = 800;
    constexpr int screen_height = 600;
    sf::RenderWindow win(sf::VideoMode(screen_width, screen_height), "Snake");
    win.setVerticalSyncEnabled(true);

    ScreenController map(HERO);
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
        if (map.get_state() == RUNNING)
        {
            win.clear(sf::Color::Black);
        }
        else
            win.clear(sf::Color(105,105,105));

        map.draw_menu(win);
        win.display();
    }
    return 0;
}
