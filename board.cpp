#include <iostream>
#define TESTING true

#include "board.hpp"

Board::Board() {
    w = 0;
    h = 0;
}

Board::Board(int w, int h) {
    this->w = w;
    this->h = h;

    initializeBoard();
}

Board::~Board() {
    delete this->board;
}

void Board::initializeBoard() {
    board = new bool[w * h];
    bool *p = board;
    for (int i = 1; i < h*w+1; i++) {
            // Initialize board with empty values
            *(p + i - 1) = false;
            if (TESTING && (i%3) == 0) *(p + i - 1) = true;
    }
}

void Board::setSize(int w, int h) {
    this->w = w;
    this->h = h;

    initializeBoard();
}

void Board::printBoard(bool showPos) {
    // Print upper border
    if (!showPos) {
        for (int i = 0; i < w + 4; ++i) {
            std::cout << "=";
        }
        std::cout << std::endl << "= ";
    }
    for (int i = 1; i < (h*w)+1; ++i) {
        if (showPos) std::cout << (i-1) << ' ';
        else std::cout << *(board+i-1);
        // Print side border & newline
        if ((i%w) == 0 && !showPos) {
            std::cout << " =\n";
            if (i < h*w) std::cout << "= ";
        } else if((i%w) == 0) std::cout << '\n';
    }
    // Print lower border
    if (!showPos) {
        for (int i = 0; i < w + 4; ++i) {
            std::cout << "=";
        }
    }
}

void Board::update() {
    for (int y = 0; y < this->h; ++y) {
        for (int x = 1; x < this->w; ++x) {
            // Update each cell by the following rules:
            // 1. Any live cell with two or three live neighbours survives
            // 2. Any dead cell with three live neighbours becomes a live cell
            // 3. All other live cells die in the next generation. Similarly, all other dead cells stay dead
            bool* cell = this->board + (y * x);
            // if ()
        }
    }
}

void Board::toggleCell(unsigned int pos) {
    if (pos > (w*h-1)) return;
    *(board + pos) = !*(board + pos);
}
