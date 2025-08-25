#include "AudioHandler.h"
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <string>



void AudioHandler::Playsound(std::string sfxID) {
    std::string path = "audio\\" + sfxID + ".wav";
    PlaySoundA(path.c_str(), NULL, SND_FILENAME | SND_ASYNC);
}
