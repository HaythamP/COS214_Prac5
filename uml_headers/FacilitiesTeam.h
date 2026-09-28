#ifndef FACILITIES_TEAM_H
#define FACILITIES_TEAM_H
#include "ResponseUnit.h"

class FacilitiesTeam:public ResponseUnit{
    public:
        FacilitiesTeam(const std::string& sign, DispatcherMediator* med);
        virtual ~FacilitiesTeam();
        void deploy(const std::string& location) ;
        void receiveInstruction(const std::string& instruction) ;
};

#endif