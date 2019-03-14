#include "SpaceSound.h"
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"Winmm.lib")
void SpaceSound::playLaserSound() {
	//PlaySound(TEXT("laserSound.wav"), NULL, SND_SYNC);
	PlaySound(TEXT("laserGun.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void SpaceSound::playAlienOutSound() {
	PlaySound(TEXT("alienout.wav"), NULL, SND_FILENAME | SND_ASYNC);

}
void SpaceSound::mainMenuSound() {
	PlaySound(TEXT("mainMenu.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void SpaceSound::selectMenuSound() {
	PlaySound(TEXT("intro.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void SpaceSound::creepySound() {
	PlaySound(TEXT("creepySound.wav"), NULL, SND_FILENAME | SND_ASYNC);
}


void SpaceSound::explosionSound() {
	PlaySound(TEXT("Explosion.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void SpaceSound::insultSound() {
	PlaySound(TEXT(".wav"), NULL, SND_FILENAME | SND_ASYNC);
}