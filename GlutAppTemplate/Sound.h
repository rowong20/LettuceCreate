#include <string>
#include "irrKlang/irrKlang.h"

using namespace irrklang;

#pragma comment(lib, "irrKlang.lib")

class Sound {
	ISoundEngine* se;
	ISound* ce;
	bool playing = false;
	void load();
	void play(std::string filepath);
public:
	Sound();
	void init(std::string spath);
	void playS(std::string spath);
	bool isPlaying();
	void stop();

	ISoundEngine* SoundEngine();
	~Sound();
};