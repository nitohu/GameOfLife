#include <iostream>

#include "../lib/board.hpp"

int main() {
    int w, h;
    std::cout << "Please enter width: ";
    std::cin >> w;
    std::cin.clear();
    std::cout << "Please enter height: ";
    std::cin >> h;
    std::cin.clear();
    std::cout << "===========" << std::endl;

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

    int gens = 5;
    std::cout << "Please enter the number of generations that should be simulated (Default 5): ";
    std::cin >> gens;
    std::cin.clear();
    if (gens < 1) gens = 5;

    for (int i = 0; i < gens; ++i) {
        std::cout << "===== Generation #" << b.getGeneration()+1 << " =====\n";
        b.update();
        b.printBoard(false);
    }

    return 0;
}
