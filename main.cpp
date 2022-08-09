#include <iostream>

#include "board.hpp"

int main() {
    int w, h;
    std::cout << "Please enter width: ";
    std::cin >> w;
    std::cin.clear();
    std::cout << "Please enter height: ";
    std::cin >> h;

    Board b = Board(w, h);
    b.printBoard();

    return 0;
}
