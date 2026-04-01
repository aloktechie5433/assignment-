#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include "Assignment.h"

using namespace std;

class FileStorage;  // forward declaration

class TaskManager {
private:
    vector<Assignment> assignments;

public:
    void addAssignment(Assignment a);
    void listAssignments();
    void markComplete(int id);
    void deleteAssignment(int id);

    friend class FileStorage; // allow FileStorage access
};

#endif