/**
 * @author Yoshito Nakaue
 * @date 2020/08/22
 */

#include <EZGS/Color.hpp>
#include <EZGS/Font.hpp>
#include <EZGS/System.hpp>
#include <SDL.h>

namespace ezgs
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
        TTF_CloseFont(font_type_);
    }

    int Font::draw(const char* str, int x, int y)
    {
        SDL_Surface* str_surface;
        SDL_Texture* str_texture;
        SDL_Color c = { 255, 255, 255 };

        str_surface = TTF_RenderUTF8_Blended(font_type_, str, c);
        str_texture = SDL_CreateTextureFromSurface(System::renderer, str_surface);
        SDL_FreeSurface(str_surface);

        int w, h;
        SDL_QueryTexture(str_texture, NULL, NULL, &w, &h);
        SDL_Rect str_rect = { 0, 0, w, h };

        SDL_RenderCopy(System::renderer, str_texture, &str_rect, &str_rect);
        SDL_RenderPresent(System::renderer);

        SDL_DestroyTexture(str_texture);
        return 0;
    }
}