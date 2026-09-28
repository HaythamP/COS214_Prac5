#include "ActiveState.h"
#include "ResolvedState.h"
#include "Incident.h"
#include <iostream>

ActiveState::~ActiveState() {}

void ActiveState::escalate(Incident* context) {
    std::cout << "[State Info] Incident is already at maximum operational alert level (ACTIVE).\n";
}

void ActiveState::resolve(Incident* context) {
    std::cout << "[State Transition] Hazard neutralised. Incident moving from ACTIVE to RESOLVED.\n";
    context->setState(new ResolvedState());
}

std::string ActiveState::getStateName() const { return "ACTIVE"; }