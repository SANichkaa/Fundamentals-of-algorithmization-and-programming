#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      text("strangerhabitguessincreasedrelativelyneedmistakelockexactlybox"),
      isWork(false),
      correctSymbol(0),
      uncorrectSymbol(0) {
  ui->setupUi(this);
  file = new FileProcessing();
  setArrayButton();
  keyboardIndex = 0;
  updateLabel();
  updateTimer = new QTimer(this);
  timer = new QTimer(this);
  setArrayNumberKeyboardSymbols();
  setColorButtons();
  setNewKeyboard(0, false, false);
  QFont font = ui->label->font();
  font.setPointSize(FONT_SIZE);
  font.setBold(true);
  ui->label->setFont(font);
  ui->comboBox->addItem("English");
  ui->comboBox->addItem("Russian");
  ui->comboBox->addItem("German");
  ui->comboBox->addItem("French");
  ui->comboBox->addItem("Hebrew");
  connect(updateTimer, &QTimer::timeout, this, &MainWindow::updateTime);
  QObject::connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this,
                   SLOT(setNewKeyboard(int)));
  QObject::connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this,
                   SLOT(updateText(int)));
  connect(ui->pushButton_65, &QPushButton::clicked, this,
          &MainWindow::updateLabel);
  connect(ui->pushButton_66, &QPushButton::clicked, this, &MainWindow::start);
  connect(ui->pushButton_67, &QPushButton::clicked, this, &MainWindow::finish);
  updateTimer->start(TIMER_FREEZE);
  updateLabel();
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::updateText(int number) {
  switch (number) {
    case 0: {
      text = "strangerhabitguessincreasedrelativelyneedmistakelockexactlybox";
      break;
    }
    case 1: {
      text = "ЛавфеуАфавомркуАекнрмывпцуекнПмсчркнкыяпакнПркупитолуогеимсуппнн";
      break;
    }
    case 2: {
      text =
          "FamilieMüllerplantihrenUrlaubSiegehtineinReisebüroundlässtsichvon";
      break;
    }
    case 3: {
      text =
          "JeappellenglicaSummerj'"
          "aiansjecanadiennemafamilletmoivonsdanslesudFrance.";
      break;
    }
    case 4: {
      text = "זוגעינייםעצובות,עינייך(=עיניים שלך)הטובותאומרותהכהלילה";
      break;
    }
  }
}
void MainWindow::setArrayButton() {
  arrayButtons = {ui->pushButton,    ui->pushButton_2,  ui->pushButton_3,
                  ui->pushButton_4,  ui->pushButton_5,  ui->pushButton_6,
                  ui->pushButton_7,  ui->pushButton_8,  ui->pushButton_9,
                  ui->pushButton_10, ui->pushButton_11, ui->pushButton_12,
                  ui->pushButton_13, ui->pushButton_14, ui->pushButton_15,
                  ui->pushButton_16, ui->pushButton_17, ui->pushButton_18,
                  ui->pushButton_19, ui->pushButton_20, ui->pushButton_21,
                  ui->pushButton_22, ui->pushButton_23, ui->pushButton_24,
                  ui->pushButton_25, ui->pushButton_26, ui->pushButton_27,
                  ui->pushButton_28, ui->pushButton_29, ui->pushButton_30,
                  ui->pushButton_31, ui->pushButton_32, ui->pushButton_33,
                  ui->pushButton_34, ui->pushButton_35, ui->pushButton_36,
                  ui->pushButton_37, ui->pushButton_38, ui->pushButton_39,
                  ui->pushButton_40, ui->pushButton_41, ui->pushButton_42,
                  ui->pushButton_43, ui->pushButton_44, ui->pushButton_45,
                  ui->pushButton_46, ui->pushButton_47, ui->pushButton_48,
                  ui->pushButton_49, ui->pushButton_50, ui->pushButton_51,
                  ui->pushButton_52, ui->pushButton_53, ui->pushButton_54,
                  ui->pushButton_55, ui->pushButton_56, ui->pushButton_57,
                  ui->pushButton_58, ui->pushButton_59, ui->pushButton_60,
                  ui->pushButton_61, ui->pushButton_62, ui->pushButton_63,
                  ui->pushButton_64};
  for (int i = 0; i < arrayButtons.size(); i++) {
    //arrayButtons[i]->setEnabled(false);
    arrayButtons[i]->setStyleSheet("color: black;");
  }
}

