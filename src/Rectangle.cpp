/**
 * @author Yoshito Nakaue
 * @date 2020/08/26
 */

#include <EZGS/Rectangle.hpp>
#include <EZGS/System.hpp>
#include <SDL.h>

namespace ezgs
{
    Rect::Rect(int width, int height)
    {
        width_ = width;
        height_ = height;
    }

    Rect::~Rect()
    {

    }

    void Rect::draw(int x, int y, int width, int height, Color color)
    {
        SDL_Surface* sfc;
        SDL_Texture* tex;

        sfc = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
        SDL_FillRect(sfc, NULL, SDL_MapRGB(sfc->format, color.red, color.green, color.blue));

        int w, h;
        tex = SDL_CreateTextureFromSurface(System::renderer, sfc);
        SDL_QueryTexture(tex, NULL, NULL, &w, &h);
        SDL_Rect src = { 0, 0, w, h };
        SDL_Rect dst = { x, y, w, h };

        SDL_RenderCopy(System::renderer, tex, &src, &dst);

        SDL_FreeSurface(sfc);
        SDL_DestroyTexture(tex);
    }
}