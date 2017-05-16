#include "Tile.h"

class Table
{
public:
    Table();
    Table(Table& t);
    ~Table();
    void setTileColor(int i, int j, Tile::COLORS color);
    void setTileValue(int i, int j, int value);
    void setTileLength(int i, int j, int length);
    void setTileAll(int i, int j, int value);
    Tile::COLORS getTileColor(int i, int j);
    int getTileValue(int i, int j);
    int getTileLength(int i, int j);
    Tile getTile(int i, int j);
    bool operator==(const Table& other) const;

protected:

private:
    Tile** tableOfTiles;
};
