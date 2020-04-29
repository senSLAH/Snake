#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H

#include <vector>

class Board {
protected:
    short food_count;
    std::vector<int> food_position_x;
    std::vector<int> food_position_y;

public:
    Board();
    void random_food_position();
    void draw_food() const;

};



#endif //SNAKE_BOARD_H
