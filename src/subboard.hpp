#ifndef SUBBOARD_HPP
#define SUBBOARD_HPP

#include <stdint.h>
#include <iostream>
#include <array>
#include <vector>
#include "util.hpp"

using namespace std;

class Subboard {

public:
    Subboard();
    ~Subboard();

    void play(int position, Player player);
    vector< pair<Subboard*, int> > getMoves();

    Player getWinner() const;
    bool hasWinner() const;

    friend std::ostream& operator<<(ostream& os, const Subboard& subboard);

private:
    array<Player, 9> grid;
    Player winner;

};

#endif
