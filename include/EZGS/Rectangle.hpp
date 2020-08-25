/**
 * @file Rectangle.hpp
 * @brief �����`�֘A
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
         * @brief �T�C�Y�E���W���w�肵�ĕ`�悷��
         * @param x x���W
         * @param y y���W
         * @param width ����
         * @param height ����
         * @return �Ȃ�
         */
        static void draw(int x, int y, int width, int height);

        /**
         * @brief ���W���w�肵�ĕ`�悷��
         * @param x x���W
         * @param y y���W
         * @return �Ȃ�
         */
        void draw(int x, int y) { draw(x, y, width_, height_); }

    private:
        int width_;
        int height_;
    };
}