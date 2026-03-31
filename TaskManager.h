#pragma once
#include <vector>
#include <string>
#include "Task.h"
#include "FileStorage.h"

using namespace std;

class TaskManager {
    friend class FileStorage;
private:
    vector<Assignment> assignments;

public:
    void addAssignment(Assignment a);
    void listAssignments();
    void markComplete(int id);
    void deleteAssignment(int id); 
};