/**
 * @file Texture.hpp
 * @brief テクスチャ管理クラス
 * @author Yoshito Nakaue
 * @date 2020/09/05
 */

#pragma once
#include <string>

namespace ezgp
{
    /**
     * @brief テクスチャ管理クラス
     */
    class Texture
    {
    public:
        Texture();
        ~Texture();

        /**
         * @brief 画像データを読み込む
         * @param file_name : 画像ファイル名
         * @return 成功時 0、失敗時 1
         */
        int LoadImage(const std::string& file_name);

        /**
         * @brief 画像データを削除
         * @return なし
         */
        void UnloadImage();

        /* Getter */
        const int GetWidth()  const { return width_; }
        const int GetHeight() const { return height_; }

    private:
        // テクスチャID
        unsigned int texture_id_;

        // 画像の横幅
        int width_;

        // 画像の高さ
        int height_;
    };
}