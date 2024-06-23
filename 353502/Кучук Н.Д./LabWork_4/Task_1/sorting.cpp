#include "sorting.h"
#include <QThread>
#include <QtDebug>

Sorting::Sorting() {}

void Sorting::heapSort(QList<int> *list)
{
    int n = list->size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(list, n, i);

    for (int i = n - 1; i >= 0; i--) {
        qSwap((*list)[0], (*list)[i]);
        QCoreApplication::processEvents();
        heapify(list, i, 0);
    }
}

void Sorting::quickSort(QList<int> *list, int low, int high)
{
    if (low < high) {
        int pi = partition(list, low, high);
        quickSort(list, low, pi - 1);
        quickSort(list, pi + 1, high);
    }
}

void Sorting::mergeSort(QList<int> *list, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(list, left, mid);
        mergeSort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}

int Sorting::binPow(int a, int b, int p)
{
    a %= p;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

void Sorting::printList(const QList<int> *list)
{
    for (int i : *list)
        qDebug() << i;
}

int Sorting::binSearch(const QList<int> *list, int a)
{
    int left = 0;
    int right = list->size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if ((*list)[mid] == a)
            return mid;
        if ((*list)[mid] < a)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void Sorting::heapify(QList<int> *list, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && list->at(left) > list->at(largest))
        largest = left;

    if (right < n && list->at(right) > list->at(largest))
        largest = right;

    if (largest != i) {
        qSwap((*list)[i], (*list)[largest]);
        QCoreApplication::processEvents();
        heapify(list, n, largest);
    }
}

int Sorting::partition(QList<int> *list, int low, int high)
{
    int pivot = (*list)[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if ((*list)[j] < pivot) {
            i++;
            qSwap((*list)[i], (*list)[j]);
            QCoreApplication::processEvents();
        }
    }
    qSwap((*list)[i + 1], (*list)[high]);
    QCoreApplication::processEvents();
    return (i + 1);
}

void Sorting::merge(QList<int> *list, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (i = 0; i < n1; i++){
        L[i] = (*list)[left + i];
         QCoreApplication::processEvents();
    }

    for (j = 0; j < n2; j++){
        R[j] = (*list)[mid + 1 + j];
         QCoreApplication::processEvents();
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            (*list)[k] = L[i];
            i++;
             QCoreApplication::processEvents();
        } else {
            (*list)[k] = R[j];
            j++;
             QCoreApplication::processEvents();
        }
        k++;
    }

    while (i < n1) {
        (*list)[k] = L[i];
        i++;
        k++;
         QCoreApplication::processEvents();
    }

    while (j < n2) {
        (*list)[k] = R[j];
        j++;
        k++;
         QCoreApplication::processEvents();
    }
}
