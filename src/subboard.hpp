#ifndef SUBBOARD_HPP
#define SUBBOARD_HPP

#include <stdint.h>
#include <iostream>
#include <array>
#include "util.hpp"

class Subboard {

public:
    Subboard();
    ~Subboard();

    void play(int position, util::Player player);

    char getWinner() const;

    friend std::ostream& operator<<(std::ostream& os, const Subboard& subboard);

private:
    std::array<util::Player, 9> grid;
    
    char winner;

};

#endif
