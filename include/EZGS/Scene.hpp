/**
 * @file Scene.hpp
 * @brief ウィンドウ描画関連
 * @author Yoshito Nakaue
 * @date 2020/08/18
 */

#pragma once

namespace ezgs
{
    namespace Scene
    {
        /**
         * @brief 色を扱う構造体
         */
        class Color {
        public:
            Color()
            {
                red  = 0.0f;  green = 0.0f;
                blue = 0.0f;  alpha = 0.0f;
            }

            Color(float Red, float Green, float Blue, float Alpha = 0.0f)
            {
                red = Red;   green = Green;
                blue = Blue;  alpha = Alpha;
            }

            float red;
            float green;
            float blue;
            float alpha;
        };
        // 背景色
        static Color bg_color;

        /**
         * @brief 背景色を設定
         * @param red : 赤 0.0 ~ 1.0
         * @param green : 緑 0.0 ~ 1.0
         * @param blue : 青 0.0 ~ 1.0
         * @param alpha : 透明度 (default)0.0 ~ 1.0
         * @return なし
         */
        void SetBackgroundColor(float red, float green, float blue, float alpha = 0.0f);
    }
}