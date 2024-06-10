#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class StartPage : public QWidget {
    Q_OBJECT

public:
    StartPage(QWidget *parent = nullptr);

signals:
    void gameLoaded();
    void newGameStarted();

private slots:
    void loadGame();
    void newGame();
};

#endif // STARTPAGE_H