void MainWindow::setNewKeyboard(int index, bool isShift, bool isCaps) {
  QVector<QString> keyboard;
  keyboardIndex = index;
  switch (index) {
    case 0: {
      keyboard = Keyboard::getEnglishKeyboard(isShift, isCaps);
      break;
    }
    case 1: {
      keyboard = Keyboard::getRussianKeyboard(isShift, isCaps);
      break;
    }
    case 2: {
      keyboard = Keyboard::getGermanKeyboard(isShift, isCaps);
      break;
    }
    case 3: {
      keyboard = Keyboard::getFranchKeyboard(isShift, isCaps);
      break;
    }
    case 4: {
      keyboard = Keyboard::getHebrewKeyboard(isShift, isCaps);
      break;
    }
  }
  for (int i = 0; i < arrayButtons.size(); i++) {
    arrayButtons.at(i)->setText(keyboard.at(i));
  }
  updateLabel();
}

void MainWindow::updateTime() {
  if (isWork == true) {
    int elapsed = time.elapsed();
    QString timeString = QString::number(elapsed / DENOMINATOR_SIZE, 'f', 2);
    ui->label_2->setText(timeString);
  } else {
    ui->label_2->setText("00:00");
  }
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
  int code = event->nativeScanCode();
  int numberButton = getNumberButton(code);
  if (!(code == 50 || code == 62 || code == 66)) {
    uncorrectSymbol++;
  }
  if (numberButton != -1) {
    arrayButtons[numberButton]->setStyleSheet("background-color: brown;");
    QString clickButton = event->text();
    if (isWork && text.size() != 0 && clickButton == (QString)text.at(0)) {
      text.remove(0, 1);
      correctSymbol++;
    }

    if (text.size() == 0) {
      finish();
    }
  }
  updateLabel();

  if (code == NUMBER_CAPSLOCK) {
    isCapsPress = !isCapsPress;
  }
  updateLabel();
  bool isLetter = event->text()[0].isLetter();
  bool isUpper = event->text()[0].isUpper();
  bool shiftPressed =
      QApplication::keyboardModifiers().testFlag(Qt::ShiftModifier);

  if (isLetter && ((isUpper && !shiftPressed) || (!isUpper && shiftPressed))) {
    isCapsPress = true;
  }
  bool isShift = false;
  if (code == FIRST_NUMBER_SHIFT || code == SECOND_NUMBER_SHIFT) {
    isShift = true;
  }
  updateLabel();
  setNewKeyboard(keyboardIndex, isShift, isCapsPress);
}
void MainWindow::keyReleaseEvent(QKeyEvent* event) {
  if (event->nativeScanCode() == FIRST_NUMBER_SHIFT ||
      event->nativeScanCode() == SECOND_NUMBER_SHIFT) {
    setNewKeyboard(keyboardIndex, false, isCapsPress);
  }
  setColorButton(event->nativeScanCode());
  return;
}

int MainWindow::getNumberButton(int code) {
  for (int i = 0; i < arrayNumberKeyboardSymbols.size(); i++) {
    if (arrayNumberKeyboardSymbols[i] == code) {
      return i;
    }
  }
  return -1;
}

void MainWindow::setColorButtons() {
  for (int i = 0; i < RED_COLOR_KEYS.size(); i++) {
    arrayButtons[RED_COLOR_KEYS[i]]->setStyleSheet("background-color: red;");
  }
  for (int i = 0; i < BLUE_COLOR_KEYS.size(); i++) {
    arrayButtons[BLUE_COLOR_KEYS[i]]->setStyleSheet("background-color: blue;");
  }
  for (int i = 0; i < ORANGE_COLOR_KEYS.size(); i++) {
    arrayButtons[ORANGE_COLOR_KEYS[i]]->setStyleSheet(
        "background-color: orange;");
  }
  for (int i = 0; i < YELLOW_COLOR_KEYS.size(); i++) {
    arrayButtons[YELLOW_COLOR_KEYS[i]]->setStyleSheet(
        "background-color: yellow;");
  }
  for (int i = 0; i < MAGENTA_COLOR_KEYS.size(); i++) {
    arrayButtons[MAGENTA_COLOR_KEYS[i]]->setStyleSheet(
        "background-color: magenta;");
  }
  for (int i = 0; i < GREY_COLOR_KEYS.size(); i++) {
    arrayButtons[GREY_COLOR_KEYS[i]]->setStyleSheet(
        "background-color: lightGrey;");
  }
  for (int i = 0; i < CYAN_COLOR_KEYS.size(); i++) {
    arrayButtons[CYAN_COLOR_KEYS[i]]->setStyleSheet("background-color: cyan;");
  }
  for (int i = 0; i < PINK_COLOR_KEYS.size(); i++) {
    arrayButtons[PINK_COLOR_KEYS[i]]->setStyleSheet(
        "background-color: hotPink;");
  }
}

