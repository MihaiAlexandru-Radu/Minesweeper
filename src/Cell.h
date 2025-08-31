#ifndef CELL_H
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
        bool isMine();
        std::string getCellSymbol();
    
    private:
        bool isRevealed, isMined, isFlagged;
        int adjacentMines;

};

#endif