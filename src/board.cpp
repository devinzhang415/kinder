#include "board.hpp"

using namespace std;

/**
 * @brief Construct a new Board:: Board object.
 * 
 */
Board::Board() {
    winner = _;
    prevMove = -1;
}

/**
 * @brief Destroy the Board:: Board object.
 * 
 */
Board::~Board() {}

/**
 * @brief Return the list of moves available, given as (Subboard, index)
 *        pairs, indicating the subboard the move at index can be played at.
 * 
 * @return vector< pair<Subboard*, int >, a list of indices possible to play a move at.
 */
vector< pair<Subboard*, int> > Board::getMoves() {
    vector<Subboard*> subboards;
    if (prevMove == -1) {
        // Next move IS NOT restricted to a particular subboard.
        for (int i = 0; i < 9; i++) {
            Subboard* subboard = &grid[i];
            if (!subboard->hasWinner()) {
                subboards.push_back(subboard);
            }
        }
    } else {
        Subboard* targetSubboard = &grid[prevMove];
        if (targetSubboard->hasWinner()) {
            // Next move IS NOT restricted to a particular subboard.
            for (int i = 0; i < 9; i++) {
                Subboard* subboard = &grid[i];
                if (!subboard->hasWinner()) {
                    subboards.push_back(subboard);
                }
            }
        } else {
            // Next move IS restricted to a the subboard that
            // is in the same position as the previous move.
            subboards.push_back(targetSubboard);
        }
    }

    vector< pair<Subboard*, int> > moves;
    for (size_t i = 0; i < subboards.size(); i++) {
        Subboard* subboard = subboards[i];
        vector< pair<Subboard*, int> > subboardMoves = subboard->getMoves();
        moves.insert(moves.end(), subboardMoves.begin(), subboardMoves.end());
    }

    return moves;
}

/**
 * @brief The winner of this board.
 * 
 * @return Player, the winning player. If no winning player, return `_`.
 */
Player Board::getWinner() const {
    return winner;
}

/**
 * @brief Whether there is a winner for this board.
 * 
 * @return true if winner is X or O.
 * @return false if winner is _.
 */
bool Board::hasWinner() const {
    return (winner != _);
}

/**
 * @brief Print the board.
 * 
 * @param os 
 * @param board 
 * @return ostream& 
 */
ostream& operator<<(ostream& os, const Board& board) {
    array<Subboard, 9> grid = board.grid;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            os << static_cast<char>(grid[3*i + j].getWinner());
        }
        os << "\n";
    }
    return os;
}
