#include <iostream>
#define TESTING false

#include "board.hpp"

Board::Board() {
    w = 0;
    h = 0;
    generation = 0;
}

Board::Board(int w, int h) {
    this->w = w;
    this->h = h;
    generation = 0;

    initializeBoard();
}

Board::~Board() {
    delete[] this->board;
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

int Board::getGeneration() {
    return generation;
}

int Board::getCellState(unsigned int pos) {
    if (pos > (w*h-1)) return false;
    return *(board + pos);
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

int Board::getNeighborCells(int cellPos, bool *cB) {
    /*
     * a  b  c
     * d  cP e
     * f  g  h
     */
    // Cellpos -> Position starting from 1 (good for border calculation stuff)
    // pos -> position starting from 0 (can be used as an index)
    int pos = cellPos - 1;
    int c = 0;
    bool top = false, left = false, right = false, bottom = false;
    if (cellPos == 10 || cellPos == 5 || cellPos == 3)
        c = 0;
    // Check if top side exists (& b)
    // Need to substract 1 from cellPos, since it starts from 1
    if ((cellPos - w) > 0) {
        top = true;
        // Add one if cell is alive
        if (*(cB + pos - w)) c++;
    }
    // Check if left side exists (&d)
    // If cellPos is on the most left side on the matrix, it cannot have left neighbors
    if ((cellPos - 1) > 0 && (cellPos-1)%w != 0) {
        left = true;
        if (*(cB + pos - 1)) c++;
    }
    // Check if right side exists (& e)
    // If cellPos is divisible by w (=> on the most right side of the matrix),
    // it cannot have a neighbor on its right side (would be on newline)
    if ((cellPos + 1) <= w*h && (cellPos) % w != 0) {
        right = true;
        if (*(cB + pos + 1)) c++;
    }
    // Check if bottom side exists (& g)
    if ((cellPos + w) <= w*h) {
        bottom = true;
        if (*(cB + pos + w)) c++;
    }
    // Check if a exists & is alive
    if (top && left)
        if (*(cB + pos - w - 1)) c++;
    // Check if C exists
    if (top && right)
        if (*(cB + pos - w + 1)) c++;
    // Check if F exists
    if (left && bottom)
        if (*(cB + pos + w - 1)) c++;
    // Check if H exists
    if (right && bottom)
        if (*(cB + pos + w + 1)) c++;
    return c;
}

void Board::update() {
    // Copy the current game board, since changes of cells in this round should not affect other cells yet
    bool *oldBoard = new bool[w*h];
    // Copy current board into old
    for(int i = 0; i < w*h; i++) {
        *(oldBoard + i) = *(board + i);
    }
    // Update each cell
    for (int i = 1; i < w*h+1; i++) {
        // Get current cell
        bool* cell = board + i - 1;
        // Get neighbor count of current cell
        int count = getNeighborCells(i, oldBoard);
        // Update cell based on game rules
        updateCell(cell, count);
    }
    generation++;
    delete[] oldBoard;
}

void Board::updateCell(bool *cell, int neighborCount) {
    // Update each cell by the following rules:
    // 1. Any live cell with two or three live neighbours survives (=> implies that cell is already alive)
    if (*cell && (neighborCount == 2 || neighborCount == 3)) {
        *cell = true;
    }
    // 2. Any dead cell with three live neighbours becomes a live cell
    else if (!*cell && neighborCount == 3) {
        *cell = true;
    }
    // 3. All other live cells die in the next generation. Similarly, all other dead cells stay dead
    else {
        *cell = false;
    }
}

void Board::toggleCell(unsigned int pos) {
    if (pos > (w*h-1)) return;
    *(board + pos) = !*(board + pos);
}
