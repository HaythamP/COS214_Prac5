#ifndef SECURITY_TEAM_H
#define SECURITY_TEAM_H

#include "ResponseUnit.h"
class SecurityTeam: public ResponseUnit{
    public:
        SecurityTeam(const std::string& sign, DispatcherMediator* med);
        virtual ~SecurityTeam();

        void deploy(const std::string& location) ;
        void receiveInstruction(const std::string& instruction) ;
};
#endif