#ifndef RESOLVED_STATE_H
#define RESOLVED_STATE_H

#include "IncidentState.h"

class ResolvedState : public IncidentState {
public:
    virtual ~ResolvedState();
    void escalate(Incident* context) ;
    void resolve(Incident* context) ;
    std::string getStateName() const ;
};

#endif