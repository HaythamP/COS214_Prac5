#ifndef INCIDENT_STATE_H
#define INCIDENT_STATE_H

#include <string>

class Incident;

class IncidentState {
public:
    virtual ~IncidentState() {}
    virtual void escalate(Incident* context) = 0;
    virtual void resolve(Incident* context) = 0;
    virtual std::string getStateName() const = 0;
};

#endif