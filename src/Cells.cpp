class Cells 
{
    public:
        static void setDimensions(int rows, int cols) {
            Cells::rows = rows;
            Cells::cols = cols;
            Cells::cellsRevealed = 0;
        }
        static void setMineTotal(int mineTotal) {
            Cells::mineTotal = mineTotal;
        }
        static int getRows() {
            return rows; 
        }
        static int getCols() {
            return cols;
        }
        static bool isFullyRevealed() {
            return (rows * cols) - mineTotal == cellsRevealed;
        }

    private:
        static int rows, cols;
        static int mineTotal;
        static int cellsRevealed;
};