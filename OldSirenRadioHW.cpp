#include "OldSirenRadioHW.h"
#include <iostream>

OldSirenRadioHW::OldSirenRadioHW(){}
OldSirenRadioHW::~OldSirenRadioHW(){}

void OldSirenRadioHW::transmitTone(int frequencyKhz, int durationSec){
    std::cout<<" [OldSirenRadioHW] Pushing radio horn at "<<frequencyKhz<<" kHz for "<<durationSec<<" seconds.\n";
}

void OldSirenRadioHW::broadcastVoiceTape(const std::string& tapeId){
    std::cout<< "[OldSirenRadioHW] Playing pre-recorded magnetic tape ID: ["<<tapeId<<"].\n";

    
}