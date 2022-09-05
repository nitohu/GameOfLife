#include "GameButton.h"

GameButton::GameButton(
            wxWindow *parent,
            wxWindowID id,
            const wxString &label) : wxButton(parent, id, label) {
    btnId = nextId;
    nextId++;
}

int GameButton::GetIndex() {
    return btnId;
}

int GameButton::nextId = 0;
