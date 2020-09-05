/**
 * @file Scene.hpp
 * @brief �V�[���ݒ�֘A
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
         * @brief �w�i�F��ݒ�
         * @param R ��(0~255)
         * @param G ��(0~255)
         * @param B ��(0~255)
         * @return �Ȃ�
         */
        void SetBackgroundColor(uint8_t R, uint8_t G, uint8_t B);
    }
}
