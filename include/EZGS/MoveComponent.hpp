/**
 * @file MoveComponent.hpp
 * @brief 移動処理コンポーネント
 * @author Yoshito Nakaue
 * @date 2020/08/13
 */

#pragma once
#include <EZGS/Component.hpp>

namespace ezgs
{
    /**
     * @brief 移動処理コンポーネントクラス
     */
    class MoveComponent : public Component
    {
    public:
        MoveComponent(class Actor* owner, int update_order = 10);

        /**
         * @brief 親アクターの座標更新
         * @param dt : 更新時間
         * @return なし
         */
        void Update(float dt) override;

        /* Setter */
        void setForwardSpeed(float speed) { forward_speed_ = speed; }
        void setAngularSpeed(float speed) { angular_speed_ = speed; }

        /* Getter */
        float getForwardSpeed() const { return forward_speed_; }
        float getAngularSpeed() const { return angular_speed_; }


    private:
        // 前方方向への速度
        float forward_speed_;

        // 回転速度
        float angular_speed_;
    };
}