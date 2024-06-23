#ifndef SORTING_H
#define SORTING_H
#include <QApplication>
#include <QCoreApplication>

class Sorting
{
public:
    Sorting();
    void heapSort(QList<int> *list);
    void quickSort(QList<int> * list, int low, int high);
    void mergeSort(QList<int> * list, int, int);
    int interpolationSearch(QList<int>* list);
    int binPow(int, int, int);
    void printList(const QList<int>* list);
    int binSearch(const QList<int>* list, int a);
private:
    void heapify(QList<int>* list, int n, int i);
    int partition(QList<int>* list, int low, int high);
    void merge( QList<int>* list, int left, int mid, int right);



};

#endif // SORTING_H
