#include "casino.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsView>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QEasingCurve>
#include <QtMath>
#include <QLabel>
#include <QComboBox>
#include <ctime>

Casino::Casino(QWidget *parent)
    : QMainWindow(parent), currentAngle(0), resultNumber(0), currentChipValue(10) {
    setupUi();
    connect(this, SIGNAL(changeBalance(int)), Character::GetInstance(), SLOT(betChange(int)));
    moneyMinus = 0;
}

class Random64
{
public:
    typedef unsigned long long uint64;
    typedef uint64 RandomValue;

    Random64()
    {
        // Инициализация зерна на основе текущего времени
        X = static_cast<uint64>(std::time(nullptr));
    }

    Random64& operator=(uint64 seed)
    {
        X = seed;
        return *this;
    }

    uint64 operator()(uint64 seed = uint64(-1))
    {
        const uint64 a = 3202034522624059733ULL;
        const uint64 c = 1ULL;

        if (seed != uint64(-1))
            X = seed;

        uint64 Y = a * X + c;
        X = a * Y + c;
        Y = (Y & 0xFFFFFFFF00000000ULL) | (X >> 32);
        return Y;
    }

    uint64 operator()(uint64 min, uint64 max)
    {
        return (*this)() % (max - min) + min;
    }

private:
    uint64 X;
};

void Casino::setupUi() {
    // Создаем сцену и виджет для отображения
    scene = new QGraphicsScene(this);
    QGraphicsView *view = new QGraphicsView(scene, this);
    setCentralWidget(view);

    // Вызов функций отрисовки колеса и секций
    drawRouletteWheel();
    drawWheelSections();

    // Настройка кнопки Spin
    spinButton = new QPushButton("Spin", this);
    connect(spinButton, &QPushButton::clicked, this, &Casino::spinRoulette);

    // Настройка выбора номинала фишек
    QLabel *chipLabel = new QLabel("Select Chip Value:", this);
    chipValueComboBox = new QComboBox(this);
    chipValueComboBox->addItems({"5", "10", "25", "50"});
    connect(chipValueComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Casino::updateChipValue);

    // Настройка кнопок ставок
    QWidget *betWidget = new QWidget(this);
    QGridLayout *gridLayout = new QGridLayout(betWidget);
    betWidget->setLayout(gridLayout);
    for (int i = 0; i < 37; ++i) {
        QPushButton *button = new QPushButton(QString::number(i), this);
        connect(button, &QPushButton::clicked, this, [this, i]() { placeBet(i); });
        gridLayout->addWidget(button, i / 10, i % 10); // 10 кнопок в строке
    }

    // Метка для отображения текущих ставок
    currentBetsLabel = new QLabel("Current Bets:\n", this);

    // Добавляем элементы в основной layout
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(view);
    mainLayout->addWidget(spinButton);
    mainLayout->addWidget(chipLabel);
    mainLayout->addWidget(chipValueComboBox);
    mainLayout->addWidget(betWidget);
    mainLayout->addWidget(currentBetsLabel);

    backButton = new QPushButton("ВЕРНУТЬСЯ", this);
    connect(backButton, &QPushButton::clicked, this, &Casino::backToPreviousScreen);
        mainLayout->addWidget(backButton);


    QWidget *mainWidget = new QWidget(this);
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    // Инициализация анимации
    spinAnimation = new QPropertyAnimation(this, "rotationAngle");
    spinAnimation->setEasingCurve(QEasingCurve::OutQuad);
    connect(spinAnimation, &QPropertyAnimation::finished, this, &Casino::handleAnimationFinished);
}

void Casino::spinRoulette() {
    spinButton->setEnabled(false); // Блокируем кнопку Spin


    Random64 rng;

    // Генерация случайного результата
    resultNumber = rng(0, 37);

    // Вычисление целевого угла
    int targetIndex = rouletteNumbers.indexOf(resultNumber);
    int targetAngle = targetIndex * (360 / 37);

    // Добавляем дополнительные вращения для эффекта
    int extraRotations = 5 * 360; // 5 полных оборотов

    emit changeBalance(moneyMinus);
    moneyMinus = 0;
    spinAnimation->setDuration(3000); // 3 секунды
    spinAnimation->setStartValue(currentAngle);
    spinAnimation->setEndValue(currentAngle + extraRotations + targetAngle);
    spinAnimation->start();
}

