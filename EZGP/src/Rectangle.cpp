/**
 * @author Yoshito Nakaue
 * @date 2020/09/11
 */

#include "SSystem.hpp"
#include <EZGP/Rectangle.hpp>
#include <EZGP/Cursor.hpp>
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>

namespace ezgp
{
    Rect::Rect(int x, int y, int width, int height)
    {
        x_ = x;
        y_ = y;
        width_ = width;
        height_ = height;
    }

    Rect::~Rect()
    {

    }

    void Rect::draw(int x, int y, int width, int height, Color color)
    {
        SDL_Rect dst = { x, y, width, height };
        SDL_SetRenderDrawColor(SSystem::GetSystem()->GetRenderer(), color.red, color.green, color.blue, color.alpha);
        SDL_RenderFillRect(SSystem::GetSystem()->GetRenderer(), &dst);
    }

    void Rect::drawFrame(int x, int y, int width, int height, Color color)
    {
        SDL_Rect dst = { x, y, width, height };
        SDL_SetRenderDrawColor(SSystem::GetSystem()->GetRenderer(), color.red, color.green, color.blue, color.alpha);
        SDL_RenderDrawRect(SSystem::GetSystem()->GetRenderer(), &dst);
    }
}