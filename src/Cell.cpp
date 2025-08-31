#include <string>

#include "Cell.h"

Cell::Cell() {
    this->isRevealed = false;
    this->isMined = false;
    this->isFlagged = false;
    this->adjacentMines = 0;
}

void Cell::reveal() {
    isRevealed = true;
}

void Cell::flag() {
    isFlagged = !isFlagged;
}

void Cell::addMine() {
    isMined = true;
}

void Cell::setAdjacentMines(int adjacentMines) {
    this->adjacentMines = adjacentMines;
}

bool Cell::isMine() {
    return isMined;
}

std::string Cell::getCellSymbol() {
    if (isMined && isRevealed)
        return "[B]";
    else if(isRevealed)
        return "[" + std::to_string(adjacentMines) + "]";
    else if (isFlagged)
        return "[F]";
    else
        return "[ ]";
}