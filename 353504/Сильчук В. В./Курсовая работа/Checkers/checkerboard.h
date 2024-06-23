#ifndef CHECKERBOARD_H
#define CHECKERBOARD_H
#include "coordinates.h"
#include "tile.h"

class Checkerboard
{
public:
    Checkerboard();
    [[nodiscard]] std::vector<PlayableTile*> getPlayableTiles() const;

private:
    void createTiles();

    std::vector<std::unique_ptr<Tile>> nonPlayableTiles_;
    std::vector<std::unique_ptr<PlayableTile>> playableTiles_;
};

#endif // CHECKERBOARD_H
