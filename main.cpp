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
    b.printBoard(true);
    b.printBoard(false);

    // Toggle field
    while(true) {
        int p;
        std::cout << "Toggle field (negative for exiting toggle mode): " << std::endl;
        std::cin >> p;
        if (p < 0) break;
        b.toggleCell(p);
        b.printBoard(true);
        b.printBoard(false);
    }

    return 0;
}
