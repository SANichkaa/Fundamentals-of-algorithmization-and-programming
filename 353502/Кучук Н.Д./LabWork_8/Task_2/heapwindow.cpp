#include "HeapWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QString>
#include <QMessageBox>

HeapWindow::HeapWindow(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *inputLayout = new QHBoxLayout();

    input = new QLineEdit(this);
    QPushButton *insertButton = new QPushButton("Insert", this);
    QPushButton *extractButton = new QPushButton("Extract Max", this);

    inputLayout->addWidget(input);
    inputLayout->addWidget(insertButton);
    inputLayout->addWidget(extractButton);

    display = new QTextEdit(this);
    display->setReadOnly(true);

    mainLayout->addLayout(inputLayout);
    mainLayout->addWidget(display);

    connect(insertButton, &QPushButton::clicked, this, &HeapWindow::insertValue);
    connect(extractButton, &QPushButton::clicked, this, &HeapWindow::extractMax);

    updateDisplay();
}

void HeapWindow::insertValue() {
    bool ok;
    int value = input->text().toInt(&ok);
    if (ok) {
        heap.insert(value);
        updateDisplay();
    } else {
        QMessageBox::warning(this, "Input Error", "Please enter a valid integer.");
    }
}

void HeapWindow::extractMax() {
    try {
        int maxValue = heap.extractMax();
        updateDisplay();
        QMessageBox::information(this, "Extracted Max", QString::number(maxValue));
    } catch (const std::runtime_error &e) {
        QMessageBox::warning(this, "Heap Error", e.what());
    }
}

void HeapWindow::updateDisplay() {
    QStringList list;
    for (int i : heap.data) {
        list << QString::number(i);
    }
    display->setText(list.join(", "));
}
