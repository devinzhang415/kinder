#include "board.hpp"

Board::Board() {
    std::cout << grid[0] << std::endl;
}

Board::~Board() {

}

std::ostream& operator<<(std::ostream& os, const Board& board) {
    std::array<Subboard, 9> grid = board.grid;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            os << static_cast<char>(grid[3*i + j].getWinner());
        }
        os << "\n";
    }
    return os;
}
