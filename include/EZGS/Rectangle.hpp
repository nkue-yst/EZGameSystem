/**
 * @file Rectangle.hpp
 * @brief 長方形関連
 * @author Yoshito Nakaue
 * @date 2020/08/25
 */

#pragma once

namespace ezgs
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
         * @return なし
         */
        static void draw(int x, int y, int width, int height);

        /**
         * @brief 座標を指定して描画する
         * @param x x座標
         * @param y y座標
         * @return なし
         */
        void draw(int x, int y) { draw(x, y, width_, height_); }

    private:
        int width_;
        int height_;
    };
}