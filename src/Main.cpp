#include <iostream>
#include <string>

#include "Cell.h"

bool isWon(int rows, int cols, int mineTotal, int revealedCells);

int main() {
    //initialize important variables
    int rows = 0, cols = 0;
    int mineTotal = 0;
    int revealedCells = 0;
    bool isWon = false, isLost = false;

    // get user input for game dimensions, difficulty through mine number
    std::cout << "Enter board dimensions (rows x cols)> ";
    std::cin >> rows >> cols;
    std::cout << "Enter mine number> ";
    std::cin >> mineTotal;

    // place mines in cells
    Cell cells[rows][cols];
    int i = 1;
    while(i <= mineTotal) {
        int bombRow = rand() % rows, bombCol = rand() % cols;
        Cell &bombCell = cells[bombRow][bombCol];
        if(bombCell.isMine()) continue;
        bombCell.addMine();
        i++;
    }

    // count adjacent mines for each non-mined cell
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            if(!cells[row][col].isMine()) {
                int adjacentMines = 0;
                if(row > 0 && cells[row-1][col].isMine()) adjacentMines++;
                if(col > 0 && cells[row][col-1].isMine()) adjacentMines++;
                if(row < rows-1 && cells[row+1][col].isMine()) adjacentMines++;
                if(col < cols-1 && cells[row][col+1].isMine()) adjacentMines++;
                if(row > 0 && col > 0 && cells[row-1][col-1].isMine()) adjacentMines++;
                if(row < rows-1 && col < cols-1 && cells[row+1][col+1].isMine()) adjacentMines++;
                if(row > 0 && col < cols-1 && cells[row-1][col+1].isMine()) adjacentMines++;
                if(row < rows-1 && col > 0 && cells[row+1][col-1].isMine()) adjacentMines++;
                cells[row][col].setAdjacentMines(adjacentMines);
            }
        }
    }

    // game loop
    while(!isWon && !isLost) {
        // print cells
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                std::string cellSymbol = cells[row][col].getCellSymbol();
                std::cout << cellSymbol;
            }
            std::cout << "\n";
        }

        // get user input for action
        char action = '-';
        int actionRow = 0, actionCol = 0; 
        std::cout << "> ";
        std::cin >> action >> actionRow >> actionCol;

        // stop action if user coordinates out of bounds
        bool inBounds = (actionRow >= 0 && actionRow < rows) && (actionCol >= 0 && actionCol < cols);
        if(!inBounds) {
            std::cout << "#ERROR# - INVALID COORDINATE\n";
            continue;
        }

        // do user action 
        switch(action) {
            case 'R': case 'r':
                cells[actionRow][actionCol].reveal();
                if(cells[actionRow][actionCol].isMine()) isLost = true;
                else revealedCells++;
                break;
            case 'F': case 'f':
                cells[actionRow][actionCol].flag();
                break;
            default:
                std::cout << "#ERROR# - INVALID ACTION\n";
                break;
        }

        // check victory condition
        isWon = (rows*cols)-mineTotal == revealedCells;
    }

    // print cells
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            std::string cellSymbol = cells[row][col].getCellSymbol();
            std::cout << cellSymbol;
        }
        std::cout << "\n";
    }

    // print victory condition
    if(isWon) std::cout << "YOU WON!";
    if(isLost) std::cout << "YOU LOST!";

    return 0;
}