/**
 * @file DrawComponent.hpp
 * @brief �`��p�R���|�[�l���g�N���X
 * @author Yoshito Nakaue
 * @date 2020/08/13
 */

#pragma once
#include <EZGS/Component.hpp>

namespace ezgs
{
    /**
     * @brief �`��p�R���|�[�l���g�N���X
     */
    class DrawComponent : public Component
    {
    public:
        /**
         * @brief �V�X�e���Ɏ��g��ǉ�
         */
        DrawComponent(class Actor* owner, int draw_order = 100);

        /**
         * @brief �V�X�e�����玩�g���폜
         */
        ~DrawComponent();

        /**
         * @brief �`������s
         * @return �Ȃ�
         */
        virtual void Draw();

        /**
         * @brief �e�N�X�`����ݒ�
         * @param texture : �ݒ肷��e�N�X�`��
         * @return �Ȃ�
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