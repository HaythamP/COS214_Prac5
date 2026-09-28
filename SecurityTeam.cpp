#include "SecurityTeam.h"
#include <iostream>

SecurityTeam::SecurityTeam(const std::string& sign, DispatcherMediator* med):ResponseUnit(sign,"SECURITY",med){}

SecurityTeam::~SecurityTeam(){}

void SecurityTeam::deploy(const std::string& location){
    std::cout<< "[SecurityTeam "<<callsign<<"] Deployed to secure "<<location <<".\n";
}

void SecurityTeam::receiveInstruction(const std::string& instruction){
    std::cout<<"[SecurityTeam "<<callsign << "] Order recieved: "<<instruction<< ".\n";
}