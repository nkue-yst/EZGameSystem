/**
 * @file Triangle.hpp
 * @brief �O�p�`�N���X
 * @author Yoshito Nakaue
 * @date 2020/09/05
 */

#pragma once
#include <EZGP/Color.hpp>

namespace ezgp
{
    class Triangle
    {
    public:
        // 3�_�̍��W���w�肵�ď�����
        Triangle(int x1, int y1, int x2, int y2, int x3, int y3);

        /**
         * @brief �F���w�肵�ĕ`�悷��
         * @param color �h��Ԃ��F
         * @return �Ȃ�
         */
        void draw(Color color = Color(0, 0, 0));

        /**
         * @brief �F���w�肵�Ęg��`�悷��
         * @param color �h��Ԃ��F
         * @return �Ȃ�
         */
        void drawFrame(Color color = Color(0, 0, 0));

    private:
        int x_[3];
        int y_[3];
    };
}