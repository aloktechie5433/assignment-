#include "FileStorage.h"
#include "TaskManager.h"

void FileStorage::saveAssignments(TaskManager& manager) {
    ofstream out(file);

    for (auto& a : manager.assignments) {
        out << a.toFileString() << endl;
    }

    out.close();
}

void FileStorage::loadAssignments(TaskManager& manager) {
    ifstream in(file);
    string line;

    while (getline(in, line)) {
        stringstream ss(line);
        string id, title, subject, deadline, completed;

        getline(ss, id, '|');
        getline(ss, title, '|');
        getline(ss, subject, '|');
        getline(ss, deadline, '|');
        getline(ss, completed, '|');

        Assignment a(stoi(id), title, subject, deadline);

        if (completed == "1") a.setCompleted(true);

        manager.addAssignment(a);
    }

    in.close();
}