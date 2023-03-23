A playlist is considered a repeating playlist if any of the songs contain a pointer to a previous song in the playlist. Otherwise, the playlist will end with the last song which points to NULL.

Implement a function isInRepeatingPlaylist that, efficiently with respect to time used, returns true if a playlist is repeating or false if it is not.

For example, the following code prints "true" as both songs point to each other.

    Song* first = new Song("Hello");
    Song* second = new Song("Eye of the tiger");
    
    first->next(second);
    second->next(first);

    std::cout << std::boolalpha << first->isInRepeatingPlaylist();