/**
 * @file Font.hpp
 * @brief �t�H���g�֘A
 * @author Yoshito Nakaue
 * @date 2020/08/21
 */

#pragma once
#include <unordered_map>
#include <vector>
#include <SDL_ttf.h>

namespace ezgs
{
    /**
     * @brief �t�H���g�Ǘ��N���X
     */
    class Font
    {
    public:
        Font(int size);
        ~Font();

        /**
         * @brief �`�悷��
         * @return �Ȃ�
         */
        void draw(const char* str) { draw(str, 0, 0); }

        /**
         * @brief �`�悷��
         * @param x : x���W
         * @param y : y���W
         * @return ������ 0�A���s�� 1
         */
        int draw(const char* str, int x, int y);

        /**
         * @brief �t�H���g�T�C�Y���擾
         * @return �t�H���g�T�C�Y : int
         */
        int GetSize() { return size_; }

    private:
        // �t�H���g�T�C�Y
        int size_;

        // �t�H���g
        TTF_Font* font_type_;

        // ������z��
        std::unordered_map<const char*, class String*> strings;
    };
}