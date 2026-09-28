#ifndef OLD_SIREN_RADIO_HW_H
#define OLD_SIREN_RADIO_HW_H


#include <string>

class OldSirenRadioHW{

    public:
        OldSirenRadioHW();
        virtual ~OldSirenRadioHW();
        void transmitTone(int frequencyKhz, int durationSec);
        void broadcastVoiceTape(const std::string& tapeId);
};

#endif