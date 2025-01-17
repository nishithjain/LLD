#include <QGridLayout>
#include <QPushButton>

#include "TicTacToeUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/TicTacToeUI/Resources/tic-tac-toe16X16.png"));
    TicTacToeUi w;

    w.show();
    return a.exec();
}
