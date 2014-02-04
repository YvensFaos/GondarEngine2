#ifndef __GS_AUDIO_H__
#define __GS_AUDIO_H__

#include "gsConfig.h"
#include "gsMacros.h"

// Subsistema responsável pelas rotinas de áudio
class GS_DLL gsAudio {
private:
	static float masterVolume;
	static float musicVolume;
	static float sfxVolume;
	static bool stereo;

public:
	static void init();
	static void update();
	static void dispose();

	inline static float getMasterVolume() { return gsAudio::masterVolume; }
	inline static float getMusicVolume() { return gsAudio::musicVolume; }
	inline static float getSFXVolume() { return gsAudio::sfxVolume; }
	inline static bool isStereo() { return gsAudio::stereo; }

	inline static void setMasterVolume(float volume) { gsAudio::masterVolume = volume; }
	inline static void setMusicVolume(float volume) { gsAudio::musicVolume = volume; }
	inline static void setSFXVolume(float volume) { gsAudio::sfxVolume = volume; }
	inline static void setStereo(bool stereo) { gsAudio::stereo = stereo; }
};

#endif