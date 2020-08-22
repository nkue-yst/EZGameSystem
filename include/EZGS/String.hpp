/**
 * @file String.hpp
 * @brief ������N���X
 * @author Yoshito Nakaue
 * @date 2020/08/21
 */

#pragma once
#include <SDL.h>
#include <SDL_ttf.h>

namespace ezgs
{
    // ������N���X
    class String
    {
    public:
        String(const char* str);

        // �`��֐�
        void draw();

    private:
        /**
         * @brief �e�N�X�`�����쐬����
         * @return �쐬�����e�N�X�`����Ԃ�
         */
        void GenTexture(SDL_Surface* surface);

        // ������
        const char* string_;

        // �t�H���g
        TTF_Font* font_type_;

        unsigned int texture_id_;
    };
}