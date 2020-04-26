#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    constexpr int screen_width = 800;
    constexpr int screen_height = 600;
    sf::RenderWindow win(sf::VideoMode(screen_width, screen_height), "Snake");
    win.setVerticalSyncEnabled(true);

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
        }

        win.clear(sf::Color::White);
        win.display();
    }

    return 0;
}
