#include "MusicPlayerFacade.h"

#include <iostream>

void MusicPlayerFacade::PlayTrack(const std::string& track, const int volume_level)
{
	loader_.LoadMusic(track);           // Load the track
	volume_.SetVolume(volume_level);    // Set the volume level
	player_.PlayMusic();                // Play the music
	lyrics_.DisplayLyrics(track);       // Display the lyrics
}

void MusicPlayerFacade::StopTrack()
{
	player_.StopMusic();				// Stop the music
	std::cout << "Music has been stopped.\n";
}

void MusicPlayerFacade::PauseTrack()
{
	player_.PauseMusic();				// Pause the music
	std::cout << "Music has been paused.\n";
}

