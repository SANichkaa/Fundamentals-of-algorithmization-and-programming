#ifndef QUEUE_H
#define QUEUE_H

#include <ctime>
#include <cstdlib>
#include <QListWidget>


struct Node{
    int data;
        Node* prev, *next;

};

class Queue{
    private:
        Node* front;//указатель на начало очереди
        Node* rear;//указатель на конец очереди
        int size = 0;

    public:
        Queue() : front(nullptr), rear(nullptr){}

        void push_back(int value){
//добавление в конец очереди
            Node* newNode = new Node;
            newNode->data = value;
            newNode->next = nullptr;

            if (rear == nullptr){
//если очередь пуста, новый элемент становиться началом и концом
                newNode->prev = newNode;
                front = newNode;
            }
            else {
                newNode->prev = rear;
                rear->next = newNode;
            }
            rear = newNode;
            ++size;
        }

        void pop_front(){
            if(front == NULL) return;

            Node* ptr = front->next;//этот временный указатель будет вести на следующий после head
            if (ptr !=NULL)
                ptr->prev = NULL;
            else
                rear = NULL;

            delete front;
            front = ptr;
            --size;
        }

        int peek(int index) const {
            if (isEmpty() || index < 0 || index >= size) {
                throw "Invalid index";
            }
            Node* current = front;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            return current->data;
        }


        void clearing(){
            Node* current = front;
            while (current) {
                Node *term = current->next;
                delete current;
                current = term;
            }
            front = rear = nullptr;
            size = 0;
        }

        void FillQueueRandomly(int x){
            srand(time(0));
            for(int i = 0; i <x; ++i){
                int randomNumber = arc4random() %100;
                push_back(randomNumber);
            }
        }
        bool isEmpty() const {
            return size==0;
        }

        int GetSize() const {
            return size;
        }

        int findMax(){
            if (isEmpty())
                return 0;
            Node* current = front;
            int maxValue = current->data;

            while(current){
                if(current->data > maxValue)
                    maxValue = current->data;
                current = current->next;
            }
            return maxValue;
        }

        int findMin(){
            if (isEmpty())
                return 0;
            Node* current = front;
            int minValue = current->data;

            while(current){
                if(current->data > minValue)
                    minValue = current->data;
                current = current->next;
            }
            return minValue;
        }
//////////////////      НЕ ВСТАВЛЯЕТСЯ А ПРОСТО КОПИРУЕТСЯ ВМЕСТО 1 ПЕРЕДЕЛАТЬ->
        void insertDeque(QListWidget *QueueListWidget, Queue& queue1, Queue& queue2) {
            if (!queue1.front || !queue2.front) {
                return;
            }

            int maxValue = queue1.findMax();
            int minValue = queue1.findMin();

            Node* current = queue1.front;
            while (current) {
                if (current->data > minValue && current->data < maxValue) {
                    Node* temp = current->next;
                    current->next = queue2.front;
                    queue2.front->prev = current;
                    queue2.rear->next = temp;
                    if (temp) {
                        temp->prev = queue2.rear;
                    } else {
                        queue1.rear = queue2.rear;
                    }
                    current = temp;
                    queue2.front = queue2.rear = nullptr;
                } else {
                    current = current->next;
                }
            }
            QueueListWidget->clear();
            for (int i = 0; i < queue1.GetSize(); ++i) {
                int num = queue1.peek(i);
                QueueListWidget->addItem(QString::number(num));
            }
        }

};
#endif // QUEUE_H
