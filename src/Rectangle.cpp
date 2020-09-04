/**
 * @author Yoshito Nakaue
 * @date 2020/09/04
 */

#include <EZGS/Rectangle.hpp>
#include <EZGS/System.hpp>
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>

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
        SDL_SetRenderDrawColor(System::GetSystem()->GetRenderer(), color.red, color.green, color.blue, color.alpha);
        SDL_RenderFillRect(System::GetSystem()->GetRenderer(), &dst);
    }

    void Rect::drawFrame(int x, int y, int width, int height, Color color)
    {
        SDL_Rect dst = { x, y, width, height };
        SDL_SetRenderDrawColor(System::GetSystem()->GetRenderer(), color.red, color.green, color.blue, color.alpha);
        SDL_RenderDrawRect(System::GetSystem()->GetRenderer(), &dst);
    }
}