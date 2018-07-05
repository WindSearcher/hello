#ifndef _CMUSIC_H
#define _CMUSIC_H

#include <Windows.h>  
#include <string>  
#include <iostream>  
#pragma comment(lib,"winmm.lib")  
using namespace std;

class CMusic
{
private:
	bool isOpen;
	string mediaName;
	string open_cmd;
	string status_cmd;
	string play_cmd;
	string close_cmd;
	static string ALIAS_NAME;
	bool SendMciCmd(string cmd);
	string GetMciStatus(string cmd);

	void ClosePlayer();
	void OpenMediaFile();
	void PlayMediaFile();

public:
	CMusic();
	CMusic(string mediaName);

	~CMusic() {};

	void setMediaName(string mediaName) 
	{ 
		this->mediaName = mediaName;
	}
	bool isStopped();
	void Play();
	void Stop();

};


#endif


