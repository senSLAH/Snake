#include "Board.h"

Board::Board()
{
    food_count = 0;
}

void Board::random_food_position()
{
    food_position_x[food_count] = rand() % 785 + 1;
    food_position_y[food_count] = rand() % 585 + 1;
    ++food_count;
}

//void Board::draw_food() const
//{
//    for (int i = 0; i < food_count; ++i)
//    {
//
//    }
//}

