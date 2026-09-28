#ifndef CENTRAL_DISPATCHER_H
#define CENTRAL_DISPATCHER_H

#include "DispatcherMediator.h"
#include <vector>

class CentralDispatcher:public DispatcherMediator {
private:
    std::vector<ResponseUnit*> colleagues;

public:
    CentralDispatcher();
    virtual ~CentralDispatcher();

    void registerColleague(ResponseUnit* unit);
    void notify(ResponseUnit* sender,const std::string& eventCode,const std::string& details)override;
};

#endif