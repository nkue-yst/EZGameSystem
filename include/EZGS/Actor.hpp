/**
 * @file Actor.hpp
 * @brief �A�N�^�[�N���X
 * @author Yoshito Nakaue
 * @date 2020/08/11
 */

#pragma once
#include <EZGS/Math.hpp>
#include <vector>

namespace ezgs
{		
    /**
     * @brief �A�N�^�[�̏�ԃN���X
     */
    enum class State
    {
        EPause,
        EActive,
        EDead,
    };

    /**
     * @brief �A�N�^�[���N���X
     */
    class Actor
    {
    public:
        /**
         * @brief �V�X�e���ɃA�N�^�[��ǉ�
         */
        Actor();

        /**
         * @brief �V�X�e������A�N�^�[���폜
         */
        virtual ~Actor();

        /**
         * @brief �A�N�^�[�S�̂̍X�V
         * @return �Ȃ�
         */
        void Update(float dt);

        /**
         * @brief �A�N�^�[���g�̍X�V
         * @return �Ȃ�
         */
        virtual void UpdateActor(float dt);

        /**
         * @brief �A�N�^�[�ɃR���|�[�l���g��ǉ�
         * @return �Ȃ�
         */
        void AddComponent(class Component* component);

        /**
         * @brief �A�N�^�[����R���|�[�l���g���폜
         * @return �Ȃ�
         */
        void RemoveComponent(class Component* component);

        /**
         * @brief ���[���h���W���v�Z
         * @return �Ȃ�
         */
        void ComputeWorldTransform();

        /* Setter */
        void SetState(State state) { state_ = state; }
        void SetPosition(const Vec2& pos) { position_ = pos; need_recompute_world_transform_ = true; }
        void SetRotation(const float rot) { rotation_ = rot; need_recompute_world_transform_ = true; }
        void SetScale(const float scl)    { scale_    = scl; need_recompute_world_transform_ = true; }

        /* Getter */
        const State GetState() const { return state_; }
        const Mat4& GetWorldTransform() const { return world_translation_; }
        const Vec2& GetPosition() const { return position_; }
        const float GetRotation() const { return rotation_; }
        const float GetScale() const { return scale_; }

        /**
         * @brief �O���������v�Z
         * @return �O�������������x�N�g��
         */
        Vec2 GetForward() const { return Vec2(std::cos(rotation_), std::sin(rotation_)); }

    private:
        // �A�N�^�[�̏��
        State state_;

        // ���[���h���W
        Mat4 world_translation_;

        // ���[���h���W�̍Čv�Z���K�v���ۂ�
        bool need_recompute_world_transform_;

        // ���W
        Vec2 position_;

        // ��]
        float rotation_;

        // �傫��
        float scale_;

        // ���L���Ă���R���|�[�l���g�z��i�X�V�D��x���j
        std::vector<class Component*> components_;
    };
}
