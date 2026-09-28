#ifndef ACCESSCONTROLSUBSYSTEM_H
#define ACCESSCONTROLSUBSYSTEM_H

#include <string>
#include <map>
using namespace std;


class AccessControlSubSystem{
    public:

        enum AccessLevel { OPEN, RESTRICTED, LOCKED};
        AccessControlSubSystem();
        virtual ~AccessControlSubSystem();

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