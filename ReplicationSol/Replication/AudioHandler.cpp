#include "AudioHandler.h"
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <string>


/// <summary>
/// JUNSHEN
/// 
/// Plays a sound effect based on a given sfx id (same as file name)
/// </summary>
/// <param name="sfxID"></param>
void AudioHandler::PlaySFX(std::string sfxID) {
    //Get path
    std::wstring base = L"play audio\\";
    std::wstring fileName(sfxID.begin(), sfxID.end());
    std::wstring extension = L".wav";

    std::wstring result = base + fileName + extension;

    mciSendString(result.c_str(), NULL, 0, NULL);
}
