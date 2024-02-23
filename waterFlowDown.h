#pragma once
#include <vector>

class WaterFlowDown {
public:
    WaterFlowDown(const std::vector<std::vector<size_t>>& _heightMap) noexcept;
    WaterFlowDown(const size_t numRows, const size_t numColumns) noexcept;
    WaterFlowDown() noexcept;

    [[nodiscard]] const std::vector<std::vector<size_t>>& getHeightMap() const noexcept;
    void setHeightmap(const std::vector<std::vector<size_t>>& _heightMap) noexcept;
    void generateHeightmap(const size_t numRows, const size_t numColumns) noexcept;
    void printHeightmap() const noexcept;
    [[nodiscard]] virtual const bool flowsOff(const size_t row, const size_t column) const noexcept;
    void virtual printAfterRain() const noexcept;
    std::vector<std::vector<size_t>> heightMap;

};

