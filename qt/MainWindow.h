//
// Created by nitohu on 02.09.2022.
//

#ifndef QT_MAINWINDOW_H
#define QT_MAINWINDOW_H
#include <QApplication>
#include <QGridLayout>
#include <QPushButton>
#include <vector>

#include "../lib/board.hpp"
#include "GameButton.h"

class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Board *board;

    std::vector<GameButton*> gameBtns;
    QPushButton *nextGenBtn;
    QPushButton *clearBtn;

    QGridLayout *layout;

    void updateBoard();

private slots:
    void toggleBtn(int index);
    void nextGeneration();
    void clearBoard();
};


#endif //QT_MAINWINDOW_H
