#ifndef SNAKE_MENU_H
#define SNAKE_MENU_H

#include <SFML/Graphics.hpp>
#include "SnakeHead.h"
#include <string>
#include <vector>


class Menu : public SnakeHead{
protected:
    sf::Font font;
    sf::Text txt;
    sf::Text txt_back_button;
    sf::Text txt_score;
    sf::Text txt_score_number;
    std::vector<sf::Text> txt_vec;
    sf::Texture logo_cute_snake;
    sf::Texture logo_angry_snake;
    sf::Texture keyboard_arrows;
    sf::Sprite sprite_logo;
    sf::Sprite sprite_keyboard_arrows;

public:
    explicit Menu(GameMode & mode);
    std::string get_string_mode(GameMode & mode) const;
    void start_screen();
    void settings();
    void finished();
    void how_to_play();
    void set_state(short & state);
};



#endif
