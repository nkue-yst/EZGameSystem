/**
 * @file Scene.hpp
 * @brief シーン設定関連
 * @author Yoshito Nakaue
 * @date 2020/08/20
 */

#pragma once

namespace ezgs
{
    namespace Scene
    {
        /**
         * @brief 背景色を設定
         * @param R : 赤 0.0 ~ 1.0
         * @param G : 緑 0.0 ~ 1.0
         * @param B : 青 0.0 ~ 1.0
         * @return なし
         */
        void SetBackgroundColor(float R, float G, float B);
    }
}
