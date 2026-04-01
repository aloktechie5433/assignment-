#include "CLI/CLI.hpp"
#include "TaskManager.h"
#include "FileStorage.h"

#include "commands/add_command.hpp"
#include "commands/list_command.hpp"
#include "commands/complete_command.hpp"
#include "commands/delete_command.hpp"

int main(int argc, char* argv[]) {

    CLI::App app{"Deadline Manager CLI"};

    TaskManager manager;
    FileStorage storage;

    storage.loadAssignments(manager);

    AddCommand addCmd(manager, storage);
    ListCommand listCmd(manager);
    CompleteCommand completeCmd(manager, storage);
    DeleteCommand deleteCmd(manager, storage);

    addCmd.setup(app);
    listCmd.setup(app);
    completeCmd.setup(app);
    deleteCmd.setup(app);

    CLI11_PARSE(app, argc, argv);

    return 0;
}