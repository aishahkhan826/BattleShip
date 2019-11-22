
#include "Board.h"
#include "Board.h"
#include "Cell.h"
#include <iostream>

BattleShip::Board::Board(int numRows, int numCols, char blankChar) : blankChar(blankChar), numRows(numRows), numCols(numCols) {}

BattleShip::Board::Board(const char blankChar, int numRows, int numCols) : blankChar('*'), numRows(numRows), numCols(numCols) {

    for(int i = 0; i <numRows; i++){
        std::vector<BattleShip::Cell>row;
        for(int j = 0; j <numCols; j++){
            Cell cell('*');
            row.push_back(cell);
        }
        boardState.push_back(row);
    }
}

bool BattleShip::Board::canPlaceShipAt(const ShipPlacement &shipPlacement) const {
    return (inBounds(shipPlacement) && spacesAreEmpty(shipPlacement));
}

int BattleShip::Board::getNumRows() const {
    return this->numRows;
}

int BattleShip::Board::getNumCols() const {
    return this->numCols;
}

std::vector<std::vector<BattleShip::Cell>> BattleShip::Board::getHiddenVersion() const {
    std::vector<std::vector<Cell>> mat;
    for (int i = 0; i < getNumRows(); ++i) {
        std::vector<Cell> curRow = boardState.at(i);
        for (int j = 0; j < getNumCols(); ++j) {
            curRow.push_back((boardState[i][j]).getContentsIfHidden());
        }
        mat.push_back(curRow);
    }
    return mat;
}

std::vector<std::vector<BattleShip::Cell>> BattleShip::Board::getVisibleVersion() const {
    std::vector<std::vector<Cell>> mat;
    for (int i = 0; i < getNumRows(); ++i) {
        std::vector<Cell> curRow = boardState.at(i);
        for (int j = 0; j < getNumCols(); ++j) {
            curRow.push_back((boardState[i][j]).getContentsIfVisible());
        }
        mat.push_back(curRow);
    }
    return mat;
}

void BattleShip::Board::AddShip(char shipChar, const ShipPlacement &shipPlacement) {
    if(canPlaceShipAt(shipPlacement) == true){
        if (shipPlacement.rowStart == shipPlacement.rowEnd){
            for (int i = shipPlacement.colStart; i <= shipPlacement.colEnd; i++){
                int a = shipPlacement.rowStart;
                this->boardState[a][i].setContents(shipChar);
            }
        }
        else if (shipPlacement.colStart == shipPlacement.colEnd){
            for (int i = shipPlacement.rowStart; i <= shipPlacement.rowEnd; i++){
                int b = shipPlacement.colStart;
                this->boardState[i][b].setContents(shipChar);
            }
        }
    }
}

bool BattleShip::Board::inBounds(int row, int col) const {
    return (row >= 0 && row < getNumRows() && col >= 0 && col < getNumRows());
}

BattleShip::Cell &BattleShip::Board::at(int i, int j) {
    return boardState[i][j];
}

const BattleShip::Cell &BattleShip::Board::at(int i, int j) const {
    return boardState[i][j];
}

bool BattleShip::Board::inBounds(const ShipPlacement &shipPlacement) const {
    if( shipPlacement.rowStart >= 0 && shipPlacement.rowEnd < numRows &&
        shipPlacement.colStart >= 0 && shipPlacement.colEnd < numCols){
        return true;
    } else{
        return false;
    }
}

bool BattleShip::Board::between(int value, int low, int high) const {
    if (low <= value && value >= high){
        return true;
    }
    else {
        return false;
    }
}

bool BattleShip::Board::spacesAreEmpty(const ShipPlacement &shipPlacement) const {
    bool empty = true;
    if (shipPlacement.rowStart == shipPlacement.rowEnd){
        for (int i = shipPlacement.colStart; i < shipPlacement.colEnd; i++){
            if (boardState[shipPlacement.rowStart][i].getContents() != '*'){
                empty = false;
            }
        }
    }
    else if (shipPlacement.colStart == shipPlacement.colEnd){
        for (int i = shipPlacement.rowStart; i < shipPlacement.rowEnd; i++){
            if (boardState[i][shipPlacement.colStart].getContents() != '*'){
                empty = false;
            }
        }
    }
    return empty;
}
