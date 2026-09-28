#include "EmergencyWorkflowFacade.h"
#include "AccessControlSubsystem.h"      
#include "NotificationService.h"
#include "IncidentCommanderConsole.h"
#include "LockdownAreaCommand.h"
#include "Incident.h"
#include <iostream>

EmergencyWorkflowFacade::EmergencyWorkflowFacade(AccessControlSubsystem* ac, NotificationService* ns, IncidentCommanderConsole* icc) : accessControl(ac), sirenService(ns), console(icc){}

EmergencyWorkflowFacade::~EmergencyWorkflowFacade() {}

void EmergencyWorkflowFacade::initiateCampusLockdown(const string& buildingId, Incident* incident){
    cout << "\n [FACADE] Initiating lockdown for " << buildingId << " \n";

    if (!console || !accessControl || !sirenService || !incident)
    {
        cout << "[FACADE ERROR] Lockdown aborted: a required subsytem or incident is missing. \n";
        return;
    }

    //step1
    console->executeCommand(new LockdownAreaCommand(accessControl, buildingId));

    //step2
    sirenService->sendAlert(1, "LOCKDOWN: SHELTER IS IN PLACE", buildingId);

    //step3
    incident->escalate();

    cout << "[FACADE] Lockdown workflow complete \n\n";
    
}

void EmergencyWorkflowFacade::resolveEmergency( const string& buildingId, Incident* incident){
    cout << "\n [FACADE] Resolving emergency for " <<buildingId << "\n";
    if(!accessControl || !sirenService || !incident){
        cout << "[FACADE ERROR] Resolution aborted, a required subsyrtem or incident is missing. \n";
        return;
    }

    incident->resolve();
    accessControl->unlockBuilding(buildingId);
    sirenService->sendAlert(3, "ALL CLEAR", buildingId);

    cout << "[FACADE] Resolution workflow complete \n\n";
}