/**
 * @file Color.hpp
 * @brief �F�֘A
 * @author Yoshito Nakaue
 * @date 2020/09/10
 */

#pragma once
#include <cstdint>

namespace ezgp
{
    struct Color
    {
    public:
        Color(uint8_t R, uint8_t G, uint8_t B, uint8_t A = 255);

        uint8_t red;
        uint8_t green;
        uint8_t blue;
        uint8_t alpha;

        friend Color operator+(Color a, Color b)
        {
            return Color(
                a.red + b.red,
                a.green + b.green,
                a.blue + b.blue,
                255
            );
        }

        friend Color operator-(Color a, Color b)
        {
            return Color(
                a.red - b.red,
                a.green - b.green,
                a.blue - b.blue,
                255
            );
        }

        static const Color AZURE;    // azure
        static const Color BLACK;    // ��
        static const Color BLUE;     // ��
        static const Color BROWN;    // ��
        static const Color CREAM;    // �N���[���F
        static const Color CYAN;     // �V�A��
        static const Color GRAY;     // �D�F
        static const Color GREEN;    // ��
        static const Color IVORY;    // �A�C�{���[
        static const Color KHAKI;    // �J�[�L
        static const Color LEMON;    // �������C�G���[
        static const Color LIME;     // ���C���O���[��
        static const Color MAGENTA;  // �}�[���^
        static const Color NAVY;     // �l�C�r�[
        static const Color ORANGE;   // �I�����W
        static const Color PINK;     // �s���N
        static const Color PURPLE;   // ��
        static const Color RED;      // ��
        static const Color SKY;      // �X�J�C�u���[
        static const Color SNOW;     // �X�m�E�z���C�g
        static const Color VIOLET;   // �o�C�I���b�g
        static const Color WHITE;    // ��
        static const Color YELLOW;   // ��
    };
}
