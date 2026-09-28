#include "AccessControlSubsystem.h"
#include <iostream>

AccessControlSubSystem::AccessControlSubSystem(){}

AccessControlSubSystem::~AccessControlSubSystem(){}

string AccessControlSubSystem::levelName(AccessLevel lvl){
    switch (lvl)
    {
    case LOCKED:
        return "LOCKED";
        break;
    case RESTRICTED:
        return "RESTRICTED";
        break;
    case OPEN:
        return "OPEN";
        break;

    default:
        return "UNKNOWN";
        break;
    }
}

AccessControlSubSystem::AccessLevel AccessControlSubSystem::getAccessLevel(const string& buildingId) const{
    map<string, AccessLevel>::const_iterator i = buildingAccess.find(buildingId);
    return(i != buildingAccess.end()) ? i->second : OPEN;
}

bool AccessControlSubSystem::isLocked(const string& buildingId) const{
    return getAccessLevel(buildingId) == LOCKED;
}

bool AccessControlSubSystem::lockDownBuilding(const string& buildingId){
    if (buildingId.empty())
    {
        cout << "[AccessControl] ERROR: Cannot lock a building with no ID. \n";
        return false;
    }
    if (isLocked(buildingId))
    {
        cout << "[AccessControl] " << buildingId << " is already LOCKED. No changes made.\n";
        return false;
    }

    buildingAccess[buildingId] = LOCKED;
    cout << "[AccessControl] " << buildingId << " -> " << levelName(LOCKED) << ". Electronic badges removed.\n";
    return true;
    
    
}

bool AccessControlSubSystem::restricBuilding(const string& buildingId){
    if (buildingId.empty())
    {
        cout << "[AccessControl] ERROR: Cannot restrict a building with no ID. \n";
        return false;
    }
    if (isLocked(buildingId))
    {
        cout << "[AccessControl] " << buildingId << " is LOCKED. Cannot changed to Restricted, unlock first.\n";
        return false;
    }

    buildingAccess[buildingId] = RESTRICTED;
    cout << "[AccessControl] " << buildingId << " -> " << levelName(RESTRICTED) << ". Authorised staff only!\n";
    return true;
    
    
}

bool AccessControlSubSystem::unlockBuilding(const string& buildingId){
    if (getAccessLevel(buildingId) == OPEN)
    {
        cout << "[AccessControl] " << buildingId << " is already OPEN, no changes were made\n";
        return false;
    }
    

    buildingAccess[buildingId] = OPEN;
    cout << "[AccessControl] " << buildingId << " -> " << levelName(OPEN) << ". Normal access restored \n";
    return true;
    
    
    
}

void AccessControlSubSystem::printStatus(const string& buildingId) const {
    cout << "[AccessControl] " << buildingId << " is currently " << levelName(getAccessLevel(buildingId)) << ".\n";
}

