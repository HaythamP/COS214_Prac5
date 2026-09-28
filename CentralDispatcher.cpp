#include "CentralDispatcher.h"
#include "ResponseUnit.h"
#include <iostream>

CentralDispatcher::CentralDispatcher() {}
CentralDispatcher::~CentralDispatcher() {}

void CentralDispatcher::registerColleague(ResponseUnit* unit) {
    if (unit){
        colleagues.push_back(unit);
    }
}

void CentralDispatcher::notify(ResponseUnit* sender,const std::string& eventCode,const std::string& details) {
    std::cout << "[CentralDispatcher] Routing event: '"<<eventCode<<"' from "<<(sender?sender->getCallsign():"UNKNOWN") << "\n";
    
    for (ResponseUnit* unit:colleagues) {
        if (unit!=sender){
            if (eventCode=="TOXIC_HAZARD" && (unit->getType()=="MEDICAL" || unit->getType()=="FACILITIES")) {
                unit->receiveInstruction("DEPLOY_HAZMAT_PROTECTION at " + details);
            } else if (eventCode=="HOSTILE_BREACH" && unit->getType()=="SECURITY") {
                unit->receiveInstruction("SEAL_PERIMETER at " + details);
            } else if (eventCode=="STRUCTURAL_COLLAPSE" && unit->getType()=="FACILITIES") {
                unit->receiveInstruction("ISOLATE_GAS_AND_POWER at " + details);
            }
        }
    }
}