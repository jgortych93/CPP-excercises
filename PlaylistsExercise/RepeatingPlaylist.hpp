#ifndef REPEATING_PLAYLIST_HPP
#define REPEATING_PLAYLIST_HPP

#include "Song.hpp"

class RepeatingPlaylist
{
public:
    RepeatingPlaylist();
    ~RepeatingPlaylist();

    bool InsertSongOfName(const std::string& name) = default;
    bool EreaseSongOfName(const std::string& name);

    void DeletePlaylist();

private:
    Song* root;
    Song* back;
};

#endif // !REPEATING_PLAYLIST_HPP
