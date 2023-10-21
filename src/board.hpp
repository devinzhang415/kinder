#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include "util.hpp"
#include "subboard.hpp"

class Board {

public:
    Board();
    ~Board();

    friend std::ostream& operator<<(std::ostream& os, const Board& board);

private:
    std::array<Subboard, 9> grid;

};

#endif
