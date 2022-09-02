//
// Created by nitohu on 02.09.2022.
//

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget{parent}
    , nextGenBtn{new QPushButton("Next Generation", this)}
    , clearBtn{new QPushButton("Clear Board", this)}
    , gameBtns{std::vector<GameButton*>()}
    , layout{new QGridLayout(this)} {

    // Initialize board
    for (int i = 0; i < 400; i++) {
        gameBtns.push_back(new GameButton("0", this));
        gameBtns.at(i)->setStyleSheet("background-color: white");
        QObject::connect(gameBtns.at(i), &GameButton::clicked, this, &MainWindow::toggleBtn);
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

void MainWindow::toggleBtn(int index) {
    board->toggleCell(index);
    bool cs = board->getCellState(index);
    gameBtns.at(index)->setText(cs ? "1" : "0");
    QString style = QString(cs
                            ? "background-color: gray"
                            : "background-color: white");
    gameBtns.at(index)->setStyleSheet(style);
}


