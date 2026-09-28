#include "DispatchUnitCommand.h"
#include "ResponseUnit.h"
#include <iostream>

DispatchUnitCommand::DispatchUnitCommand(ResponseUnit* u, const std::string& dest)
    : unit(u), destination(dest) {}

DispatchUnitCommand::~DispatchUnitCommand() {}

void DispatchUnitCommand::execute() {
    if (unit) {
        unit->deploy(destination);
    }
}

void DispatchUnitCommand::undo() {
    std::cout << "[Command UNDO] Recalling unit from " << destination << ".\n";
}   