void Casino::handleAnimationFinished() {
    // Обновляем текущий угол
    currentAngle = spinAnimation->endValue().toInt() % 360;
    spinButton->setEnabled(true); // Разблокируем кнопку Spin

    // Показ результата
    showResult();

    // Очистка ставок
    currentBets.clear();
    updateCurrentBetsLabel();
}

void Casino::updateWheel() {
    // Поворот колеса в соответствии с текущим углом
    QTransform transform;
    transform.rotate(currentAngle);
    wheel->setTransform(transform);
}

void Casino::placeBet(int betNumber) {

    if (currentBets.contains(betNumber)) {
        if(moneyMinus + currentChipValue >= Character::GetInstance()->getMoney()){
            QMessageBox::information(nullptr, "Ошибка", "Не хватает денег для ставки");
            return;
        }
        currentBets[betNumber] += currentChipValue;

    }

    else {
            currentBets[betNumber] = currentChipValue;
        }

    moneyMinus += currentChipValue;

    qDebug() << moneyMinus;
    updateCurrentBetsLabel();
}

    void Casino::updateCurrentBetsLabel() {
        QString betsText = "Current Bets:\n";
        for (auto it = currentBets.constBegin(); it != currentBets.constEnd(); ++it) {
            betsText += "Number " + QString::number(it.key()) + ": " + QString::number(it.value()) + "\n";
        }
        currentBetsLabel->setText(betsText);
    }

    void Casino::updateChipValue(int index) {
        currentChipValue = chipValueComboBox->itemText(index).toInt();
    }

    void Casino::showResult() {
        QString resultText = QString("The ball landed on %1").arg(resultNumber);
        if (currentBets.contains(resultNumber)) {
            resultText += QString("\nYou won %1!").arg(currentBets[resultNumber] * 36);
            emit changeBalance(-1 * currentBets[resultNumber] * 36);
        } else {
            resultText += "\nYou lost!";
        }

        QMessageBox::information(this, "Roulette Result", resultText);
    }


    void Casino::drawRouletteWheel() {
        wheel = scene->addEllipse(-300, -300, 600, 600, QPen(), QBrush(QColor(255, 0, 0, 127)));
        scene->addLine(0, -310, 0, -290, QPen(Qt::red, 3, Qt::SolidLine, Qt::RoundCap));
    }

    void Casino::drawWheelSections() {
        int numSections = rouletteNumbers.size();
        double angleStep = 360.0 / numSections;

        for (int i = 0; i < numSections; ++i) {
            double angle = i * angleStep;
            QColor color;

            if (rouletteNumbers[i] == 0) {
                color = Qt::green;
            } else if (rouletteNumbers[i] % 2 == 0) {
                color = Qt::black;
            } else {
                color = Qt::red;
            }

            QGraphicsTextItem *textItem = scene->addText(QString::number(rouletteNumbers[i]));
            textItem->setDefaultTextColor(color);

            double textX = 250 * cos((angle - angleStep / 2) * M_PI / 180.0);
            double textY = 250 * sin((angle - angleStep / 2) * M_PI / 180.0);
            textItem->setPos(textX - textItem->boundingRect().width() / 2, textY - textItem->boundingRect().height() / 2);

            scene->addLine(0, 0, 300 * cos(angle * M_PI / 180.0), 300 * sin(angle * M_PI / 180.0), QPen(Qt::black));
        }
    }

    void Casino::on_spinButton_clicked() {

    if (animation->state() == QPropertyAnimation::Running) {
    return; // Prevent starting a new animation if the current one is still running
    }
    // Устанавливаем анимацию вращения для обертки колеса
    animation->setTargetObject(rotatableWheel);
    animation->setPropertyName("rotation");
    animation->setStartValue(0);
    animation->setEndValue(360 * 5); // 5 full rotations
    animation->setDuration(2000); // 2 seconds
    animation->setEasingCurve(QEasingCurve::OutCubic);

    animation->start();
    }

void Casino::setRotationAngle(int angle) {
    currentAngle = angle;
    updateWheel();
}

int Casino::rotationAngle() const {
    return currentAngle;
}

void Casino::backToPreviousScreen() {
emit OpenMainWindow();
    close();
}
