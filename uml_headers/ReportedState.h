#ifndef REPORTED_STATE_H
#define REPORTED_STATE_H

#include "IncidentState.h"

class ReportedState : public IncidentState {
public:
    virtual ~ReportedState();
    void escalate(Incident* context) ;
    void resolve(Incident* context) ;
    std::string getStateName() const ;
};

#endif