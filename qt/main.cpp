#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow window{};
    window.setWindowTitle("Game of Life - Qt Version");
    window.show();

    return QApplication::exec();
}
