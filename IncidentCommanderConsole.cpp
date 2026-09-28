#include "IncidentCommanderConsole.h"
#include "Command.h"
#include <iostream>

IncidentCommanderConsole::IncidentCommanderConsole() {}

IncidentCommanderConsole::~IncidentCommanderConsole() {
    for (Command* cmd : history) {
        delete cmd;
    }
    history.clear();
}

void IncidentCommanderConsole::executeCommand(Command* cmd) {
    if (cmd) {
        cmd->execute();
        history.push_back(cmd);
    }
}

void IncidentCommanderConsole::undoLastCommand() {
    if (!history.empty()) {
        Command* last = history.back();
        last->undo();
        history.pop_back();
        delete last;
    } else {
        std::cout << "[Console] No operations in history to revert.\n";
    }
}