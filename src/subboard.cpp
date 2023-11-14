#include "subboard.hpp"

using namespace std;

/**
 * @brief Construct a new Subboard:: Subboard object.
 * 
 */
Subboard::Subboard() {
    grid = {_, _, _,
            _, _, _,
            _, _, _};
    winner = _;
}

/**
 * @brief Destroy the Subboard:: Subboard object.
 * 
 */
Subboard::~Subboard() {}

/**
 * @brief Play a given move, placing a mark `player` at position `position`.
 *        If a player would get 3-across, that player is the winner of this board.
 * 
 * @param position the index to play the move at.
 * @param player the player playing the move.
 */
void Subboard::play(int position, Player player) {
    if (!(position >= 0 && position <= 8)) {
        return;
    }

    grid[position] = player;
    
    // Check positions that may result in a win.
    // `x` marks the position played.
    // `c` indicates the position needs to be checked.
    switch (position) {
        case 0:
        {
            // x c c
            // c c _
            // c _ c
            if ((grid[1] == player && grid[2] == player) ||
                (grid[3] == player && grid[6] == player) ||
                (grid[4] == player && grid[8] == player)) {
                    winner = player;
            }
            break;
        }
        case 1:
        {
            // c x c
            // _ c _
            // _ c _
            if ((grid[0] == player && grid[2] == player) ||
                (grid[4] == player && grid[7] == player)) {
                    winner = player;
            }
            break;
        }
        case 2:
        {
            // c c x
            // _ c c
            // c _ c
            if ((grid[0] == player && grid[1] == player) ||
                (grid[5] == player && grid[8] == player) ||
                (grid[4] == player && grid[6] == player)) {
                    winner = player;
            }
            break;
        }
        case 3:
        {
            // c _ _
            // x c c
            // c _ _
            if ((grid[0] == player && grid[6] == player) ||
                (grid[4] == player && grid[5] == player)) {
                    winner = player;
            }
            break;
        }
        case 4:
        {
            // c c c
            // c x c
            // c c c
            if ((grid[0] == player && grid[8] == player) ||
                (grid[1] == player && grid[7] == player) ||
                (grid[2] == player && grid[6] == player) ||
                (grid[3] == player && grid[5] == player)) {
                    winner = player;
            }
            break;
        }
        case 5:
        {
            // _ _ c
            // c c x
            // _ _ c
            if ((grid[2] == player && grid[8] == player) ||
                (grid[3] == player && grid[4] == player)) {
                    winner = player;
            }
            break;
        }
        case 6:
        {
            // c _ c
            // c c _
            // x c c
            if ((grid[0] == player && grid[3] == player) ||
                (grid[7] == player && grid[8] == player) ||
                (grid[4] == player && grid[2] == player)) {
                    winner = player;
            }
            break;
        }
        case 7:
        {
            // _ c _
            // _ c _
            // c x c
            if ((grid[1] == player && grid[4] == player) ||
                (grid[6] == player && grid[8] == player)) {
                    winner = player;
            }
            break;
        }
        case 8:
        {
            // c _ c
            // _ c c
            // c c x
            if ((grid[0] == player && grid[4] == player) ||
                (grid[2] == player && grid[5] == player) ||
                (grid[6] == player && grid[7] == player)) {
                    winner = player;
            }
            break;
        } 
        default:
            break;
    }
}

/**
 * @brief Return the list of moves available on this given subboard.
 *        This list will be empty if there is a winner for this board already,
 *        indicating it is not possible to make further moves on this board.
 * 
 * @return vector< pair<Subboard*, int> >, a list of indices possible to play a move at in this subboard.
 */
vector< pair<Subboard*, int> > Subboard::getMoves() {
    vector< pair<Subboard*, int> > moves;
    if (winner != _) {
        for (int position = 0; position < 9; position++) {
            if (grid[position] == _) {
                pair<Subboard*, int> move = make_pair(this, position);
                moves.push_back(move);
            }
        }
    }
    return moves;
}

/**
 * @brief The winner of this subboard.
 * 
 * @return Player, the winning player. If no winning player, return `_`.
 */
Player Subboard::getWinner() const {
    return winner;
}

/**
 * @brief Whether there is a winner for this subboard.
 * 
 * @return true if winner is X or O.
 * @return false if winner is _.
 */
bool Subboard::hasWinner() const {
    return (winner != _);
}

/**
 * @brief Print the subboard.
 * 
 * @param os 
 * @param subboard 
 * @return ostream& 
 */
ostream& operator<<(ostream& os, const Subboard& subboard) {
    array<Player, 9> board = subboard.grid;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            os << static_cast<char>(board[3*i + j]);
        }
        os << "\n";
    }
    return os;
}
