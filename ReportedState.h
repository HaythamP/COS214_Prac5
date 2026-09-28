#ifndef REPORTED_STATE_H
#define REPORTED_STATE_H

#include "IncidentState.h"

class ReportedState : public IncidentState {
public:
    virtual ~ReportedState();
    void escalate(Incident* context) override;
    void resolve(Incident* context) override;
    std::string getStateName() const override;
};

#endif