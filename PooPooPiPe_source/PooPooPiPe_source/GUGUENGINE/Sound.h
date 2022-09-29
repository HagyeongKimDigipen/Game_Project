#pragma once
/*
 *eunjin.hong
 *9.23.2019
 *chocob0217@gmail.com
 *Sound.h
 *this is a header for sound
 */
#include <string>
#include <vector>
#include "fmod.hpp"
#include "System.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"

class Sound : public System
{
public:
	void Init() override;
	void Update() override;

	Sound();
	~Sound();

	//void Free();
	void LoadMusic(const char* filePath);

	void Load();

	bool IsPlaying();
	bool IsPaused();
	void Play(std::string source, int loop = 1);
	void Pause();
	void Resume();
	void Stop();
	void Rewind();

	void SetVolume(float volume = 0.3f);
	float GetVolume();
	void ToggleMute();
	void SetLoopCount(int loopCount);
	void StopEffectSound();
	void StopSound(std::string mString);
	void resumeSound(std::string mString);
	void pauseSound(std::string mString);

	bool IsMute_();
	bool soundCheck(std::string mString);

	Vector2<float> GetSoundBarSize() { return soundBarSize; };
	Vector2<float> GetSoundBarPosition() { return soundBarPosition; };

	void SetSoundBarSize(float size) { soundBarSize.x += size;};
	void SetSoundBarPosition(float posiiton) { soundBarPosition.x += posiiton; };

	void SetSoundBarSize(Vector2<float> size) { soundBarSize.x = size.x;  soundBarSize.x = size.x;};
	void SetSoundBarPosition(Vector2<float> position) { soundBarPosition.x = position.x; soundBarPosition.y = position.y;};
	
private:

	struct SOUNDMANAGER
	{
		FMOD::Channel* channel = nullptr;
		FMOD::Sound* sound = nullptr;
		bool IsPlaying = false;

		std::string source = "";
	};

	std::vector<SOUNDMANAGER*> m_sounds;

	FMOD::System* system;

	FMOD::ChannelGroup* soundEffects = nullptr;
	FMOD::ChannelGroup* backgroundSounds = nullptr;
	FMOD::ChannelGroup* masterChannel = nullptr;

	bool isPlaying = false;
	bool isMute = false;
	
	float m_volume;
	FMOD_RESULT result;

	Vector2<float>	soundBarSize;
	Vector2<float> soundBarPosition;
};
extern Sound* SOUND;