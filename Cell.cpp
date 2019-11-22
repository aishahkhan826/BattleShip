#include <stdexcept>
#include "Cell.h"
#include "GameAttributes.h"

BattleShip::Cell::Cell(char contents, const char hiddenMarker, const char hitMarker, const char missMarker) : contents(
        contents), hiddenMarker(hiddenMarker), hitMarker(hitMarker), missMarker(missMarker) {}

BattleShip::Cell::Cell(char contents) : contents(contents), hiddenMarker('*'), hitMarker('X'), missMarker('O') {}

char BattleShip::Cell::getContents() const {
    return this->contents;
}

void BattleShip::Cell::setContents(char contents) {
    this->contents = contents;
}

char BattleShip::Cell::getContentsIfHidden() const {
    if(HasBeenFiredAt() == true && this->contents == this->hitMarker){
        return this->hitMarker;
    }
    else if(HasBeenFiredAt() == true && this->contents == this->missMarker){
        return this->missMarker;
    }
    else{
        return '*';
    }
}

char BattleShip::Cell::getContentsIfVisible() const {
    if(HasBeenFiredAt() == true && this->contents == this->hitMarker){
        return this->hitMarker;
    }
    else if(HasBeenFiredAt() == true && this->contents == this->missMarker){
        return this->missMarker;
    }
    else{
        return this->contents;
    }
}

bool BattleShip::Cell::HasBeenFiredAt() const {
    if (this->contents != this->hiddenMarker){
        return true;
    }
    else{
        return false;
    }
}

void BattleShip::Cell::setHasBeenFiredAt(bool hasBeenFiredAt) {
    hasBeenFiredAt = true;
}

bool BattleShip::Cell::containsShip() const {
    if (this->contents != this->hiddenMarker && this->contents != this->hitMarker && this->contents != this->missMarker){
        return true;
    }
    else{
        return false;
    }
}
