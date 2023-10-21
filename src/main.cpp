#include "util.hpp"
#include "board.hpp"
#include "subboard.hpp"

int main(int argc, char* argv[]) {
    util::helloworld();
    Board board;
    std::cout << board << std::endl;

    return 0;
}
