
#include <algorithm>
#include <vector>
#include <cctype>
#include "StandardView.h"
#include "Utility.h"

BattleShip::StandardView::StandardView(std::istream &in, std::ostream &out) : in(in), out(out) {}

BattleShip::StandardView::StandardView() : StandardView(std::cin, std::cout) {

}

BattleShip::PlayerConfiguration BattleShip::StandardView::getPlayerConfiguration() {
    int numHumanPlayers = 0;
    int numAIPlayers = 0;
    int gameType;
    out << "What type of game do you want to play?\n1. Human vs Human\n2. Human vs AI\n3. AI vs AI\nYour choice: \n";
    in >> gameType;
    if (gameType == 1){
        numHumanPlayers = 2;
        numAIPlayers = 0;
    }
    else if (gameType == 2){
        numHumanPlayers = 1;
        numAIPlayers = 1;
    }
    else if (gameType == 3){
        numHumanPlayers = 0;
        numAIPlayers = 2;
    }
    PlayerConfiguration players(numHumanPlayers, numAIPlayers);
    return players;
}

std::string BattleShip::StandardView::getPlayerName(int i) {
    std::string name;
    out << "Player " << i << " please enter your name:\n";
    in >> name;
    return name;
}


ShipPlacement BattleShip::StandardView::getShipPlacement(const BattleShip::Player &player, char shipChar, int shipLen) {
    char orientation;
    int rowStart;
    int colStart;
    showPlacementBoard(player);
    out << player.getName() << ", do you want to place " << shipChar << " horizontally or vertically?\nEnter h for horizontal or v for vertical\nYour choice:\n";
    in >> orientation;
    out << player.getName() << ", enter the row and column you want to place " << shipChar << ", which is " << shipLen << " long , at with a space in between row and col:\n";
    in >> rowStart;
    in >> colStart;
    ShipPlacement shipplacement;
    shipplacement.rowStart = rowStart;
    shipplacement.colStart = colStart;
    if (orientation == 'h'){
        shipplacement.rowEnd = rowStart;
        shipplacement.colEnd = colStart + shipLen-1;
    }
    else if (orientation == 'v'){
        shipplacement.rowEnd = rowStart + shipLen-1;
        shipplacement.colEnd = colStart;
    }
    return shipplacement;
}

void BattleShip::StandardView::updateShipPlacementView(const BattleShip::Player &player) {
    const Board &board = player.getBoard();
    printBoardAsVisible(board);

}

std::pair<int, int> BattleShip::StandardView::getFiringCoordinate(const BattleShip::Player &attacker) {
    std::pair<int, int> coordinates;
    int row;
    int col;
    out << attacker.getName() << ", where would you like to fire?\n"
                                 "Enter your attack coordinate in the form row col: \n";
    in >> row >> col;
    coordinates.first = row;
    coordinates.second = col;
    return coordinates;
}

void BattleShip::StandardView::showWinner(const BattleShip::Player &winner) {
    out << winner.getName() << " won the game!";
}


void BattleShip::StandardView::showResultOfAttack(const BattleShip::Player &attacker,
                                                  const BattleShip::AttackResult &attackResult) {
    if(attackResult.destroyed == true){
        out << attacker.getName() << " hit " << attacker.getOpponent().getName() << "'s " << attackResult.shipChar << "!\n";
        out << attacker.getName() << " destroyed " << attacker.getOpponent().getName() << "'s " << attackResult.shipChar << "!\n";
    }
    else if(attackResult.hit == true){
        out << attacker.getName() << " hit " << attacker.getOpponent().getName() << "'s " << attackResult.shipChar << "!\n\n";
    }
    else{
        out << "Missed.\n";
    }

}

void BattleShip::StandardView::showPlayersBoard(const BattleShip::Player &player) {
    out << player.getName() <<"'s Firing Board\n";
    printBoardAsObscured(player.getOpponent().getBoard());
    out << "\n\n" << player.getName() << "'s Placement Board\n";
    printBoardAsVisible(player.getBoard());


}

void BattleShip::StandardView::showPlacementBoard(const BattleShip::Player &player) {
    printBoardAsVisible(player.getBoard());
}


void BattleShip::StandardView::printBoardAsVisible(const BattleShip::Board &board) {
    std::vector<std::vector<BattleShip::Cell>> mat = board.getVisibleVersion();
    out << "  ";
    for (int i = 0; i < board.getNumRows(); i++){
        out << i << " ";
    }
    out << "\n";
    for(int row = 0; row < board.getNumRows(); row++) {
        out << row << " ";
        for(int col = 0; col< board.getNumCols(); col++) {
            out << mat[row][col].getContents() << " ";
        }
        out << "\n";
    }
}

void BattleShip::StandardView::printBoardAsObscured(const BattleShip::Board &board) {
    std::vector<std::vector<BattleShip::Cell>> mat = board.getHiddenVersion();
    out << "  ";
    for (int i = 0; i < board.getNumRows(); i++){
        out << i << " ";
    }
    out << "\n";
    for(int row = 0; row < board.getNumRows(); row++) {
        out << row << " ";
        for(int col = 0; col< board.getNumCols(); col++) {
            out << mat[row][col].getContentsIfHidden() << " ";
        }
        out << "\n";
    }
}

BattleShip::StandardView::~StandardView() {

}
