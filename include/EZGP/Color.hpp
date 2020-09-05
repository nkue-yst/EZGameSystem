/**
 * @file Color.hpp
 * @brief êFä÷òA
 * @author Yoshito Nakaue
 * @date 2020/09/05
 */


#pragma once
#include <cstdint>

namespace ezgp
{
    struct Color
    {
    public:
        Color(uint8_t R, uint8_t G, uint8_t B, uint8_t A = 255);

        uint8_t red;
        uint8_t green;
        uint8_t blue;
        uint8_t alpha;
    };
}
