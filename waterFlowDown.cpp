#include "waterFlowDown.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

//verlangt die rechteckige zweidimensionale Karte heightMap als Paramete
WaterFlowDown::WaterFlowDown(const std::vector<std::vector<size_t>>& _heightMap) noexcept:
 heightMap(_heightMap) {}

//erstellt eine zufällige Karte der angegebenen Größe
WaterFlowDown::WaterFlowDown(const size_t numRows, const size_t numColumns) noexcept {
    generateHeightmap(numRows, numColumns);
}
//Der Konstruktor ohne Parameter
WaterFlowDown::WaterFlowDown() noexcept {
    generateHeightmap(5, 5);
}
//gibt die Karte zurück
const std::vector<std::vector<size_t>>& WaterFlowDown::getHeightMap() const noexcept {
    return heightMap;
}
//soll es erlauben, eine Karte anzugeben
void WaterFlowDown::setHeightmap(const std::vector<std::vector<size_t>>& _heightMap) noexcept {
    heightMap = _heightMap;
}
//erstellt eine zufällige random zweidimensionale Karte der angegebenen Größe
void WaterFlowDown::generateHeightmap(const size_t numRows, const size_t numColumns) noexcept {
    heightMap.resize(numRows, std::vector<size_t>(numColumns));
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    for (size_t i = 0; i < numRows; ++i) {
        for (size_t j = 0; j < numColumns; ++j) {
            heightMap[i][j] = std::rand() % 90 + 10;
        }
    }
}
//Die gesamte Karte gibt durch print aus
void WaterFlowDown::printHeightmap() const noexcept {
    for (const auto& row : heightMap) {
        for (const size_t value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}
// kontrolliert,ob wasser über den Rand der Karte abfließen kann
const bool WaterFlowDown::flowsOff(const size_t row, const size_t column) const noexcept {
   
    const size_t currentValue = heightMap[row][column];

    if (row == heightMap.size() - 1) {
        return true;
    }

    if (heightMap[row + 1][column] < currentValue && flowsOff(row + 1, column)) {
        return true;
    }

    return false;
}
//den Zustand der Landschaft nach starkem Regen 
void WaterFlowDown::printAfterRain() const noexcept {
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
    std::cout <<"\n"<< std::endl;
}