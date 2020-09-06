/**
 * @file Scene.hpp
 * @brief シーン設定関連
 * @author Yoshito Nakaue
 * @date 2020/09/05
 */

#pragma once
#include <cstdint>

namespace ezgp
{
    namespace Scene
    {
        /**
         * @brief 背景色を設定
         * @param R 赤(0~255)
         * @param G 緑(0~255)
         * @param B 青(0~255)
         * @return なし
         */
        void SetBackgroundColor(uint8_t R, uint8_t G, uint8_t B);
    }
}
