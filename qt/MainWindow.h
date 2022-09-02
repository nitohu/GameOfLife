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

class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Board *board;

    std::vector<QPushButton*> gameBtns;
    QPushButton *nextGenBtn;
    QPushButton *clearBtn;

    QGridLayout *layout;
};


#endif //QT_MAINWINDOW_H
