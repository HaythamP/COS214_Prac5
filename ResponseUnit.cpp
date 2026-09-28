#include "ResponseUnit.h"
#include "DispatcherMediator.h"

ResponseUnit::ResponseUnit(const std::string& sign, const std::string& t, DispatcherMediator* med):callsign(sign),type(t),mediator(med){}
ResponseUnit::~ResponseUnit(){}

void ResponseUnit::reportStatus(const std::string& eventCode, const std::string& details){
    if(mediator){
        mediator->notify(this,eventCode,details);
    }

}

std::string ResponseUnit::getCallsign() const { return callsign;}
std::string ResponseUnit::getType() const { return type;}