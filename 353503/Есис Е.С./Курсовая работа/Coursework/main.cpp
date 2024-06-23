#include <QApplication>
#include <QScreen>
#include <QTimer>
#include <QString>
#include <QLabel>

#include "Game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game *game = new Game(qApp->screens()[0]->size());

    QLabel *label = new QLabel(game);
    label->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QPalette palette = label->palette();
    palette.setColor(label->foregroundRole(), Qt::red);
    label->setPalette(palette);

    QFont font = label->font();
    font.setPointSize(24);
    label->setFont(font);

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&] {
        label->setText(QString::number(game->destroyesEnemies));
        });

    timer.start(100);


    game->showMaximized();
    game->Start();
    return a.exec();
}
