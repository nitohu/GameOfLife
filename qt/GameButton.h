//
// Created by nitohu on 02.09.2022.
//

#ifndef QT_GAMEBUTTON_H
#define QT_GAMEBUTTON_H
#include <QPushButton>

class GameButton : public QPushButton {
    Q_OBJECT

public:
    GameButton(const QString &text, int id, QWidget *parent = nullptr);
    explicit GameButton(const QString &text, QWidget *parent = nullptr);

private:
    static int nextId;
    int id;

public slots:
    void click();

signals:
    void clicked(int id);
};


#endif //QT_GAMEBUTTON_H
