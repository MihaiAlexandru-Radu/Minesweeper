#include <iostream>

#include "Cell.cpp"
#include "Cells.cpp"

void initCells();
void makeMove();

int main() {

    initCells();

    Cell cells[Cells::getRows()][Cells::getCols()];

    while(!Cells::isFullyRevealed()) {
        for (int row = 0; row < Cells::getRows(); row++) {
            for (int col = 0; col < Cells::getCols(); col++) {
                std::cout << cells[row][col].getCellSymbol();
            }
            std::cout << "\n";
        }
        makeMove();
    }

    return 0;
}
void initCells() {
    std::cout << "Enter board dimensions (rows x cols)> ";
    int rows = 0, cols = 0;
    std::cin >> rows >> cols;
    Cells::setDimensions(rows,cols);

    std::cout << "Enter mine number> ";
    int mineTotal = 0;
    std::cin >> mineTotal;
    Cells::setMineTotal(mineTotal);
}
void makeMove() {
    std::cout << "> ";
    std::string move = "";
    std::cin >> move;
}
