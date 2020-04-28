#ifndef SNAKE_MENU_H
#define SNAKE_MENU_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

enum GameMode:unsigned short {NORMAL, HERO, GOD};
enum GameState:unsigned short {START_SCREEN, SETTINGS, HOW_TO_PLAY, RUNNING, FINISHED_WIN, FINISHED_LOSS};

class Menu{
protected:
    GameMode Mode;
    GameState state;
    sf::Font font;
    sf::Text txt;
    std::vector<sf::Text> txt_vec;
    sf::Texture logo;
    sf::Sprite sprite_logo;

public:
    explicit Menu(GameMode mode);
    std::string get_string_mode(GameMode mode) const;

};



#endif
