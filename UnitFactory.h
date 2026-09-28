#ifndef UNIT_FACTORY_H
#define UNIT_FACTORY_H

#include <string>

class ResponseUnit;
class DispatcherMediator;

class UnitFactory {
public:
    virtual ~UnitFactory() {}
    virtual ResponseUnit* createUnit(const std::string& type, const std::string& callsign, DispatcherMediator* mediator) = 0;
};

#endif