void MainWindow::setArrayNumberKeyboardSymbols() {
  arrayNumberKeyboardSymbols = {
      49, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 0,  24,
      25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 51, 66, 38, 39, 40,
      41, 42, 43, 44, 45, 46, 47, 48, 36, 50, 52, 53, 54, 55, 56, 57,
      58, 59, 60, 61, 62, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0};
}

void MainWindow::updateLabel() {
  ui->label->setText(text);
  double persent = getPersent();
  ui->label_3->setText(QString::number(persent) + "%");
}

void MainWindow::on_pushButton_65_clicked() {
  file->setFilePath();
  text = file->getText();
}

void MainWindow::setColorButton(int index) {
  index = find(arrayNumberKeyboardSymbols, index);
  if (find(RED_COLOR_KEYS, index) != -1) {
    arrayButtons[RED_COLOR_KEYS[find(RED_COLOR_KEYS, index)]]->setStyleSheet(
        "background-color: red;");
  }
  if (find(BLUE_COLOR_KEYS, index) != -1) {
    arrayButtons[BLUE_COLOR_KEYS[find(BLUE_COLOR_KEYS, index)]]->setStyleSheet(
        "background-color: blue;");
  }
  if (find(ORANGE_COLOR_KEYS, index) != -1) {
    arrayButtons[ORANGE_COLOR_KEYS[find(ORANGE_COLOR_KEYS, index)]]
        ->setStyleSheet("background-color: orange;");
  }
  if (find(YELLOW_COLOR_KEYS, index) != -1) {
    arrayButtons[YELLOW_COLOR_KEYS[find(YELLOW_COLOR_KEYS, index)]]
        ->setStyleSheet("background-color: yellow;");
  }
  if (find(MAGENTA_COLOR_KEYS, index) != -1) {
    arrayButtons[MAGENTA_COLOR_KEYS[find(MAGENTA_COLOR_KEYS, index)]]
        ->setStyleSheet("background-color: magenta;");
  }
  if (find(GREY_COLOR_KEYS, index) != -1) {
    arrayButtons[GREY_COLOR_KEYS[find(GREY_COLOR_KEYS, index)]]->setStyleSheet(
        "background-color: lightgrey;");
  }
  if (find(CYAN_COLOR_KEYS, index) != -1) {
    arrayButtons[CYAN_COLOR_KEYS[find(CYAN_COLOR_KEYS, index)]]->setStyleSheet(
        "background-color: cyan;");
  }
  if (find(PINK_COLOR_KEYS, index) != -1) {
    arrayButtons[PINK_COLOR_KEYS[find(PINK_COLOR_KEYS, index)]]->setStyleSheet(
        "background-color: hotPink;");
  }
}

int MainWindow::find(QVector<int> arr, int value) {
  for (int i = 0; i < arr.size(); i++) {
    if (value == arr[i])
      return i;
  }
  return -1;
}

void MainWindow::start() {
  uncorrectSymbol = 0;
  correctSymbol = 0;
  QMessageBox messageBox;
  time.restart();
  isWork = true;
}

void MainWindow::finish() {
  isWork = false;
  int elapsed = time.elapsed();
  QString timeString = QString::number(elapsed / DENOMINATOR_SIZE, 'f', 2);
  double persent = getPersent();
  ui->label_2->setText("00:00");
  ui->label_3->setText("0%");
  QMessageBox::information(
      nullptr, "Information",
      ("Время выполнения: " + timeString +
       "\nПроцент коррестности: " + QString::number(persent) + "%"));
  uncorrectSymbol = 0;
  correctSymbol = 0;
}

double MainWindow::getPersent() {
  if (uncorrectSymbol == 0) {
    return 0;
  }
  return (double)correctSymbol / uncorrectSymbol * PERCENT_NUMBER;
}
