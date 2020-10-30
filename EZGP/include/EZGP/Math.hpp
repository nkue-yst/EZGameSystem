/**
 * @file Math.hpp
 * @brief 計算処理等
 * @author Yoshito Nakaue
 * @date 2020/09/08
 */

#pragma once

namespace ezgp
{
    struct Vec2
    {
        int x;
        int y;
    };

    /**
     * @brief 指定範囲内のランダムな整数値を返す
     * @param min 最小値
     * @param max 最大値
     * @return 最大・最小値を含む範囲内の整数値
     */
    int RandomInt(int min, int max);
}
