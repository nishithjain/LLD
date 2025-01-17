#pragma once
#include <string>

#include "LyricsDisplay.h"
#include "MusicLoader.h"
#include "MusicPlayer.h"
#include "VolumeControl.h"

class MusicPlayerFacade {
    MusicLoader loader_;
    MusicPlayer player_;
    VolumeControl volume_;
    LyricsDisplay lyrics_;

public:
    void PlayTrack(const std::string& track, int volume_level);
    void StopTrack();
    void PauseTrack();
};

