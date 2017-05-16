#include "Table.h"
#include <stdlib.h>

Table::Table()
{
    tableOfTiles = (Tile**) malloc(sizeof(Tile*)*4);
    for(int i = 0; i < 4; i++) tableOfTiles[i] = (Tile*) malloc(sizeof(Tile)*4);
    Tile tmp;
    tmp.setAll(0);
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            tableOfTiles[i][j] = tmp;
}

Table::Table(Table& t){
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            this->tableOfTiles[i][j] = t.tableOfTiles[i][j];
}

Table::~Table()
{
    free(tableOfTiles);
}
// setter, getter
void Table::setTileColor(int i, int j, Tile::COLORS color){ tableOfTiles[i][j].setColor(color);}
void Table::setTileValue(int i, int j, int value){tableOfTiles[i][j].setValue(value);}
void Table::setTileLength(int i, int j, int length){tableOfTiles[i][j].setLength(length);}
void Table::setTileAll(int i, int j, int value){tableOfTiles[i][j].setAll(value);}
Tile::COLORS Table::getTileColor(int i, int j){return tableOfTiles[i][j].getColor();}
int Table::getTileValue(int i, int j){return tableOfTiles[i][j].getValue();}
int Table::getTileLength(int i, int j){return tableOfTiles[i][j].getLength();}
Tile Table::getTile(int i, int j){return tableOfTiles[i][j];}
bool Table::operator==(const Table& other) const{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(this->tableOfTiles[i][j].getValue() != other.tableOfTiles[i][j].getValue()) return false;
    return true;
}

