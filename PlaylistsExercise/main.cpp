#include "RepeatingPlaylist.hpp"
#include "Song.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    // Create a RepeatingPlaylist object
    RepeatingPlaylist playlist;

    // Test an empty playlist
    playlist.PrintPlaylist(); // Expected output: (empty)

    // Test PushBack and PushFront with empty playlist
    Song song1("Song 1");
    Song song2("Song 2");
    Song song3("Song 3");

    playlist.PushBack(song1);
    playlist.PushFront(song2);
    playlist.PushBack(song3);

    playlist.PrintPlaylist(); // Expected output: Song 2, Song 1, Song 3

    // Test modifying the value of a song
    Song& frontSong = playlist.GetFront();
    frontSong.SetName("Modified Song 2");

    playlist.PrintPlaylist(); // Expected output: Modified Song 2, Song 1, Song 3

    // Test modifying the value of the last song
    Song& backSong = playlist.GetBack();
    backSong.SetName("Modified Song 3");

    playlist.PrintPlaylist(); // Expected output: Modified Song 2, Song 1, Modified Song 3

    // Test modifying the value of a song using PopFront and PushFront
    playlist.PopFront();
    playlist.PushFront(song3);

    playlist.PrintPlaylist(); // Expected output: Modified Song 3, Song 1, Modified Song 3

    // Test modifying the value of a song using PopBack and PushBack
    playlist.PopBack();
    playlist.PushBack(song2);

    playlist.PrintPlaylist(); // Expected output: Modified Song 3, Song 1, Modified Song 2

    // Test deleting a node at a specific position
    bool deleteResult = playlist.DeleteNodeAtPosition(1); // Delete the second song

    if (deleteResult)
    {
        std::cout << "Node at position 1 deleted successfully\n";
        playlist.PrintPlaylist(); // Expected output: Modified Song 3, Modified Song 2
    }
    else
    {
        std::cout << "Failed to delete node at position 1\n";
    }

    // Test deleting a node that doesn't exist
    deleteResult = playlist.DeleteNodeAtPosition(2); // Try to delete a non-existing node

    if (deleteResult)
    {
        std::cout << "Node at position 2 deleted successfully\n";
    }
    else
    {
        std::cout << "Failed to delete node at position 2\n";
        playlist.PrintPlaylist(); // Expected output: Song 3, Song 2
    }

    // Test deleting the last remaining nodes
    playlist.DeletePlaylist();
    playlist.PrintPlaylist();         // Expected output: (empty)

    // Test deleting whole playlist one by one
    playlist.PushBack(song1);
    playlist.PushFront(song2);
    playlist.DeleteNodeAtPosition(1);
    playlist.DeleteNodeAtPosition(0);
    playlist.PrintPlaylist();         // Expected output: (empty)

	return 0;
}