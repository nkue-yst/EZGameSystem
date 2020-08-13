/**
 * @file MoveComponent.hpp
 * @brief �ړ������R���|�[�l���g
 * @author Yoshito Nakaue
 * @date 2020/08/13
 */

#pragma once
#include <EZGS/Component.hpp>

namespace ezgs
{
    /**
     * @brief �ړ������R���|�[�l���g�N���X
     */
    class MoveComponent : public Component
    {
    public:
        MoveComponent(class Actor* owner, int update_order = 10);

        /**
         * @brief �e�A�N�^�[�̍��W�X�V
         * @param dt : �X�V����
         * @return �Ȃ�
         */
        void Update(float dt) override;

        /* Setter */
        void setForwardSpeed(float speed) { forward_speed_ = speed; }
        void setAngularSpeed(float speed) { angular_speed_ = speed; }

        /* Getter */
        float getForwardSpeed() const { return forward_speed_; }
        float getAngularSpeed() const { return angular_speed_; }


    private:
        // �O�������ւ̑��x
        float forward_speed_;

        // ��]���x
        float angular_speed_;
    };
}