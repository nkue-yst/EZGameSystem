/**
 * @author Yoshito Nakaue
 * @date 2020/10/31
 */

#include "SSystem.hpp"
#include <EZGP/Circle.hpp>
#include <SDL2_gfxPrimitives.h>

namespace ezgp
{
    Circle::Circle(int x, int y, int rad)
    {
        x_ = x;
        y_ = y;
        rad_x_ = rad;
        rad_y_ = rad;
    }

    Circle::Circle(int x, int y, int rad_x, int rad_y)
    {
        x_ = x;
        y_ = y;
        rad_x_ = rad_x;
        rad_y_ = rad_y;
    }

    void Circle::draw(int x, int y, int rad_x, int rad_y, Color color)
    {
        filledEllipseRGBA(SSystem::GetSystem()->GetRenderer(), x, y, rad_x, rad_y,
            color.red, color.green, color.blue, color.alpha);
    }

    void Circle::drawFrame(int x, int y, int rad_x, int rad_y, Color color)
    {
        aaellipseRGBA(SSystem::GetSystem()->GetRenderer(), x, y, rad_x, rad_y,
            color.red, color.green, color.blue, color.alpha);
    }
}
