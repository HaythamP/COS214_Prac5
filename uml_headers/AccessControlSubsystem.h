#ifndef ACCESS_CONTROL_SUBSYSTEM_H
#define ACCESS_CONTROL_SUBSYSTEM_H

#include <string>
#include <map>
using namespace std;


class AccessControlSubsystem{
    public:

        enum AccessLevel { OPEN, RESTRICTED, LOCKED};
        AccessControlSubsystem();
        virtual ~AccessControlSubsystem();

        bool lockDownBuilding(const string& buildingId);
        bool restricBuilding(const string& buildingId);
        bool unlockBuilding(const string& buildingId);

        AccessLevel getAccessLevel(const string& buildingId) const;
        bool isLocked(const string& buildingId) const;

        void printStatus(const string& buildingId) const;
    
    private:
        std::map<string, AccessLevel> buildingAccess;
        static string levelName(AccessLevel lvl);


};

#endif