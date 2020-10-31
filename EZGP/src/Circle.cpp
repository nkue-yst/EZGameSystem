/**
 * @author Yoshito Nakaue
 * @date 2020/10/31
 */

#include "SSystem.hpp"
#include <EZGP/Circle.hpp>
#include <EZGP/Cursor.hpp>
#include <cmath>
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

    bool Circle::mouseOver()
    {
        Vec2 pos = Cursor::Pos();
        int a = pos.x - x_;
        int b = pos.y - y_;
        int c = static_cast<int>(sqrt(a * a + b * b));

        if (c <= rad_x_)
        {
            return true;
        }

        return false;
    }
}
