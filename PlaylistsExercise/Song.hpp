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

    inline void SetName(std::string&& newName)
    {
        this->name = newName;
    }

private:
    std::string name;
};

#endif