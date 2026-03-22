#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include "Assignment.h"

class FileStorage; // forward declaration

class TaskManager {
private:
    vector<Assignment> assignments;

public:
    void addAssignment(const Assignment& a) {
        assignments.push_back(a);
    }

    void listAssignments() const {
        for (const auto& a : assignments) {
            a.display();
        }
    }

    void markAssignmentComplete(int id) {
        for (auto& a : assignments) {
            if (a.getId() == id) {
                a.markComplete();
                cout << "Marked as completed!\n";
                return;
            }
        }
        cout << "Assignment not found!\n";
    }

    vector<Assignment>& getAssignments() {
        return assignments;
    }

    friend class FileStorage;
};

#endif