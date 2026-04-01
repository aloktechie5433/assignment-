#include "TaskManager.h"
#include <iostream>

using namespace std;

void TaskManager::addAssignment(Assignment a) {
    assignments.push_back(a);

void TaskManager::listAssignments() {
    for (auto &a : assignments) {
        a.display();
    }
}

void TaskManager::markComplete(int id) {
    for (auto &a : assignments) {
        if (a.getId() == id) {
            a.setCompleted(true);
            cout << "Marked as complete\n";
            return;
        }
    }
    cout << "Assignment not found\n";
}

void TaskManager::deleteAssignment(int id) {
    for (auto it = assignments.begin(); it != assignments.end(); ++it) {
        if (it->getId() == id) {
            assignments.erase(it);
            cout << "Deleted successfully\n";
            return;
        }
    }
    cout << "Assignment not found\n";
}