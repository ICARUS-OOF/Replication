#include "MusicHandler.h"
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <string>

/// <summary>
/// KAYDEN
/// 
/// Play music based on a musicID (file name)
/// Overrides the current music playing
/// </summary>
/// <param name="musicID"></param>
void MusicHandler::PlayMusic(std::string musicID) {
    std::string path = "music\\" + musicID + ".wav";
    PlaySoundA(path.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

/// <summary>
/// KAYDEN
/// 
/// Stop the current track immediately
/// </summary>
void MusicHandler::StopMusic()
{
    PlaySoundA(0,0,0);
}
