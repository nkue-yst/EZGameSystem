/**
 * @file Rectangle.hpp
 * @brief 長方形関連
 * @author Yoshito Nakaue
 * @date 2020/09/05
 */

#pragma once
#include <EZGP/Color.hpp>

namespace ezgp
{
    class Rect
    {
    public:
        Rect(int width, int height);
        ~Rect();

        /**
         * @brief サイズ・座標を指定して描画する
         * @param x x座標
         * @param y y座標
         * @param width 横幅
         * @param height 高さ
         * @param color 塗りつぶす色
         * @return なし
         */
        static void draw(int x, int y, int width, int height, Color color = Color(0, 0, 0));

        /**
         * @brief 座標を指定して描画する
         * @param x x座標
         * @param y y座標
         * @param color 塗りつぶす色
         * @return なし
         */
        void draw(int x, int y, Color color = Color(0, 0, 0))
        {
            draw(x, y, width_, height_, color);
        }

        /**
         * @brief サイズ・座標を指定して枠を描画する
         * @param x x座標
         * @param y y座標
         * @param width 横幅
         * @param height 高さ
         * @param color 色
         * @return なし
         */
        static void drawFrame(int x, int y, int width, int height, Color color = Color(0, 0, 0));

        /**
         * @brief 座標を指定して枠を描画する
         * @param x x座標
         * @param y y座標
         * @param color 塗りつぶす色
         * @return なし
         */
        void drawFrame(int x, int y, Color color = Color(0, 0, 0))
        {
            drawFrame(x, y, width_, height_, color);
        }

    private:
        int width_;
        int height_;
    };
}