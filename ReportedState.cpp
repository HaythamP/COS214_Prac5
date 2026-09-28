#include "ReportedState.h"
#include "ActiveState.h"
#include "Incident.h"
#include <iostream>

ReportedState::~ReportedState() {}

void ReportedState::escalate(Incident* context) {
    std::cout << "[State Transition] Incident verified and escalating from REPORTED to ACTIVE.\n";
    context->setState(new ActiveState());
}

void ReportedState::resolve(Incident* context) {
    // Demonstrates handling invalid runtime operation gracefully
    std::cout << "[ERROR: Invalid Operation] Cannot resolve an incident that hasn't been triage-activated.\n";
}

std::string ReportedState::getStateName() const { return "REPORTED"; }