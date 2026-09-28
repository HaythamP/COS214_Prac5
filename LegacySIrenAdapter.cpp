#include "LegacySirenAdapter.h"
#include "OldSirenRadioHW.h"
#include <iostream>

LegacySirenAdapter::LegacySirenAdapter(OldSirenRadioHW* hw):legacyHardware(hw) {}

LegacySirenAdapter::~LegacySirenAdapter() {}

void LegacySirenAdapter::sendAlert(int priorityLevel, const std::string& message, const std::string& zone) {
    std::cout<<"[LegacySirenAdapter] Adapting modern alert for zone: "<<zone<<" ('" << message << "')\n";
    if(legacyHardware) {
        if(priorityLevel==1) {
            legacyHardware->transmitTone(120,15);
            legacyHardware->broadcastVoiceTape("TAPE_EVACUATE_ZONE_URGENT");
        }else{
            legacyHardware->transmitTone(60,5);
            legacyHardware->broadcastVoiceTape("TAPE_CAUTION_GENERAL");
        }
    }
}