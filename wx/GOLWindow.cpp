#include "GOLWindow.h"
#include "GameButton.h"

#include <iostream>

GOLWindow::GOLWindow() : wxFrame(NULL, wxID_ANY, "Game of Life - wxWidgets Version") {
    board_width = 20;
    board_height = 20;
    board = new Board(board_width, board_height);

    initWindow();
}

GOLWindow::~GOLWindow() {
    // I guess the parent's destructor will be called automatically
    // wxWidgets' DELETE makro (=> `#define wxDELETE(p)\t if ( (p) != NULL ) { delete p; p = NULL; }` )
    wxDELETE(board);
}

void GOLWindow::initWindow() {
    // Build UI
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_HELLO, "&Hello...\tCTRL+H", "Some help string.");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    // Not needed for this application
    /*
    CreateStatusBar();
    SetStatusText("Some status text");
    */
    // Using panel positions the two texts over each other
    /*
    wxPanel *panel = new wxPanel(this);
    wxStaticText *txt = new wxStaticText(panel, wxID_STATIC, "Some label hopefully displayed...");
    wxStaticText *txt2 = new wxStaticText(panel, wxID_STATIC, "Some other label...");
    // If sizer exists: sizer->Add(panel); // items in panel still get positions over each other
    */
    // Use sizer instead
    wxBoxSizer *pSizer = new wxBoxSizer(wxVERTICAL);
    wxFlexGridSizer *sizer = new wxFlexGridSizer(board_height, board_width, 1, 1);
    // Generate buttons used for playing the game
    for(int i = 0; i < (board_width * board_height); i++) {
        // Probably need a custom button class with static variable which counts for the identifier
        auto *btn = new GameButton(this, ID_GAME, "0");
        Bind(wxEVT_BUTTON, &GOLWindow::OnGameButton, this, ID_GAME);
        sizer->Add(btn);
    }

    pSizer->Add(sizer);
    // Control buttons
    auto *nextBtn = new wxButton(this, ID_NEXT, "Next Step");
    // pSizer->AddGrowableRow(board_height, 1);
    // Add nextBtn with proportion 1, expanding and set padding to 1
    pSizer->Add(nextBtn, 1, wxEXPAND | wxALL, 1);

    auto *clearBtn = new wxButton(this, ID_CLEAR, "Clear Board");
    pSizer->Add(clearBtn, 1, wxEXPAND | wxALL, 1);

    SetSizerAndFit(pSizer);

    // Bind Menu items
    Bind(wxEVT_MENU, &GOLWindow::OnHello, this, ID_HELLO);
    Bind(wxEVT_MENU, &GOLWindow::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, [=](wxCommandEvent&) { Close(true); }, wxID_EXIT);
    // Bind buttons
    Bind(wxEVT_BUTTON, &GOLWindow::OnNextStep, this, ID_NEXT);
    Bind(wxEVT_BUTTON, &GOLWindow::OnClear, this, ID_CLEAR);

}

void GOLWindow::OnHello(wxCommandEvent &evt) {
    wxLogMessage("Hello from Game of Life.");
}

void GOLWindow::OnAbout(wxCommandEvent &evt) {
    wxMessageBox("Welcome to 'Game of Life' developed in C++ with wxWidgets!", "About GameOfLife", wxOK | wxICON_INFORMATION);
}

void GOLWindow::OnNextStep(wxCommandEvent &evt) {
    std::cout << "Simulate next step" << std::endl;
}

void GOLWindow::OnClear(wxCommandEvent &evt) {
    std::cout << "Clear board" << std::endl;
}

void GOLWindow::OnGameButton(wxCommandEvent &evt) {
    std::cout << "Button clicked.. sure which one?" << std::endl;
    GameButton *btn = (GameButton*) evt.GetEventObject();
    // TODO: Get index of button clicked (maybe need some class with static variable for counting the index)
    // TODO: Update board with index the button was clicked
    // TODO: Update label according to field state of board 
    btn->SetLabel("1");
    std::cout << btn << " " << btn->GetIndex() << std::endl;
}
