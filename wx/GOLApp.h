// There are probably better imports for this (wxApp only maybe)
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class GOLApp : public wxApp {
public:
    virtual bool OnInit();

};
