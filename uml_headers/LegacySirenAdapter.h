#ifndef LEGACY_SIREN_ADAPTER_H
#define LEGACY_SIREN_ADAPTER_H
#include "NotificationService.h"

class OldSirenRadioHW;
class LegacySirenAdapter:public NotificationService{
    private:    
    OldSirenRadioHW* legacyHardware;

    public:
        LegacySirenAdapter(OldSirenRadioHW* hw);
        virtual ~LegacySirenAdapter();
        void sendAlert(int priorityLevel,const std::string& message, const std::string& zone) ;
};
#endif