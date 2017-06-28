#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Fake Emblem:Under Construction");
    w.show();
    return a.exec();
}

/* ==Fake Emblem 0.1.0==
 * A game that emulates Fire Embles Series
 * music from Fire Emblem: the Sacred Stone
 * picture from Fire Emblem: awakening
 *
 * ==Changelog 0.1.0==
 * -make the repository to public
 * ==Known Bugs/issues==
 * -may be more classes later like evolved knight, etc...
 */
