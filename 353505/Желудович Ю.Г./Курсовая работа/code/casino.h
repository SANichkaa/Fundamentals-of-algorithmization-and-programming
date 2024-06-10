// Casino.h

#ifndef CASINO_H
#define CASINO_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QMap>
#include <QList>
#include <QLabel>
#include <QComboBox>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include "rotableitem.h"
#include "character.h"
#include "linearcongruentialgenerator.h"

namespace Ui {
class Casino;
}

class Casino : public QMainWindow {
    Q_OBJECT
    Q_PROPERTY(int rotationAngle READ rotationAngle WRITE setRotationAngle)

public:
    explicit Casino(QWidget *parent = nullptr);

    void setupUi();
    void drawRouletteWheel();
    void drawWheelSections();
    void updateWheel();
    void showResult();
    void updateCurrentBetsLabel();
    void setRotationAngle(int angle);
    int rotationAngle() const;

signals:
        void OpenMainWindow();
        void changeBalance(int moneyMinus);

private slots:
    void spinRoulette();
    void handleAnimationFinished();
    void placeBet(int betNumber);
    void updateChipValue(int index);

    void on_spinButton_clicked();
    void backToPreviousScreen();

private:

    Ui::Casino *ui;

    QGraphicsScene *scene;
    QGraphicsEllipseItem *wheel;
    QPushButton *spinButton;
    QPropertyAnimation *spinAnimation;
    int currentAngle;
    int resultNumber;
    int moneyMinus;
    QMap<int, int> currentBets;
    QList<int> rouletteNumbers = {0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13, 36, 11, 30, 8, 23, 10, 5, 24, 16, 33, 1, 20, 14, 31, 9, 22, 18, 29, 7, 28, 12, 35, 3, 26};
    QLabel *currentBetsLabel;
    QComboBox *chipValueComboBox;
    int currentChipValue;
    QGraphicsView* view;
    QPropertyAnimation *animation;
    RotableItem *rotatableWheel;
    QPushButton* backButton;

    int currentBet;
    int currentWin;



};


#endif // CASINO_H
