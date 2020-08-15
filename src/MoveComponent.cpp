/**
 * @author Yoshito Nakaue
 * @date 2020/08/15
 */

#include <EZGS/MoveComponent.hpp>
#include <EZGS/Actor.hpp>
#include <EZGS/Math.hpp>

namespace ezgs
{
    MoveComponent::MoveComponent(class Actor* owner, int update_order)
        :Component(owner, update_order)
        , forward_speed_(0.0f)
        , angular_speed_(0.0f)
    {

    }

    void MoveComponent::Update(float dt)
    {
        float rot = owner_->GetRotation();
        rot += angular_speed_ * dt;
        owner_->SetRotation(rot);

        Vec2 pos = owner_->GetPosition();
        pos += owner_->GetForward() * forward_speed_ * dt;
        owner_->SetPosition(pos);
    }
}