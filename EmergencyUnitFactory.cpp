#include "EmergencyUnitFactory.h"
#include "SecurityTeam.h"
#include "MedicalTeam.h"
#include "FacilitiesTeam.h"
#include "CentralDispatcher.h"
#include <iostream>

EmergencyUnitFactory::EmergencyUnitFactory() {}
EmergencyUnitFactory::~EmergencyUnitFactory() {}

ResponseUnit* EmergencyUnitFactory::createUnit(const std::string& type, const std::string& callsign, DispatcherMediator* mediator) {
    ResponseUnit* created = nullptr;

    if (type == "SECURITY") {
        created = new SecurityTeam(callsign, mediator);
    } else if (type == "MEDICAL") {
        created = new MedicalTeam(callsign, mediator);
    } else if (type == "FACILITIES") {
        created = new FacilitiesTeam(callsign, mediator);
    } else {
        std::cout << "[Factory Error] Unknown response unit type: " << type << "\n";
        return nullptr;
    }

    CentralDispatcher* dispatcher = dynamic_cast<CentralDispatcher*>(mediator);
    if (dispatcher && created) {
        dispatcher->registerColleague(created);
    }

    return created;
}   