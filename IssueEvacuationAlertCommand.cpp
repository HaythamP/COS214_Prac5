#include "IssueEvacuationAlertCommand.h"
#include "NotificationService.h"
#include <iostream>

IssueEvacuationAlertCommand::IssueEvacuationAlertCommand(NotificationService* s, const std::string& z, const std::string& n)
    : service(s), zone(z), notice(n) {}

IssueEvacuationAlertCommand::~IssueEvacuationAlertCommand() {}

void IssueEvacuationAlertCommand::execute() {
    if (service) {
        service->sendAlert(1, notice, zone);
    }
}

void IssueEvacuationAlertCommand::undo() {
    std::cout << "[Command UNDO] Cancelling broadcast alert in zone " << zone << ".\n";
}