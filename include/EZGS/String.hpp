/**
 * @file String.hpp
 * @brief 文字列クラス
 * @author Yoshito Nakaue
 * @date 2020/08/21
 */

#pragma once
#include <SDL.h>
#include <SDL_ttf.h>

namespace ezgs
{
    // 文字列クラス
    class String
    {
    public:
        String(const char* str);

        // 描画関数
        void draw();

    private:
        /**
         * @brief テクスチャを作成する
         * @return 作成したテクスチャを返す
         */
        void GenTexture(SDL_Surface* surface);

        // 文字列
        const char* string_;

        // フォント
        TTF_Font* font_type_;

        unsigned int texture_id_;
    };
}