/**
 * @file Rectangle.hpp
 * @brief �����`�֘A
 * @author Yoshito Nakaue
 * @date 2020/10/31
 */

#pragma once
#include <EZGP/Color.hpp>

namespace ezgp
{
    class Rect
    {
    public:
        Rect(int x, int y, int width, int height);
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
         * @param color �h��Ԃ��F
         * @return �Ȃ�
         */
        void draw(Color color = Color(0, 0, 0))
        {
            draw(x_, y_, width_, height_, color);
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
         * @param color �h��Ԃ��F
         * @return �Ȃ�
         */
        void drawFrame(Color color = Color(0, 0, 0))
        {
            drawFrame(x_, y_, width_, height_, color);
        }

        /**
         * @brief �}�E�X���d�Ȃ��Ă��邩�𔻒�
         * @return �d�Ȃ��Ă����true, �d�Ȃ��Ă��Ȃ����false
         */
        bool mouseOver();

    private:
        int x_;
        int y_;
        int width_;
        int height_;
    };
}