/**
 * @author Yoshito Nakaue
 * @date 2020/08/16
 */

#include <EZGS/DrawComponent.hpp>
#include <EZGS/Actor.hpp>
#include <EZGS/Math.hpp>
#include <EZGS/Shader.hpp>
#include <EZGS/System.hpp>
#include <EZGS/Texture.hpp>

namespace ezgs
{
    DrawComponent::DrawComponent(Actor* owner, const std::string& image_name, int draw_order)
        :Component(owner)
        , texture_(nullptr)
        , texture_width_(0)
        , texture_height_(0)
        , draw_order_(draw_order)
    {
        System::AddDrawComponent(this);
        SetTexture(System::GetTexture(image_name));
    }

    DrawComponent::~DrawComponent()
    {
        System::RemoveDrawComponent(this);
    }

    void DrawComponent::Draw(Shader* shader)
    {
        if (texture_)
        {
            Mat4 scale_mat = Mat4::CreateScale(
                static_cast<float>(texture_width_),
                static_cast<float>(texture_height_),
                1.0f
            );
            Mat4 world_transform = scale_mat * owner_->GetWorldTransform();

            shader->SetMatUniform("world_transform", world_transform);
            texture_->SetActive();
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        }
    }

    void DrawComponent::SetTexture(class Texture* texture)
    {
        texture_ = texture;
        texture_width_ = texture->GetWidth();
        texture_height_ = texture->GetHeight();
    }
}