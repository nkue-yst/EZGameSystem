/**
 * @file Actor.hpp
 * @brief アクタークラス
 * @author Yoshito Nakaue
 * @date 2020/08/11
 */

#pragma once
#include <vector>

namespace ezgs
{		
    /**
     * @brief アクターの状態クラス
     */
    enum class State
    {
        EPause,
        EActive,
        EDead,
    };

    /**
     * @brief アクター基底クラス
     */
    class Actor
    {
    public:
        /**
         * @brief システムにアクターを追加
         */
        Actor();

        /**
         * @brief システムからアクターを削除
         */
        virtual ~Actor();

        /**
         * @brief アクター全体の更新
         * @return なし
         */
        void Update(float dt);

        /**
         * @brief アクター自身の更新
         * @return なし
         */
        virtual void UpdateActor(float dt);

        /**
         * @brief アクターにコンポーネントを追加
         * @return なし
         */
        void AddComponent(class Component* component);

        /**
         * @brief アクターからコンポーネントを削除
         * @return なし
         */
        void RemoveComponent(class Component* component);

    private:
        // アクターの状態
        State state_;

        // 所有しているコンポーネント配列（更新優先度順）
        std::vector<class Component*> components_;
    };
}
