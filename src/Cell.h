#ifndef CELL_H_INCLUDED
#define CELL_H

#include <string>

class Cell
{
    public:
        Cell();
        void reveal();
        void flag();
        void addMine();
        void setAdjacentMines(int adjacentMines);
        std::string getCellSymbol();
    
    private:
        bool isRevealed, isMined, isFlagged;
        int adjacentMines;

};

#endif