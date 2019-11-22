
#include <stdexcept>
#include <iostream>
#include <vector>
#include <sstream>
#include "PlayerConfiguration.h"
#include "Controller.h"
#include "HumanPlayer.h"
#include "AiPlayer.h"
#include "StandardView.h"
#include "CheatingAI.h"
#include "RandomAI.h"
#include "HuntDestroyAI.h"

BattleShip::Controller::Controller() : hasBeenSetUp(false), view(std::make_unique<StandardView>()) {}

void BattleShip::Controller::setupGame(const std::string &GameConfigurationFile, int seed) {

    AiPlayer::seed_random_number_generator(seed);
    setupGame(GameConfigurationFile);

}

void BattleShip::Controller::setupGame(const std::string &GameConfigurationFile) {

    this->model.loadGameConfigurationFromFile(GameConfigurationFile);
    PlayerConfiguration playerConfiguration = view->getPlayerConfiguration();
    for (int i = 0; i < playerConfiguration.numHumanPlayers; i++){
        model.addPlayer<HumanPlayer>(*view);
    }

    model.SetOpponents();
    hasBeenSetUp = true;

}

void BattleShip::Controller::setupGame() {

}

void BattleShip::Controller::playGame() {
    if(hasBeenSetUp == true) {
        while (model.isGameOver() == false) {
            view->showPlayersBoard(model.getAttackingPlayer());
            std::unique_ptr<Move> move = model.getNextMove();
            move->enact(model, *view);
            model.changeTurn();
        }
        view->showWinner(model.getWinner());
    }

}
