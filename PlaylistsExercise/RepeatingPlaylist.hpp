#ifndef REPEATING_PLAYLIST_HPP
#define REPEATING_PLAYLIST_HPP

#include "Song.hpp"

class RepeatingPlaylist
{
public:
    RepeatingPlaylist()
        : root(nullptr)
        , back(nullptr)
    {}
    ~RepeatingPlaylist();

    void PushBack(Song& song);
    void PushFront(Song& song);
    void PopBack();
    void PopFront();

    Song& GetFront() const;
    Song& GetBack() const;

    void DeletePlaylist();

    void PrintPlaylist();

private:
    struct Node {
        Song* val;
        Node* nextSong;
        Node* prevSong;
    };

    Node* root;
    Node* back;
};

#endif // !REPEATING_PLAYLIST_HPP
