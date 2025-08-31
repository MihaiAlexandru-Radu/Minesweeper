#include <string>

#include "Cell.h"

class Cell 
{
    public:
        Cell() {
            this->isRevealed = false;
            this->isMined = false;
            this->isFlagged = false;
            this->adjacentMines = 0;
        }
        void reveal() {
            isRevealed = true;
        }
        void flag() {
            isFlagged = !isFlagged;
        }
        void addMine() {
            isMined = true;
        }
        void setAdjacentMines(int adjacentMines) {
            this->adjacentMines = adjacentMines;
        }
        std::string getCellSymbol() {
            if(isMined) return "[" + std::to_string(adjacentMines) + "]"; 
            else if(isFlagged) return "[F]";
            else return "[ ]";
        }
        
    private:
        bool isRevealed, isMined, isFlagged;
        int adjacentMines;
};