#pragma once
#include "WaterFlowDown.h"

//Unterklasse von WaterFlowDown

class WaterFlow4 : public WaterFlowDown {
public:
    WaterFlow4() noexcept;
    WaterFlow4(const std::vector<std::vector<size_t>>& _heightMap) noexcept;
    WaterFlow4(const size_t numRows, const size_t numColumns) noexcept;

    [[nodiscard]] const bool flowsOff(const size_t row, const size_t column) const noexcept override;
    void printAfterRain() const noexcept override;
};

