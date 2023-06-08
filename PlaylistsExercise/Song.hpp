#ifndef SONG_HPP
#define SONG_HPP

#include <stdexcept>

class Song
{
public:
    Song(std::string name) : name(name) {}

    inline std::string GetName() const
    {
        return this->name;
    }

private:
    const std::string name;
};

#endif