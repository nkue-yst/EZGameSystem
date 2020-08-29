/**
 * @file Line.hpp
 * @brief 線
 * @author Yoshito Nakaue
 * @date 2020/08/29
 */

#pragma once
#include <EZGS/Color.hpp>

namespace ezgs
{
    class Line
    {
    public:
        /**
         * @brief 始点、終点を指定して初期化
         * @param x1 始点のx座標
         * @param y1 始点のy座標
         * @param x2 終点のx座標
         * @param x2 終点のy座標
         */
        Line(int x1, int y1, int x2, int y2);

        /**
         * @brief 始点、終点、太さ、色を指定して初期化
         * @param x1 始点のx座標
         * @param y1 始点のy座標
         * @param x2 終点のx座標
         * @param x2 終点のy座標
         * @param thick 線の太さ
         * @param color 線の色
         */
        static void draw(int x1, int y1, int x2, int y2, int thick, Color color = Color(0, 0, 0));

        /**
         * @brief 太さ、色を指定して線を描画する
         * @param thick 線の太さ
         * @param color 線の色
         * @return なし
         */
        void draw(int thick, Color color = Color(0, 0, 0))
        {
            draw(x1_, y1_, x2_, y2_, thick, color);
        }

    private:
        int x1_, y1_;
        int x2_, y2_;
    };
}
