#include <string>

class Cell 
{
    public:
        Cell() {
            this->isMined = false;
            this->isFlagged = false;
            this->adjacentMines = 0;
        }
        void mine() {

        }
        void chord() {

        }
        void flag() {

        }
        void addMine() {
            
        }
        void countAdjacentMines() {
            
        }
        std::string getCellSymbol() {
            if(isMined) return "[" + std::to_string(adjacentMines) + "]"; 
            else if(isFlagged) return "[F]";
            else return "[ ]";
        }
        
    private:
        bool isMined, isFlagged;
        int adjacentMines;
};