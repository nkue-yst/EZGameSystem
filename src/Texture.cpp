/**
 * @author Yoshito Nakaue
 * @date 2020/08/21
 */

#include <EZGS/Texture.hpp>
#include <SDL.h>
#include <SDL_image.h>


namespace ezgs
{
    Texture::Texture()
        :texture_id_(0)
        , width_(0)
        , height_(0)
    {

    }

    Texture::~Texture()
    {

    }

    int Texture::LoadImage(const std::string& file_name)
    {
        SDL_Surface* image = IMG_Load(file_name.c_str());

        if (!image)
        {
            SDL_Log("Failed to load image %s", file_name.c_str());
            return 1;
        }

        this->width_  = image->w;
        this->height_ = image->h;



        SDL_FreeSurface(image);
        return 0;
    }

    void Texture::UnloadImage()
    {
    }
}