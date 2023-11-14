#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include "util.hpp"
#include "subboard.hpp"

using namespace std;

class Board {

public:
    Board();
    ~Board();

    friend ostream& operator<<(ostream& os, const Board& board);

private:
    array<Subboard, 9> grid;

};

#endif
