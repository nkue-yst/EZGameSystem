/**
 * @file Circle.hpp
 * @brief �~�֘A
 * @author Yoshito Nakaue
 * @date 2020/10/31
 */

#pragma once
#include <EZGP/Color.hpp>

namespace ezgp
{
    class Circle
    {
    public:
        // ���~
        Circle(int x, int y, int rad);

        /**
         * @brief �T�C�Y�E���W���w�肵�ĉ~��`�悷��
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
         * @brief �T�C�Y�E���W���w�肵�ĉ~�̘g��`�悷��
         * @param x x���W
         * @param y y���W
         * @param rad ���a
         * @param color �F
         * @return �Ȃ�
         */
        static void drawFrame(int x, int y, int rad, Color color = Color(0, 0, 0))
        {
            drawFrame(x, y, rad, rad, color);
        }


        // �ȉ~
        Circle(int x, int y, int rad_x, int rad_y);

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
        void draw(Color color = Color(0, 0, 0))
        {
            draw(x_, y_, rad_x_, rad_y_, color);
        }

        /**
         * @brief ���W���w�肵�đȉ~�̘g��`�悷��
         * @param x x���W
         * @param y y���W
         * @param color �h��Ԃ��F
         * @return �Ȃ�
         */
        void drawFrame(Color color = Color(0, 0, 0))
        {
            drawFrame(x_, y_, rad_x_, rad_y_, color);
        }

        /**
         * @brief �}�E�X���d�Ȃ��Ă��邩�𔻒�
         * @return �d�Ȃ��Ă����true, �d�Ȃ��Ă��Ȃ����false
         */
        bool mouseOver();
        
    private:
        int x_;
        int y_;
        int rad_x_;
        int rad_y_;
    };
}
