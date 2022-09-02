//
// Created by nitohu on 02.09.2022.
//

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget{parent}
    , nextGenBtn{new QPushButton("Next Generation", this)}
    , clearBtn{new QPushButton("Clear Board", this)}
    , gameBtns{std::vector<QPushButton*>()}
    , layout{new QGridLayout(this)} {

    // Initialize board
    for (int i = 0; i < 400; i++) {
        gameBtns.push_back(new QPushButton("0", this));
        gameBtns.at(i)->setStyleSheet("background-color: white");
        layout->addWidget(gameBtns.at(i), i/20, i%20);
    }

    layout->addWidget(nextGenBtn, 21, 0, 1, 20);

    layout->addWidget(clearBtn, 22, 0, 1, 20);

    board = new Board(20, 20);

    this->setLayout(layout);
}

MainWindow::~MainWindow() {
    delete[] board;
    delete layout;
    delete nextGenBtn;
    delete clearBtn;
    for (auto btn : gameBtns) delete btn;
}


