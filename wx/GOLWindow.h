#include <wx/wxprec.h>
#include <vector>

#include "../lib/board.hpp"

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class GOLWindow : public wxFrame {
public:
    GOLWindow();
    ~GOLWindow();

protected:
    void initWindow();

private:
    // Members
    Board *board;
    int board_width;
    int board_height;
    
    // Event Handlers
    void OnHello(wxCommandEvent &evt);
    void OnAbout(wxCommandEvent &evt);

    void OnGameButton(wxCommandEvent &evt);
    void OnNextStep(wxCommandEvent &evt);
    void OnClear(wxCommandEvent &evt);
};

enum {
    ID_HELLO = 1,
    ID_NEXT  = 2,
    ID_CLEAR = 3,
    ID_GAME  = 4
};
