/**
 * @file Scene.hpp
 * @brief �E�B���h�E�`��֘A
 * @author Yoshito Nakaue
 * @date 2020/08/18
 */

#pragma once

namespace ezgs
{
    namespace Scene
    {
        /**
         * @brief �F�������\����
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
        // �w�i�F
        static Color bg_color;

        /**
         * @brief �w�i�F��ݒ�
         * @param red : �� 0.0 ~ 1.0
         * @param green : �� 0.0 ~ 1.0
         * @param blue : �� 0.0 ~ 1.0
         * @param alpha : �����x (default)0.0 ~ 1.0
         * @return �Ȃ�
         */
        void SetBackgroundColor(float red, float green, float blue, float alpha = 0.0f);
    }
}