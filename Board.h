#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H

#include <vector>
#include <SFML/Graphics.hpp>

enum FoodType : short { APPLE, MUSHROOM, TNT };
enum GameMode:unsigned short {NORMAL, HERO, GOD};
enum GameState:unsigned short {RUNNING, SETTINGS, HOW_TO_PLAY, START_SCREEN, FINISHED};

struct Food
{
    short food_position_x;
    short food_position_y;
    FoodType type;
};

class Board{
protected:
    GameMode Mode;
    GameState last_state;
    GameState current_state;
    int time;
    int start_time;
    short food_count;
    int health;
    Food f;
    sf::Texture apple_texture;
    sf::Texture mushroom_texture;
    sf::Texture TNT_texture;
    sf::Sprite appple;
    sf::Sprite mushroom;
    sf::Sprite tnt;
    sf::RectangleShape line[4];
    sf::Color border_color;
    std::vector<Food> food;

public:
    Board();
    void add_food();
    void remove_food(int position = 1);
    void draw_food(sf::RenderWindow &win);
    int how_many_food();
    virtual void set_state(GameState state);
    GameState get_state() const;

};



#endif
