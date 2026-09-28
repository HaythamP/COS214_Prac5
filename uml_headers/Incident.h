#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>

class IncidentState;

class Incident {
private:
    std::string incidentId;
    std::string location;
    std::string description;
    IncidentState* currentState;

public:
    Incident(const std::string& id, const std::string& loc, const std::string& desc);
    virtual ~Incident();

    void setState(IncidentState* newState);
    void escalate();
    void resolve();
    void displayStatus() const;
};

#endif