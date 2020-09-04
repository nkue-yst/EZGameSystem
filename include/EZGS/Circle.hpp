/**
 * @file Circle.hpp
 * @brief �~�֘A
 * @author Yoshito Nakaue
 * @date 2020/09/04
 */

#pragma once
#include <EZGS/Color.hpp>

namespace ezgs
{
    class Circle
    {
    public:
        // ���~
        Circle(int rad);

        /**
         * @brief �T�C�Y�E���W���w�肵�đȉ~��`�悷��
         * @param x x���W
         * @param y y���W
         * @param rad ���a
         * @param color �h��Ԃ��F
         * @return �Ȃ�
         */
        static void draw(int x, int y, int rad, Color color = Color(0, 0, 0))
        {
            draw(x, y, rad, rad, color);
        }

        /**
         * @brief �T�C�Y�E���W���w�肵�đȉ~�̘g��`�悷��
         * @param x x���W
         * @param y y���W
         * @param rad_x x�����̔��a
         * @param rad_y y�����̔��a
         * @param color �F
         * @return �Ȃ�
         */
        static void drawFrame(int x, int y, int rad, Color color = Color(0, 0, 0))
        {
            drawFrame(x, y, rad, rad, color);
        }


        // �ȉ~
        Circle(int rad_x, int rad_y);

        /**
         * @brief �T�C�Y�E���W���w�肵�đȉ~��`�悷��
         * @param x x���W
         * @param y y���W
         * @param rad_x x�����̔��a
         * @param rad_y y�����̔��a
         * @param color �h��Ԃ��F
         * @return �Ȃ�
         */
        static void draw(int x, int y, int rad_x, int rad_y, Color color = Color(0, 0, 0));

        /**
         * @brief �T�C�Y�E���W���w�肵�đȉ~�̘g��`�悷��
         * @param x x���W
         * @param y y���W
         * @param rad_x x�����̔��a
         * @param rad_y y�����̔��a
         * @param color �F
         * @return �Ȃ�
         */
        static void drawFrame(int x, int y, int rad_x, int rad_y, Color color = Color(0, 0, 0));


        /* ���~�E�ȉ~���ʊ֐� */

        /**
         * @brief ���W���w�肵�ĉ~��`�悷��
         * @param x x���W
         * @param y y���W
         * @param color �h��Ԃ��F
         * @return �Ȃ�
         */
        void draw(int x, int y, Color color = Color(0, 0, 0))
        {
            draw(x, y, rad_x_, rad_y_, color);
        }

        /**
         * @brief ���W���w�肵�đȉ~�̘g��`�悷��
         * @param x x���W
         * @param y y���W
         * @param color �h��Ԃ��F
         * @return �Ȃ�
         */
        void drawFrame(int x, int y, Color color = Color(0, 0, 0))
        {
            drawFrame(x, y, rad_x_, rad_y_, color);
        }
        
    private:
        int rad_x_;
        int rad_y_;
    };
}
