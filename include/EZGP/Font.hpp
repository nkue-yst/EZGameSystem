/**
 * @file Font.hpp
 * @brief フォント関連
 * @author Yoshito Nakaue
 * @date 2020/09/05
 */

#pragma once
#include <unordered_map>
#include <vector>
#include <SDL_ttf.h>

namespace ezgp
{
    /**
     * @brief フォント管理クラス
     */
    class Font
    {
    public:
        Font(int size);
        ~Font();

        /**
         * @brief 描画する
         * @param str 描画する文字列
         * @return なし
         */
        void draw(const char* str) { draw(str, 0, 0); }

        /**
         * @brief 描画する
         * @param str 描画する文字列
         * @param x : x座標
         * @param y : y座標
         * @return 成功時 0、失敗時 1
         */
        int draw(const char* str, int x, int y);

        /**
         * @brief フォントサイズを取得
         * @return フォントサイズ : int
         */
        int GetSize() { return size_; }

    private:
        // フォントサイズ
        int size_;

        // フォント
        TTF_Font* font_type_;
    };
}