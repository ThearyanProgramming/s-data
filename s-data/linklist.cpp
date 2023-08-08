#include <iostream>


struct Student {
    int id;
    Student* next;
};

Student* addStudentToFront(int id, Student* head) {
    Student* newStudent = new Student;
    newStudent->id = id;
    newStudent->next = head;
    return newStudent;
}

Student* addStudentToMiddle(int id, int position, Student* head) {
    Student* newStudent = new Student;
    newStudent->id = id;

    if (position <= 1 || head == nullptr) {
        newStudent->next = head;
        return newStudent;
    }


    Student* current = head;
    int count = 1;
    while (current->next != nullptr && count < position - 1) {
        current = current->next;
        count++;
    }

    newStudent->next = current->next;
    current->next = newStudent;
    return head;
}


Student* removeStudent(int id, Student* head) {
    if (head == nullptr)
        return nullptr;


    if (head->id == id) {
        Student* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Student* current = head;
    while (current->next != nullptr && current->next->id != id) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Student* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    return head;
}


void displayStudents(Student* head) {
    Student* current = head;
    while (current != nullptr) {
        std::cout << "Student ID: " << current->id << std::endl;
        current = current->next;
    }
}


void deleteList(Student* head) {
    Student* current = head;
    while (current != nullptr) {
        Student* temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {
    Student* head = nullptr;
    int choice;

    do {
    
        std::cout << "Choose an option:\n"
                  << "1. Add a student to the front\n"
                  << "2. Add a student to the middle\n"
                  << "3. Remove a student\n"
                  << "4. Display students\n"
                  << "0. Exit\n";
        std::cin >> choice;

        switch (choice) {
            case 1: {
       
                int id;
                std::cout << "Enter student ID: ";
                std::cin >> id;
                head = addStudentToFront(id, head);
                break;
            }
            case 2: {
             
                int id, position;
                std::cout << "Enter student ID: ";
                std::cin >> id;
                std::cout << "Enter position to insert: ";
                std::cin >> position;
                head = addStudentToMiddle(id, position, head);
                break;
            }
            case 3: {
            
                int id;
                std::cout << "Enter student ID to remove: ";
                std::cin >> id;
                head = removeStudent(id, head);
                break;
            }case 4: {
             
                displayStudents(head);
                break;
            }
            case 0:
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);


    deleteList(head);
    return 0;
}