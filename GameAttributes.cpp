#include <utility>
#include <iostream>
#include "Utility.h"
#include "GameAttributes.h"

BattleShip::GameAttributes::GameAttributes() : numRows(10), numCols(10), numShips(5) {}

BattleShip::GameAttributes::GameAttributes(int numRows, int numCols, int numShips) : numRows(numRows), numCols(numCols), numShips(numShips) {
}

BattleShip::GameAttributes::GameAttributes(std::istream& in){
    in >> numRows;
    in >> numCols;
    in >> numShips;
    char shipChar;
    int shipLen;
    for( int i = 0; i < numShips; i++){
        verifiedRead(in, shipChar);
        verifiedRead(in, shipLen);
        shipAttributes.insert({shipChar, shipLen});
    }
}


int BattleShip::GameAttributes::getNumRows() const {
    return numRows;
}

void BattleShip::GameAttributes::setNumRows(int numRows) {
    this->numRows = numRows;
}

int BattleShip::GameAttributes::getNumCols() const {
    return numCols;
}

void BattleShip::GameAttributes::setNumCols(int numCols) {
    this->numCols = numCols;
}

int BattleShip::GameAttributes::getNumShips() const {
    return numShips;
}

void BattleShip::GameAttributes::setNumShips(int numShips) {
    this->numShips = numShips;
}


int BattleShip::GameAttributes::getShipSize(const char ShipChar) const {
    return shipAttributes.at(ShipChar);
}

const std::map<char, int> &BattleShip::GameAttributes::getShipAttributes() const {
    return shipAttributes;
}

void BattleShip::GameAttributes::setShipAttributes(std::map<char, int> shipAttributes) {
    this->shipAttributes = shipAttributes;
}
