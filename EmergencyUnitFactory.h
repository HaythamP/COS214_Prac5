#ifndef EMERGENCY_UNIT_FACTORY_H
#define EMERGENCY_UNIT_FACTORY_H

#include "UnitFactory.h"

class EmergencyUnitFactory : public UnitFactory {
public:
    EmergencyUnitFactory();
    virtual ~EmergencyUnitFactory();

    ResponseUnit* createUnit(const std::string& type, const std::string& callsign, DispatcherMediator* mediator) override;
};

#endif