/**
 * @file Component.hpp
 * @brief �R���|�[�l���g�N���X
 * @author Yoshito Nakaue
 * @date 2020/08/11
 */

#pragma once

namespace ezgs
{
    /**
     * @brief �R���|�[�l���g���N���X
     */
    class Component
    {
    public:
        /**
         * @brief ���L�A�N�^�[�A�X�V�D��x��ݒ�
         */
        Component(class Actor* owner, int update_order);

        /**
         * @brief ���L�A�N�^�[����R���|�[�l���g���폜
         */
        virtual ~Component();

        /**
         * @brief �R���|�[�l���g�̍X�V
         * @return �Ȃ�
         */
        virtual void Update(float dt);

        /**
         * @brief ���[���h���W�̌v�Z
         * @return �Ȃ�
         */
        virtual void NotifiedUpdateWorldTransform() {};

        /**
         * @brief �X�V�D��x�̎擾
         * @return �R���|�[�l���g�̍X�V�D��x�i�����l�j
         */
        int GetUpdateOrder() const { return update_order_; }

    protected:
        // ���L�A�N�^�[
        class Actor* owner_;

        // �X�V�D��x
        int update_order_;
    };
}
