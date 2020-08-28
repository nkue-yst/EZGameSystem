/**
 * @author Yoshito Nakaue
 * @date 2020/08/28
 */

#include <EZGS/Circle.hpp>
#include <EZGS/System.hpp>
#include <SDL2_gfxPrimitives.h>

namespace ezgs
{
    Circle::Circle(int rad)
    {
        rad_x_ = rad;
        rad_y_ = rad;
    }

    Circle::Circle(int rad_x, int rad_y)
    {
        rad_x_ = rad_x;
        rad_y_ = rad_y;
    }

    void Circle::draw(int x, int y, int rad_x, int rad_y, Color color)
    {
        filledEllipseRGBA(System::renderer, x, y, rad_x, rad_y,
            color.red, color.green, color.blue, color.alpha);
    }

    void Circle::drawFrame(int x, int y, int rad_x, int rad_y, Color color)
    {
        aaellipseRGBA(System::renderer, x, y, rad_x, rad_y,
            color.red, color.green, color.blue, color.alpha);
    }
}
