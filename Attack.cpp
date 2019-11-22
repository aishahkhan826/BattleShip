
#include "Attack.h"



BattleShip::Attack::Attack(Player &moveMaker, const int row, const int col) : Move(moveMaker), row(row), col(col) {}

void BattleShip::Attack::enact(BattleShip::Model &model, BattleShip::View &view) {
    AttackResult resultOfAttack = moveMaker.fireAt(row, col);
    view.showPlayersBoard(moveMaker);
    view.showResultOfAttack(moveMaker, resultOfAttack);
}

const int BattleShip::Attack::getRow() const {
    return row;
}

const int BattleShip::Attack::getCol() const {
    return col;
}
