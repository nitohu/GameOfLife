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

bool Board::isRunning() {
    return running;
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
    std::cout << '\n';
}

int Board::getNeighborCells(int cellPos) {
    /*
     * a  b  c
     * d  cP e
     * f  g  h
     */
    int c = 0;
    bool b = false, d = false, e = false, g = false;
    // Check if b exists
    if ((cellPos - w) > 0) {
        c++;
        b = true;
    }
    // Check if d exists
    // If cellPos is on the most left side on the matrix, it cannot have left neighbors
    if ((cellPos - 1) > 0 && (cellPos-1)%w != 0) {
        c++;
        d = true;
    }
    // Check if e exists
    // If cellPos is divisible by w (=> on the most right side of the matrix),
    // it cannot have a neighbor on its right side (would be on newline)
    if ((cellPos + 1) <= w*h && (cellPos) % w != 0) {
        c++;
        e = true;
    }
    // Check if g exists
    if ((cellPos + w) <= w*h) {
        c++;
        g = true;
    }
    // Check if a exists
    if (b && d) c++;
    // Check if C exists
    if (b && e) c++;
    // Check if F exists
    if (d && g) c++;
    // Check if H exists
    if (e && g) c++;
    return c;
}

void Board::update() {
    for (int i = 1; i < w*h+1; i++) {
        // Update each cell by the following rules:
        // 1. Any live cell with two or three live neighbours survives
        // 2. Any dead cell with three live neighbours becomes a live cell
        // 3. All other live cells die in the next generation. Similarly, all other dead cells stay dead
        bool* cell = this->board + i;
        int count = getNeighborCells(i);
        std::cout << "Cell " << i << " has " << count << " neighbors." << std::endl;

    }
}

void Board::toggleCell(unsigned int pos) {
    if (pos > (w*h-1)) return;
    *(board + pos) = !*(board + pos);
}
