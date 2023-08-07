#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

int queue[MAX_SIZE];
int front = 0;
int rear = 0;

bool isEmpty() {
    return front == rear;
}

bool isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full. Cannot add a new element." << endl;
        return;
    }

    queue[rear] = value;
    rear = (rear + 1) % MAX_SIZE;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot remove an element." << endl;
        return;
    }

    cout << "Removed element: " << queue[front] << endl;
    front = (front + 1) % MAX_SIZE;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Current queue: ";
    int i = front;
    while (i != rear) {
        cout << queue[i] << " ";
        i = (i + 1) % MAX_SIZE;
    }
    cout << endl;
}

int main() {
    int choice, value;

    while (true) {
        cout << "\nSelect an option:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
