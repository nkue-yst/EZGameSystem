/**
 * @author Yoshito Nakaue
 * @date 2020/08/11
 */

#include <EZGS/Component.hpp>
#include <EZGS/Actor.hpp>

namespace ezgs
{
    Component::Component(Actor* owner, int update_order)
        :owner_(owner)
        ,update_order_(update_order)
    {
        owner_->AddComponent(this);
    }

    Component::~Component()
    {
        owner_->RemoveComponent(this);
    }

    void Component::Update(float dt)
    {

    }
}