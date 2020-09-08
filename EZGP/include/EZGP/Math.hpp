/**
 * @file Math.hpp
 * @brief �v�Z������
 * @author Yoshito Nakaue
 * @date 2020/09/08
 */

#pragma once

namespace ezgp
{
    struct Vec2
    {
        int x;
        int y;
    };

    /**
     * @brief �w��͈͓��̃����_���Ȑ����l��Ԃ�
     * @param min �ŏ��l
     * @param max �ő�l
     * @return �ő�E�ŏ��l���܂ޔ͈͓��̐����l
     */
    int RandomInt(int min, int max);
}
