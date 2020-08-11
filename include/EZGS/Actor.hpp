/**
 * @file Actor.hpp
 * @brief �A�N�^�[�N���X
 * @author Yoshito Nakaue
 * @date 2020/08/11
 */

#pragma once
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

    private:
        // �A�N�^�[�̏��
        State state_;

        // ���L���Ă���R���|�[�l���g�z��i�X�V�D��x���j
        std::vector<class Component*> components_;
    };
}
