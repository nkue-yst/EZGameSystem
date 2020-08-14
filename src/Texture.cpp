/**
 * @author Yoshito Nakaue
 * @date 2020/08/13
 */

#include <EZGS/Texture.hpp>

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
        int channels_num = 0;
        unsigned char* image = 
    }

    void Texture::UnloadImage()
    {
        glDeleteTextures(1, &texture_id_);
    }
}