/**
 * @file DrawComponent.hpp
 * @brief 描画用コンポーネントクラス
 * @author Yoshito Nakaue
 * @date 2020/08/13
 */

#pragma once
#include <EZGS/Component.hpp>

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
         */
        DrawComponent(class Actor* owner, int draw_order = 100);

        /**
         * @brief システムから自身を削除
         */
        ~DrawComponent();

        /**
         * @brief 描画を実行
         * @return なし
         */
        virtual void Draw();

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