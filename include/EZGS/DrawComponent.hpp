/**
 * @file DrawComponent.hpp
 * @brief 描画用コンポーネントクラス
 * @author Yoshito Nakaue
 * @date 2020/08/16
 */

#pragma once
#include <EZGS/Component.hpp>
#include <string>

namespace ezgs
{
    /**
     * @brief 描画用コンポーネントクラス
     */
    class DrawComponent : public Component
    {
    public:
        /**
         * @brief システムに自身を追加
         * @param owner : 所有アクター
         * @param image_name : 割り当てテクスチャ名（画像ファイル名）
         * @param draw_order : 描画優先度
         */
        DrawComponent(class Actor* owner, const std::string& image_name, int draw_order = 100);

        /**
         * @brief システムから自身を削除
         */
        ~DrawComponent();

        /**
         * @brief 描画を実行
         * @param shader : 使用するシェーダークラス
         * @return なし
         */
        virtual void Draw(class Shader* shader);

        /**
         * @brief テクスチャを設定
         * @param texture : 設定するテクスチャ
         * @return なし
         */
        virtual void SetTexture(class Texture* texture);

        /* Getter */
        int GetTextureWidth()  const { return texture_width_;  }
        int GetTextureHeight() const { return texture_height_; }
        int GetDrawOrder()     const { return draw_order_; }

    private:
        class Texture* texture_;
        int texture_width_;
        int texture_height_;

        int draw_order_;
    };
}