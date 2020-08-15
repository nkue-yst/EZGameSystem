/**
 * @author Yoshito Nakaue
 * @date 2020/08/15
 */

#include <EZGS/Texture.hpp>
#include <GL/glew.h>
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

        int format = GL_RGB;
        if (image->format->BytesPerPixel == 4)
            format = GL_RGBA;

        glGenTextures(1, &texture_id_);
        glBindTexture(GL_TEXTURE_2D, texture_id_);

        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            format,
            width_,
            height_,
            0,
            format,
            GL_UNSIGNED_BYTE,
            image->pixels
        );

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        SDL_FreeSurface(image);
        return 0;
    }

    void Texture::UnloadImage()
    {
        glDeleteTextures(1, &texture_id_);
    }
}