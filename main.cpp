#include <iostream>
#include "TaskManager.h"
#include "FileStorage.h"

using namespace std;

int main() {
    TaskManager manager;
    FileStorage storage;

    storage.loadAssignments(manager);

    int choice;

    while (true) {
        cout << "\n1. Add Assignment\n2. List Assignments\n3. Mark Complete\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string title, subject, deadline;

            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter Title: ";
            getline(cin, title);

            cout << "Enter Subject: ";
            getline(cin, subject);

            cout << "Enter Deadline: ";
            getline(cin, deadline);

            manager.addAssignment(Assignment(id, title, subject, deadline));
        }
        else if (choice == 2) {
            manager.listAssignments();
        }
        else if (choice == 3) {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            manager.markAssignmentComplete(id);
        }
        else if (choice == 4) {
            storage.saveAssignments(manager);
            cout << "Data saved. Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}