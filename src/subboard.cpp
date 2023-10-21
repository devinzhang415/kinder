#include "subboard.hpp"

Subboard::Subboard() {
    grid = {util::X, util::O, util::_, util::X, util::O, util::_, util::X, util::O, util::_};
    winner = util::_;
}

Subboard::~Subboard() {

}

void Subboard::play(int position, util::Player player) {
    if (position < 0 || position > 9) {
        return;
    }
    grid[position] = player;
}

char Subboard::getWinner() const {
    return winner;
}

std::ostream& operator<<(std::ostream& os, const Subboard& subboard) {
    std::array<util::Player, 9> board = subboard.grid;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            os << static_cast<char>(board[3*i + j]);
        }
        os << "\n";
    }
    return os;
}
