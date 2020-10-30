/**
 * @file Rectangle.hpp
 * @brief �����`�֘A
 * @author Yoshito Nakaue
 * @date 2020/09/12
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
         * @param color �h��Ԃ��F
         * @return �Ȃ�
         */
        void draw(int x, int y, Color color = Color(0, 0, 0))
        {
            draw(x, y, width_, height_, color);
        }

        /**
         * @brief �T�C�Y�E���W���w�肵�Ęg��`�悷��
         * @param x x���W
         * @param y y���W
         * @param width ����
         * @param height ����
         * @param color �F
         * @return �Ȃ�
         */
        static void drawFrame(int x, int y, int width, int height, Color color = Color(0, 0, 0));

        /**
         * @brief ���W���w�肵�Ęg��`�悷��
         * @param x x���W
         * @param y y���W
         * @param color �h��Ԃ��F
         * @return �Ȃ�
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