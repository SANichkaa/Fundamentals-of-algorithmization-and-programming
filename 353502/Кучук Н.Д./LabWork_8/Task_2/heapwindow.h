#ifndef HEAPWINDOW_H
#define HEAPWINDOW_H

#include <QWidget>
#include "heaparray.h"

class HeapWindow : public QWidget {
    Q_OBJECT

public:
    HeapWindow(QWidget *parent = nullptr);

private slots:
    void insertValue();
    void extractMax();

private:
    HeapArray heap;
    QLineEdit *input;
    QTextEdit *display;

    void updateDisplay();
};

#endif // HEAPWINDOW_H
