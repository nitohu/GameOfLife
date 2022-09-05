#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class GameButton : public wxButton {
private:
    static int nextId;
    int btnId;

public:
    GameButton(
            wxWindow *parent,
            wxWindowID id,
            const wxString &label = wxEmptyString);

    int GetIndex();
};
