#include "AudioHandler.h"
#include <windows.h>
#include <iostream>

#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib")
#include <string>



void AudioHandler::Playsound(std::string sfxID) {
	PlaySound(TEXT("/Replication/audio/" , sfxID , ".wav"), NULL, SND_ASYNC);
}
