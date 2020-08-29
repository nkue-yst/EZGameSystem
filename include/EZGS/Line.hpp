/**
 * @file Line.hpp
 * @brief ��
 * @author Yoshito Nakaue
 * @date 2020/08/29
 */

#pragma once
#include <EZGS/Color.hpp>

namespace ezgs
{
    class Line
    {
    public:
        /**
         * @brief �n�_�A�I�_���w�肵�ď�����
         * @param x1 �n�_��x���W
         * @param y1 �n�_��y���W
         * @param x2 �I�_��x���W
         * @param x2 �I�_��y���W
         */
        Line(int x1, int y1, int x2, int y2);

        /**
         * @brief �n�_�A�I�_�A�����A�F���w�肵�ď�����
         * @param x1 �n�_��x���W
         * @param y1 �n�_��y���W
         * @param x2 �I�_��x���W
         * @param x2 �I�_��y���W
         * @param thick ���̑���
         * @param color ���̐F
         */
        static void draw(int x1, int y1, int x2, int y2, int thick, Color color = Color(0, 0, 0));

        /**
         * @brief �����A�F���w�肵�Đ���`�悷��
         * @param thick ���̑���
         * @param color ���̐F
         * @return �Ȃ�
         */
        void draw(int thick, Color color = Color(0, 0, 0))
        {
            draw(x1_, y1_, x2_, y2_, thick, color);
        }

    private:
        int x1_, y1_;
        int x2_, y2_;
    };
}
