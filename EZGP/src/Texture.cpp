/**
 * @author Yoshito Nakaue
 * @date 2020/09/08
 */

#include "SSystem.hpp"
#include <EZGP/Texture.hpp>
#include <SDL_image.h>


namespace ezgp
{
    Texture::Texture(const char* file_name)
    {
        texture_ = LoadImage(file_name);
    }

    Texture::~Texture()
    {
        this->UnloadImage();
    }

    void Texture::draw(int x, int y)
    {
        SDL_Rect srcrect = { 0, 0, width_, height_ };
        SDL_Rect dstrect = { x, y, width_, height_ };
        SDL_RenderCopy(SSystem::GetSystem()->GetRenderer(), texture_, &srcrect, &dstrect);
    }

    void Texture::resize(int width, int height)
    {
        width_ = width;
        height_ = height;
    }

    void Texture::resizeAt(int x, int y, int width, int height)
    {
        SDL_Rect srcrect = { 0, 0, width_, height_ };
        SDL_Rect dstrect = { x, y, width, height };
        SDL_RenderCopy(SSystem::GetSystem()->GetRenderer(), texture_, &srcrect, &dstrect);
    }

    void Texture::rotateAt(int x, int y, int angle)
    {
        SDL_Rect srcrect = { 0, 0, width_, height_ };
        SDL_Rect dstrect = { x, y, width_, height_ };
        SDL_RenderCopyEx(
            SSystem::GetSystem()->GetRenderer(),
            texture_,
            &srcrect,
            &dstrect,
            angle,
            NULL,
            SDL_FLIP_NONE
        );
    }

    SDL_Texture* Texture::LoadImage(const char* file_name)
    {
        SDL_Surface* image = IMG_Load(file_name);

        if (!image)
        {
            SDL_Log("Failed to load image %s", file_name);
            return NULL;
        }

        this->width_  = image->w;
        this->height_ = image->h;

        SDL_Texture* tex = SDL_CreateTextureFromSurface(SSystem::GetSystem()->GetRenderer(), image);
        SDL_FreeSurface(image);

        return tex;
    }

    void Texture::UnloadImage()
    {
        SDL_DestroyTexture(this->texture_);
    }
}
