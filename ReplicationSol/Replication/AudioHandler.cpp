#include "AudioHandler.h"
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <string>



void AudioHandler::PlaySFX(std::string sfxID) {
    std::wstring base = L"play audio\\";
    std::wstring fileName(sfxID.begin(), sfxID.end());
    std::wstring extension = L".wav";

    std::wstring result = base + fileName + extension;

    mciSendString(result.c_str(), NULL, 0, NULL);
}
