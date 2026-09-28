#include "Incident.h"
#include "IncidentState.h"
#include "ReportedState.h"
#include <iostream>

Incident::Incident(const std::string& id, const std::string& loc, const std::string& desc)
    : incidentId(id), location(loc), description(desc) {
    currentState = new ReportedState();
}

Incident::~Incident() {
    delete currentState;
}

void Incident::setState(IncidentState* newState) {
    if (currentState) {
        delete currentState;
    }
    currentState = newState;
}

void Incident::escalate() {
    if (currentState) {
        currentState->escalate(this);
    }
}

void Incident::resolve() {
    if (currentState) {
        currentState->resolve(this);
    }
}

void Incident::displayStatus() const {
    std::cout << "[Incident #" << incidentId << "] Location: " << location 
              << " | Details: " << description 
              << " | State: " << (currentState ? currentState->getStateName() : "NONE") << "\n";
}