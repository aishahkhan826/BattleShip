
#ifndef BATTLESHIP_PLAYERCONFIGURATION_H
#define BATTLESHIP_PLAYERCONFIGURATION_H
namespace BattleShip {
class PlayerConfiguration {

 public:
  PlayerConfiguration(int numHumanPlayers, int numAiPlayers);
  int numHumanPlayers, numAiPlayers;
};
}
#endif //BATTLESHIP_PLAYERCONFIGURATION_H
