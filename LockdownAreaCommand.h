#ifndef LOCKDOWN_AREA_COMMAND_H
#define LOCKDOWN_AREA_COMMAND_H

#include "Command.h"
#include <string>

class AccessControlSubsystem;

class LockdownAreaCommand : public Command {
private:
    AccessControlSubsystem* accessControl;
    std::string buildingId;

public:
    LockdownAreaCommand(AccessControlSubsystem* ac, const std::string& bId);
    virtual ~LockdownAreaCommand();

    void execute() override;
    void undo() override;
};

#endif