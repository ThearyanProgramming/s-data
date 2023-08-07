#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

int stack[MAX_SIZE];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX_SIZE - 1;
}

void push(int value) {
    if (isFull()) {
        cout << "Stack is full. Cannot add a new element." << endl;
        return;
    }

    top++;
    stack[top] = value;
}

void pop() {
    if (isEmpty()) {
        cout << "Stack is empty. Cannot remove an element." << endl;
        return;
    }

    cout << "Removed element: " << stack[top] << endl;
    top--;
}

void display() {
    if (isEmpty()) {
        cout <<"\n" << "Stack is empty." <<"\n" endl;
        return;
    }

    cout << "Current stack: ";
    for (int i = top; i >= 0; i--) {
        cout <<"\n" << stack[i] << "\n";
    }
    cout << endl;
}

int main() {
    int choice, value;

    while (true) {
        cout << "\nSelect an option:\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
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
