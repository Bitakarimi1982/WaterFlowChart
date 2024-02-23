#include "waterFlow4.h"
#include <iostream>

//Unterklasse von WaterFlowDown
WaterFlow4::WaterFlow4() noexcept : WaterFlowDown() {}

WaterFlow4::WaterFlow4(const std::vector<std::vector<size_t>>& _heightMap) noexcept : WaterFlowDown(_heightMap) {}

WaterFlow4::WaterFlow4(const size_t numRows, const size_t numColumns) noexcept : WaterFlowDown(numRows, numColumns) {}

//das Wasser kann nach unten,oben, links und rechts abfließen 
const bool WaterFlow4::flowsOff(const size_t row, const size_t column) const noexcept {
    
    const size_t currentValue = heightMap[row][column];
    if (row == 0 || row == heightMap.size() - 1 || column == 0 || column == heightMap[row].size() - 1) {
        return true;
    }

    if (row > 0 && heightMap[row - 1][column] < currentValue && flowsOff(row - 1, column)) {
        return true;
    }

    if (column > 0 && heightMap[row][column - 1] < currentValue && flowsOff(row, column - 1)) {
        return true;
    }

    if (row < heightMap[row].size() - 1 &&  heightMap[row + 1][column] < currentValue && flowsOff(row + 1, column)) {
        return true;
    }

    if (column < heightMap[row].size() - 1 && heightMap[row][column + 1] < currentValue && flowsOff(row, column + 1)) {
        return true;
    }

    return false;
}

void WaterFlow4::printAfterRain() const noexcept {
    for (size_t i = 0; i < heightMap.size(); ++i) {
        for (size_t j = 0; j < heightMap[i].size(); ++j) {
            if (flowsOff(i, j)) {
                std::cout << "-";
            }
            else {
                std::cout << "W";
            }
        }
        std::cout << std::endl;
    }
}