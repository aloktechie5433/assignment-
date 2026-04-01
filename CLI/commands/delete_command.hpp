#pragma once
#include "../icommand.hpp"
#include "../TaskManager.h"
#include "../FileStorage.h"

class DeleteCommand : public ICommand {
public:
    DeleteCommand(TaskManager &manager, FileStorage &storage)
        : manager(manager), storage(storage) {}

    void setup(CLI::App &app) override {
        auto sub = app.add_subcommand("delete", "Delete assignment");

        sub->add_option("id", id)->required();

        sub->callback([this]() { execute(); });
    }

private:
    TaskManager &manager;
    FileStorage &storage;
    int id;

    void execute() {
        manager.deleteAssignment(id);
        storage.saveAssignments(manager);
    }
};