#include <algorithm>
#include "ShipPlacement.h"
#include <sstream>
#include <stdexcept>

ShipPlacement::ShipPlacement() {

}
ShipPlacement::ShipPlacement(int rowStart, int colStart, int rowEnd, int colEnd) : rowStart(rowStart),
                                                                                   colStart(colStart), rowEnd(rowEnd),
                                                                                   colEnd(colEnd) {}

void ShipPlacement::normalize() {
    if (rowStart > rowEnd){
        std::swap(rowStart, rowEnd);
    }
    if (colStart > colEnd){
        std::swap(colStart, colEnd);
    }
}
