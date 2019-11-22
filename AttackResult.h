
#ifndef BATTLESHIP_ATTACKRESULT_H
#define BATTLESHIP_ATTACKRESULT_H
namespace BattleShip {
class AttackResult {

 public:
  AttackResult(bool hit, bool destroyed, char shipChar);
  bool hit;
  bool destroyed;
  char shipChar;
};
}

#endif //BATTLESHIP_ATTACKRESULT_H
