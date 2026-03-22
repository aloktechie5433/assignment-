#ifndef TASK_H
#define TASK_H

#include <iostream>
using namespace std;

class Task {
protected:
    int id;
    string title;
    bool completed;

public:
    Task(int i = 0, string t = "") {
        id = i;
        title = t;
        completed = false;
    }

    virtual ~Task() {}

    void markComplete() {
        completed = true;
    }

    bool isCompleted() const {
        return completed;
    }

    int getId() const {
        return id;
    }

    string getTitle() const {
        return title;
    }

    virtual void display() const {
        cout << "ID: " << id << "\nTitle: " << title
             << "\nStatus: " << (completed ? "Completed" : "Pending") << endl;
    }
};

#endif