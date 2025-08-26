#include "MusicHandler.h"
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <string>

void MusicHandler::PlayMusic(std::string musicID) {
    std::string path = "music\\" + musicID + ".wav";
    PlaySoundA(path.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void MusicHandler::StopMusic()
{
    PlaySoundA(0,0,0);
}
