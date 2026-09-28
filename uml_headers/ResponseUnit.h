#ifndef RESPONSE_UNIT_H
#define RESPONSE_UNIT_H

#include <string>

class DispatcherMediator;

class ResponseUnit{
    protected:
        std::string callsign;
        std::string type;
        DispatcherMediator* mediator;
    public:
        ResponseUnit(const std::string& sign, const std::string& t, DispatcherMediator* med);
        virtual ~ResponseUnit();
        virtual void deploy(const std::string& location)=0;
        virtual void receiveInstruction(const std::string& instruction)=0;
        virtual void reportStatus(const std::string& eventCode, const std::string& details);

        std::string getCallsign() const;
        std::string getType() const;
};


#endif