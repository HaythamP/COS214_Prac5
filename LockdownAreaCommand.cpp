#include "LockdownAreaCommand.h"
#include "AccessControlSubsystem.h"

LockdownAreaCommand::LockdownAreaCommand(AccessControlSubsystem* ac, const std::string& bId)
    : accessControl(ac), buildingId(bId) {}

LockdownAreaCommand::~LockdownAreaCommand() {}

void LockdownAreaCommand::execute() {
    if (accessControl) {
        accessControl->lockDownBuilding(buildingId);
    }
}

void LockdownAreaCommand::undo() {
    if (accessControl) {
        accessControl->unlockBuilding(buildingId);
    }
}