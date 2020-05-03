#ifndef SNAKE_MENU_H
#define SNAKE_MENU_H

#include <SFML/Graphics.hpp>
#include "Snake.h"
#include <string>
#include <vector>


class Menu : public Snake{
protected:
    sf::Font font;
    sf::Text txt;
    sf::Text instruction;
    sf::Text txt_back_button;
    sf::Text txt_score;
    sf::Text txt_health;
    sf::Text txt_score_number;
    sf::Text txt_health_number;
    std::vector<sf::Text> txt_vec;
    sf::Texture logo_cute_snake;
    sf::Texture logo_angry_snake;
    sf::Texture keyboard_arrows;
    sf::Sprite sprite_logo;
    sf::Sprite sprite_keyboard_arrows;

public:
    explicit Menu(GameMode & mode);
    static std::string get_string_mode(GameMode & mode) ;
    void start_screen();
    void settings();
    void how_to_play();
    void set_state(short & state);
};



#endif
