#pragma once

#include <iostream>
#include <string>

#pragma comment(lib, "winmm.lib")

class MusicHandler
{
public:
	static void PlayMusic(std::string sfxID);
	static void StopMusic();
};

