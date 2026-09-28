#include "ResolvedState.h"
#include "Incident.h"
#include <iostream>

ResolvedState::~ResolvedState() {}

void ResolvedState::escalate(Incident* context) {
    std::cout << "[ERROR: Invalid Operation] Cannot re-escalate an archived/resolved incident.\n";
}

void ResolvedState::resolve(Incident* context) {
    std::cout << "[State Info] Incident is already closed and resolved.\n";
}

std::string ResolvedState::getStateName() const { return "RESOLVED"; }