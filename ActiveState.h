#ifndef ACTIVE_STATE_H
#define ACTIVE_STATE_H

#include "IncidentState.h"

class ActiveState : public IncidentState {
public:
    virtual ~ActiveState();
    void escalate(Incident* context) override;
    void resolve(Incident* context) override;
    std::string getStateName() const override;
};

#endif