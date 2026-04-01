#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
using namespace std;

class Task {
protected:
    int id;
    string title;
    bool completed;

public:
    Task(int id, string title)
        : id(id), title(title), completed(false) {}

    virtual ~Task() {}

    int getId() {
        return id;
    }

    bool isCompleted() {
        return completed;
    }

    void setCompleted(bool status) {
        completed = status;
    }

    virtual void display() {
        cout << "[" << (completed ? "✔" : "✘") << "] "
             << id << " - " << title << endl;
    }
};

#endif