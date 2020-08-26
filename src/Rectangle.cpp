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
        SDL_Rect dst = { x, y, width, height };
        SDL_SetRenderDrawColor(System::renderer, color.red, color.green, color.blue, color.alpha);
        SDL_SetRenderDrawBlendMode(System::renderer, SDL_BLENDMODE_BLEND);
        SDL_RenderFillRect(System::renderer, &dst);
    }
}