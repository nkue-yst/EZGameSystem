/**
 * @author Yoshito Nakaue
 * @date 2020/09/05
 */

#include <EZGP/Color.hpp>
#include <EZGP/Font.hpp>
#include <EZGP/System.hpp>
#include <SDL.h>

namespace ezgp
{
    Font::Font(int size)
        :size_(10)
        ,font_type_(nullptr)
    {
        font_type_ = TTF_OpenFont("Font/default_font.ttf", size);
        if (!font_type_)
            SDL_Log("%s", TTF_GetError());
        size_ = size;
    }

    Font::~Font()
    {

    }

    int Font::draw(const char* str, int x, int y)
    {
        SDL_Surface* str_surface;
        SDL_Texture* str_texture;
        SDL_Color c = { 255, 255, 255 };

        str_surface = TTF_RenderUTF8_Blended(font_type_, str, c);
        str_texture = SDL_CreateTextureFromSurface(System::GetSystem()->GetRenderer(), str_surface);
        SDL_FreeSurface(str_surface);

        int w, h;
        SDL_QueryTexture(str_texture, NULL, NULL, &w, &h);
        SDL_Rect src_rect = { 0, 0, w, h };
        SDL_Rect dst_rect = { x, y, w, h };

        SDL_RenderCopy(System::GetSystem()->GetRenderer(), str_texture, &src_rect, &dst_rect);

        SDL_DestroyTexture(str_texture);
        return 0;
    }
}