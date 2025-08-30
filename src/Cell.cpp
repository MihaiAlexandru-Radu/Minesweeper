class Cell 
{
    public:
        Cell() {
            this->isMine = false;
            this->isFlagged = false;
            this->isRevealed = false;
            this->adjacentMines = 0;
        }
        void click() {

        }
        void flag() {

        }
        void chord() {

        }
        void addMine() {
            
        }
        void countAdjacentMines() {
            
        }
        
    private:
        bool isMine, isFlagged, isRevealed;
        int adjacentMines;
};