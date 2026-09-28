#ifndef INCIDENT_COMMANDER_CONSOLE_H
#define INCIDENT_COMMANDER_CONSOLE_H

#include <vector>

class Command;

class IncidentCommanderConsole {
private:
    std::vector<Command*> history;

public:
    IncidentCommanderConsole();
    virtual ~IncidentCommanderConsole();

    void executeCommand(Command* cmd);
    void undoLastCommand();
};

#endif