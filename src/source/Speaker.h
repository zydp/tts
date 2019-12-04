#pragma once
#include <iostream>
#include <sapi.h>               // SAPI
#include <sphelper.h>           // SAPI Helper
#include <string>
#include <time.h>
#include <process.h>
#include <atomic>
using namespace std;

struct Speaker {
public:
	Speaker();
	~Speaker();
public:
	void CheckInitStaus();
	bool VoicePrepare();
	string SetOutput(const string& filepath, const string& fileNamePrefix);
	bool Speak(WCHAR* text, SpeechVoiceSpeakFlags Flags, unsigned long *StreamNumber = 0);
private:
	bool initContent();
	void deInitContent();
private:
	std::atomic_bool isInit_;
	CComPtr<ISpVoice> m_tts_;
	CComPtr<ISpObjectToken> m_voiceToken_;
	CComPtr<ISpStreamFormat> oldStream_;
};

