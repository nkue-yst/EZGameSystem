/**
 * @file Actor.hpp
 * @brief �A�N�^�[�N���X
 * @author Yoshito Nakaue
 * @date 2020/08/11
 */

#pragma once

namespace ezgs
{		
    /**
     * @brief Actor�̏�ԃN���X
     */
    enum class State
    {
        EPause,
        EActive,
        EDead,
    };

    /**
     * @brief Actor�N���X
     */
    class Actor
    {
    public:
        /**
         * @brief �V�X�e����Actor�ǉ�
         */
        Actor();

        /**
         * @brief �V�X�e������Actor���폜
         */
        virtual ~Actor();

        /**
         * @brief Actor�S�̂̍X�V
         * @return �Ȃ�
         */
        void Update(float dt);

        /**
         * @brief �A�N�^�[���g�̍X�V
         * @return �Ȃ�
         */
        virtual void UpdateActor(float dt);

    private:
        // Actor�̏��
        State state_;
    };
}
