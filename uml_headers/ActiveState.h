#ifndef ACTIVE_STATE_H
#define ACTIVE_STATE_H

#include "IncidentState.h"

class ActiveState : public IncidentState {
public:
    virtual ~ActiveState();
    void escalate(Incident* context) ;
    void resolve(Incident* context) ;
    std::string getStateName() const ;
};

#endif