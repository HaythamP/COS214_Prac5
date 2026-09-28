#ifndef DISPATCH_UNIT_COMMAND_H
#define DISPATCH_UNIT_COMMAND_H

#include "Command.h"
#include <string>

class ResponseUnit;

class DispatchUnitCommand : public Command {
private:
    ResponseUnit* unit;
    std::string destination;

public:
    DispatchUnitCommand(ResponseUnit* u, const std::string& dest);
    virtual ~DispatchUnitCommand();

    void execute() ;
    void undo() ;
};

#endif