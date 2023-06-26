#include "frame.h"
#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

 //   QMainWindow window;
    frame window;
 //   window.setCentralWidget(freim);

    window.setFixedSize(300, 300);
    window.setWindowTitle("2048_Cpp_Qt");
    window.show();

    return app.exec();
}
