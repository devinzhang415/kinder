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

    vector< pair<Subboard*, int> > getMoves();

    Player getWinner() const;
    bool hasWinner() const;

    friend ostream& operator<<(ostream& os, const Board& board);

private:
    array<Subboard, 9> grid;
    Player winner;

    // The index of the previous move
    // was played on. This restricts which subboard
    // the next move can be played on.
    // If -1, indicating no previous move, any subboard can be played on.
    int prevMove;

};

#endif
