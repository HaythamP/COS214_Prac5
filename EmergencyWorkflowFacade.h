#ifndef EMERGENCYWORKFLOWFACADE_H
#define EMERGENCYWORKFLOWFACADE_H
#include <string>
using namespace std;

class AccessControlSubsystem;
class NotificationService;
class IncidentCommanderConsole;
class Incident;

class EmergencyWorkflowFacade{
    private:
        AccessControlSubsystem* accessControl;
        NotificationService* sirenService;
        IncidentCommanderConsole* console;

    public:
        EmergencyWorkflowFacade(AccessControlSubsystem* ac, NotificationService* ns, IncidentCommanderConsole icc);
        virtual ~EmergencyWorkflowFacade();

        void initiateCampusLockdown(const string& buildingId, Incident* incident);
        void resolveEmergency(const string& buildingId, Incident* incident);
};
#endif