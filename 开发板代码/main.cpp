#include <QtGui/QApplication>
#include "mainwindow.h"
#include "loginwindow.h"
#include "qimage.h"

#include "qlabel.h"

#include "qpixmap.h"

int main(int argc, char *argv[])

{

QApplication a(argc, argv);

//LoginWindow w;
LoginWindow w;
w.show();
return a.exec();

}
