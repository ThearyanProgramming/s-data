#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == MAX_SIZE - 1) {
        cout << "Queue is full. Cannot add a new element." << endl;
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "The queue is empty." << endl;
        return;
    }

    front++;
}

bool isEmpty() {
    return (front == -1 || front > rear);
}

bool isFull() {
    return (rear == MAX_SIZE - 1);
}

int main() {
    int element;
    char choice;

    cout << "Please choose an operation:\n";
    cout << "1. Enqueue (Add element)\n";
    cout << "2. Dequeue (Remove element)\n";
    cout << "3. Exit\n";

    while (true) {
        cin >> choice;
        switch (choice) {
            case '1':
                cout << "Enter the element you want to enqueue: ";
                cin >> element;
                enqueue(element);
                break;
            case '2':
                dequeue();
                break;
            case '3':
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << "Current queue: ";
        if (!isEmpty()) {
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
        } else {
            cout << "Empty";
        }
        cout << endl;
    }

    return 0;
}
