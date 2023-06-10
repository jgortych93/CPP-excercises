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

    void PushBack(const Song & song);
    void PushFront(const Song & song);
    void PopBack();
    void PopFront();

    Song& GetFront() const;
    Song& GetBack() const;

    bool DeleteNodeAtPosition(uint32_t idx);
    void DeletePlaylist();

    void PrintPlaylist();

private:
    struct Node {
        const Song* val;
        Node* nextSong;
        Node* prevSong;
    };

    void DeleteNode(Node* node);

    Node* root;
    Node* back;
};

#endif // !REPEATING_PLAYLIST_HPP
