//
// Created by nitohu on 02.09.2022.
//

#include "GameButton.h"

GameButton::GameButton(const QString &text, int id, QWidget *parent)
        : QPushButton{text, parent}
        , id(id) {
    connect(this, SIGNAL(clicked()), this, SLOT(click()));
}

GameButton::GameButton(const QString &text, QWidget *parent) : GameButton(text, nextId++, parent) {

}

void GameButton::click() {
    emit clicked(id);
}

int GameButton::nextId = 0;
