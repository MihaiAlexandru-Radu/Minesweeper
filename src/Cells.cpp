#include "Cell.cpp"

class Cells 
{
    public:

        Cells(int rows, int cols, int bombs) {
            this->rows = rows;
            this->cols = cols;
            this->bombs = bombs;
        }

    private:
        static int rows, cols;
        static int bombs;

};