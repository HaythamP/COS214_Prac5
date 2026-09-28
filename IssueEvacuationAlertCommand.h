#ifndef ISSUE_EVACUATION_ALERT_COMMAND_H
#define ISSUE_EVACUATION_ALERT_COMMAND_H

#include "Command.h"
#include <string>

class NotificationService;

class IssueEvacuationAlertCommand : public Command {
private:
    NotificationService* service;
    std::string zone;
    std::string notice;

public:
    IssueEvacuationAlertCommand(NotificationService* s, const std::string& z, const std::string& n);
    virtual ~IssueEvacuationAlertCommand();

    void execute() override;
    void undo() override;
};

#endif