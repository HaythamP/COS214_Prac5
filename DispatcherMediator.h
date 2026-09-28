#ifndef DISPATCHER_MEDIATOR_H
#define DISPATCHER_MEDIATOR_H

#include <string>

class ResponseUnit;

class DispatcherMediator{
    public:
        virtual ~DispatcherMediator(){};
        virtual void notify(ResponseUnit* sender, const std::string& eventCode, const std::string& details)=0;
};

#endif