/**
 * @file Rectangle.hpp
 * @brief �����`�֘A
 * @author Yoshito Nakaue
 * @date 2020/08/26
 */

#pragma once
#include <EZGS/Color.hpp>

namespace ezgs
{
    class Rect
    {
    public:
        Rect(int width, int height);
        ~Rect();

        /**
         * @brief �T�C�Y�E���W���w�肵�ĕ`�悷��
         * @param x x���W
         * @param y y���W
         * @param width ����
         * @param height ����
         * @param color �h��Ԃ��F
         * @return �Ȃ�
         */
        static void draw(int x, int y, int width, int height, Color color = Color(0, 0, 0));

        /**
         * @brief ���W���w�肵�ĕ`�悷��
         * @param x x���W
         * @param y y���W
         * @return �Ȃ�
         */
        void draw(int x, int y, Color color = Color(0, 0, 0))
        {
            draw(x, y, width_, height_, color);
        }

    private:
        int width_;
        int height_;
    };
}