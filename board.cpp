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
    board = new int[w * h];
    int *p = board;
    for (int y = 0; y < h+1; y++) {
        for (int x = 1; x < w+1; x++) {
            // Initialize board with empty values
            *(p + (y * x)) = 0;
        }
    }
}

void Board::setSize(int w, int h) {
    this->w = w;
    this->h = h;

    initializeBoard();
}

void Board::printBoard() {
    std::cout << "Height: " << this->h << std::endl;
    std::cout << "Width: " << this->w << std::endl;
    for (int y = 0; y < this->h+2; y++) {
        // Print upper & lower boarder
        if (y == 0 || y == this->h+1) {
            std::cout << ' ';
            for (int x = 0; x < this->w+4; ++x) {
                std::cout << '=';
            }
            std::cout << ' ';
        } else {
            // Print field
            for (int x = 0; x < this->w+2; ++x) {
                // Print side border
                if (x == 0 || x == this->w+1) std::cout << " = ";
                // Print field
                else std::cout << *(this->board + (y * x));
            }
        }
        std::cout << std::endl;
    }
}
