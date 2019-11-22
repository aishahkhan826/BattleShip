
#ifndef BATTLESHIP_GAMEATTRIBUTES_H
#define BATTLESHIP_GAMEATTRIBUTES_H
#include <istream>
#include <map>
namespace BattleShip {
    class GameAttributes {
    public:
        GameAttributes();
        GameAttributes(int numRows, int numCols, int numShips);
        GameAttributes(std::istream& in);

        int getNumRows() const;
        void setNumRows(int numRows);
        int getNumCols() const;
        void setNumCols(int numCols);
        int getNumShips() const;
        void setNumShips(int numShips);

        int getShipSize(const char ShipChar) const;
        const std::map<char, int>& getShipAttributes() const;
        void setShipAttributes(std::map<char,int> shipAttributes);

    private:
        int numRows, numCols;
        int numShips;
        std::map<char, int> shipAttributes;
    };

    std::istream& operator>>(std::istream& in, GameAttributes& gameAttributes);

}
#endif //BATTLESHIP_GAMEATTRIBUTES_H
