/**
 * @author Yoshito Nakaue
 * @date 2020/08/21
 */

#include <EZGS/String.hpp>
#include <EZGS/Math.hpp>

namespace ezgs
{
    String::String(const char* str)
        :string_()
        ,font_type_(nullptr)
        ,texture_id_(NULL)
    {
        string_ = str;
        font_type_ = TTF_OpenFont("lib/Font/default_font.ttf", 10);
        if (!font_type_)
            SDL_Log("%s", TTF_GetError());

        SDL_Surface* str_img;
        SDL_Color c = { 1, 1, 1 };
        str_img = TTF_RenderUTF8_Blended(font_type_, str, c);

        SDL_FreeSurface(str_img);
    }

    void String::draw()
    {
 
    }

    void String::GenTexture(SDL_Surface* surface)
    {

    }
}