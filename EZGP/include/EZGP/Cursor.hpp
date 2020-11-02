/**
 * @file Cursor.hpp
 * @brief カーソル関連
 * @author Yoshito Nakaue
 * @date 2020/11/02
 */

#pragma once
#include <EZGP/Math.hpp>

namespace ezgp
{
    namespace Cursor
    {
        constexpr int NONE      = 0b0000;
        constexpr int LEFT_ON   = 0b0001;
        constexpr int RIGHT_ON  = 0b0010;
        constexpr int MIDDLE_ON = 0b0100;

        Vec2 Pos();
    }
}
