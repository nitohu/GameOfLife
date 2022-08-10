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
}

void Board::getNeighborCells(int cellPos, int *r) {
    std::cout << "Finding neighbor cells for cell " << cellPos << "..." << std::endl;
    std::cout << "a   b   c\nd   cP  e\nf   g   h" << std::endl;
    /*
     * a  b  c
     * d  cP e
     * f  g  h
     */
    int *p = r;
    // Search for a
    if ((cellPos - w - 1) > 0 && (cellPos - w - 1) % w != 0) {
        *p = cellPos - w - 1;
        std::cout << "Found a: " << *p << std::endl;
    }
    p++;
    // Search for b
    if ((cellPos - w) > 0 && (cellPos - w) % w != 0) {
        *p = cellPos - w;
        std::cout << "Found b: " << *p << std::endl;
    }
    p++;
    // Search for c
    if ((cellPos - w + 1) > 0 && (cellPos + 1) < w*h && (cellPos - w + 1) % w != 0) {
        *p = cellPos - w + 1;
        std::cout << "Found c: " << *p << std::endl;
    }
    p++;
    // Search for d
    if ((cellPos - 1) > 0 && (cellPos - 1) % w != 0) {
        *p = cellPos - 1;
        std::cout << "Found d: " << *p << std::endl;
    }
    p++;
    // Search for e
    if ((cellPos + 1) < w*h && (cellPos + 1) % w != 0) {
        *p = cellPos + 1;
        std::cout << "Found e: " << *p << std::endl;
    }
    p++;
    // Search for f
    if ((cellPos + w - 1) > 0 && (cellPos + w - 1) < w*h && (cellPos + w - 1) % w != 0) {
        *p = cellPos + w - 1;
        std::cout << "Found f: " << *p << std::endl;
    }
    p++;
    // Search for g
    if ((cellPos + w) < w*h && (cellPos + w) % w != 0) {
        *p = cellPos + w;
        std::cout << "Found g: " << *p << std::endl;
    }
    p++;
    // Search for h
    if ((cellPos + w + 1) < w*h && (cellPos + w + 1) % w != 0) {
        *p = cellPos + w + 1;
        std::cout << "Found h: " << *p << std::endl;
    }
}

void Board::update() {
    for (int i = 1; i < w*h + 1; i++) {
        // Update each cell by the following rules:
        // 1. Any live cell with two or three live neighbours survives
        // 2. Any dead cell with three live neighbours becomes a live cell
        // 3. All other live cells die in the next generation. Similarly, all other dead cells stay dead
        bool* cell = this->board + i;
        int neighborPos[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        getNeighborCells(i, neighborPos);
        for (int j = 0; j < 8; ++j) {
            std::cout << "Neighbor positions: " << neighborPos[j] << std::endl;
        }
    }
}

void Board::toggleCell(unsigned int pos) {
    if (pos > (w*h-1)) return;
    *(board + pos) = !*(board + pos);
}
