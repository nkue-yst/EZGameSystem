/**
 * @file Triangle.hpp
 * @brief 三角形クラス
 * @author Yoshito Nakaue
 * @date 2020/09/05
 */

#pragma once
#include <EZGP/Color.hpp>

namespace ezgp
{
    class Triangle
    {
    public:
        // 3点の座標を指定して初期化
        Triangle(int x1, int y1, int x2, int y2, int x3, int y3);

        /**
         * @brief 色を指定して描画する
         * @param color 塗りつぶす色
         * @return なし
         */
        void draw(Color color = Color(0, 0, 0));

        /**
         * @brief 色を指定して枠を描画する
         * @param color 塗りつぶす色
         * @return なし
         */
        void drawFrame(Color color = Color(0, 0, 0));

    private:
        int x_[3];
        int y_[3];
    };
}