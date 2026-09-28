#ifndef NOTIFICATION_SERVICE_H
#define NOTIFICATION_SERVICE_H

#include <string>

class NotificationService{
    public:
        virtual ~NotificationService(){}
        virtual void sendAlert(int priorityLevel, const std::string& message, const std::string& zone)=0;

};

#endif