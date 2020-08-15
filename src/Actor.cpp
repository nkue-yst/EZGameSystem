/**
 * @author Yoshito Nakaue
 * @date 2020/08/11
 */

#include <EZGS/Actor.hpp>
#include <EZGS/Component.hpp>
#include <EZGS/System.hpp>

namespace ezgs
{
    Actor::Actor()
        :state_(State::EActive)
    {
        System::AddActor(this);
    }

    Actor::~Actor()
    {
        System::RemoveActor(this);
    }

    void Actor::Update(float dt)
    {
        if (state_ == State::EActive)
        {
            this->UpdateActor(dt);
        }
    }

    void Actor::UpdateActor(float dt)
    {

    }

    void Actor::UpdateComponents(float dt)
    {
        for (auto component : components_)
            component->Update(dt);
    }

    void Actor::AddComponent(Component* component)
    {
        int own_order = component->GetUpdateOrder();
        auto iter = components_.begin();
        for (; iter != components_.end(); ++iter)
        {
            if (own_order < (*iter)->GetUpdateOrder())
                break;
        }
        components_.insert(iter, component);
    }

    void Actor::RemoveComponent(Component* component)
    {
        auto iter = std::find(components_.begin(), components_.end(), component);
        if (iter != components_.end())
            components_.erase(iter);
    }

    void Actor::ComputeWorldTransform()
    {
        if (need_recompute_world_transform_)
        {
            need_recompute_world_transform_ = false;

            world_translation_  = Mat4::CreateScale(scale_);
            world_translation_ *= Mat4::RotationZ(rotation_);
            world_translation_ *= Mat4::Translation(Vec3(position_.x, position_.y, 0.0f));

            for (auto compo : components_)
                compo->NotifiedUpdateWorldTransform();
        }
    }
}