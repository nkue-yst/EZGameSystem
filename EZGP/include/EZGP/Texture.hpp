/**
 * @file Texture.hpp
 * @brief テクスチャ管理クラス
 * @author Yoshito Nakaue
 * @date 2020/09/06
 */

#pragma once
#include <SDL.h>

namespace ezgp
{
    /**
     * @brief テクスチャ管理クラス
     */
    class Texture
    {
    public:
        // ファイル名を指定して読み込み
        Texture(const char* file_name);
        ~Texture();

        /**
         * @brief 指定座標に画像を描画
         * @param x x座標
         * @param y y座標
         * @return なし
         */
        void draw(int x, int y);

        /**
         * @brief 指定したサイズに拡大縮小
         * @param width リサイズ後の横幅
         * @param height リサイズ後の高さ
         * @return なし
         */
        void resize(int width, int height);

        /**
         * @brief 拡大縮小させて描画する
         * @param x x座標
         * @param y y座標
         * @param width リサイズ後の横幅
         * @param height リサイズ後の高さ
         * @return なし
         */
        void resizeAt(int x, int y, int width, int height);

        /**
         * @brief 画像を回転させて描画する
         * @param x x座標
         * @param y y座標
         * @param angle 回転角度(度数法)
         * @return なし
         */
        void rotateAt(int x, int y, int angle);

        /* Getter */
        const int GetWidth()  const { return width_; }
        const int GetHeight() const { return height_; }

    private:
        /**
         * @brief 画像データを読み込む
         * @param file_name : 画像ファイル名
         * @return 画像から作成したテクスチャ
         */
        SDL_Texture* LoadImage(const char* file_name);

        /**
         * @brief 画像データを削除
         * @return なし
         */
        void UnloadImage();

        // テクスチャデータ
        SDL_Texture* texture_;

        // 画像の横幅
        int width_;

        // 画像の高さ
        int height_;
    };
}
