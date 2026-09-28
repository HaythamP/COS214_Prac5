#ifndef RESOLVED_STATE_H
#define RESOLVED_STATE_H

#include "IncidentState.h"

class ResolvedState : public IncidentState {
public:
    virtual ~ResolvedState();
    void escalate(Incident* context) override;
    void resolve(Incident* context) override;
    std::string getStateName() const override;
};

#endif