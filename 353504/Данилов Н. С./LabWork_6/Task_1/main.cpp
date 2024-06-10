#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include "QFile"
#include "QDebug"
#include "QTextEdit"
#include "SportTeam.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QMainWindow *Main = new QMainWindow;
    QFile stylesFile("/home/shosh/CourseProject/Course project/Styles/styles.qss");
    qDebug() << stylesFile.open(QIODevice::ReadWrite);
    QString style(stylesFile.readAll());
    a.setStyleSheet(style);
   .
    SportTeam team2;
    for (int i : team1.count_of_GOOOOOOLS) {
        TextScreen->setText(TextScreen->toPlainText() + "|" + QString::number(i));
    }
    Main->show();
    return QApplication::exec();
}
