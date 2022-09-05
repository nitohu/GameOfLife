#include "GOLApp.h"
#include "GOLWindow.h"

bool GOLApp::OnInit() {
    GOLWindow *win = new GOLWindow();
    win->Show(true);
    return true;
}
