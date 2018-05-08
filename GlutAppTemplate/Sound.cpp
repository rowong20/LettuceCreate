#include "Sound.h"

Sound::Sound() {

}

void Sound::init(std::string spath) {
	se = irrklang::createIrrKlangDevice();
	if (!se)
		printf("Error: Not created\n");
	//load();
	playing = true;
	ce = se->play2D(spath.c_str());
}

void Sound::load() {

}

void Sound::playS(std::string spath) {
	se->play2D(spath.c_str());
}

void Sound::play(std::string spath) {
	if (!playing) {
		playing = true;
		se->play2D(spath.c_str());
	}
	else {
		se->stopAllSounds();
		ce = se->play2D(spath.c_str());
	}
}

void Sound::stop() {
	se->stopAllSounds();
}

bool Sound::isPlaying() {
	return playing;
}

irrklang::ISoundEngine * Sound::SoundEngine() {
	return se;
}

Sound::~Sound() {
	se->drop();
}