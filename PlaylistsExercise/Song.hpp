#ifndef SONG_HPP
#define SONG_HPP

#include <stdexcept>
#include <iostream>

class Song
{
public:
    Song(std::string name) : name(name), nextSong(NULL) {}

    void next(Song* song)
    {
        this->nextSong = song;
    }

    bool isInRepeatingPlaylist()
    {
        if (this->nextSong->nextSong == this)
            return true;
        else
            return false;
    }

private:
    const std::string name;
    Song* nextSong;
};

#endif