class Cells 
{
    public:
        static void setDimensions(int rows = 0, int cols = 0) {
            Cells::rows = rows;
            Cells::cols = cols;
            Cells::cellsRevealed = 0;
        }
        static void setMineTotal(int mineTotal) {
            Cells::mineTotal = mineTotal;
        }
        static int getRows() {
            return Cells::rows; 
        }
        static int getCols() {
            return Cells::cols;
        }
        static bool isFullyRevealed() {
            return (Cells::rows * Cells::cols) - Cells::mineTotal == Cells::cellsRevealed;
        }
        inline static int rows = 0, cols = 0;
        inline static int mineTotal = 0;
        inline static int cellsRevealed = 0;
};

