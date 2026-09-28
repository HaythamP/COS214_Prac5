#ifndef MEDICAL_TEAM_H
#define MEDICAL_TEAM_H

#include "ResponseUnit.h"
class MedicalTeam: public ResponseUnit{
    public:
        MedicalTeam(const std::string& sign, DispatcherMediator* med);
        virtual ~MedicalTeam();
        void deploy(const std::string& location) ;
        void receiveInstruction(const std::string& instruction) ;
};

#endif