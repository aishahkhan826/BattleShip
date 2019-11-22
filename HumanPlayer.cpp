
#include <utility>
#include <iostream>
#include "HumanPlayer.h"
#include "ShipPlacement.h"
#include "Attack.h"
#include <iostream>

BattleShip::HumanPlayer::HumanPlayer(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view) : Player(
        gameAttributes, view) {}

std::unique_ptr<BattleShip::Move> BattleShip::HumanPlayer::getMove() {
    std::pair<int, int> firingCoordinates;
    firingCoordinates = view.getFiringCoordinate(*this);
    return std::make_unique<Attack>(*this, firingCoordinates.first, firingCoordinates.second);
}

void BattleShip::HumanPlayer::placeShips() {
    for(const auto& ship : shipHealths) {
        ShipPlacement placement = view.getShipPlacement(*this,ship.first, ship.second);
        (*this).getBoard().AddShip(ship.first, placement);
    }
    view.updateShipPlacementView(*this);
}

void BattleShip::HumanPlayer::initializeName() {
    setName(view.getPlayerName(id+1));
}
