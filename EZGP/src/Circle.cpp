/**
 * @author Yoshito Nakaue
 * @date 2020/09/05
 */

#include "EZGP_System.hpp"
#include <EZGP/Circle.hpp>
#include <SDL2_gfxPrimitives.h>

namespace ezgp
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
        filledEllipseRGBA(System::GetSystem()->GetRenderer(), x, y, rad_x, rad_y,
            color.red, color.green, color.blue, color.alpha);
    }

    void Circle::drawFrame(int x, int y, int rad_x, int rad_y, Color color)
    {
        aaellipseRGBA(System::GetSystem()->GetRenderer(), x, y, rad_x, rad_y,
            color.red, color.green, color.blue, color.alpha);
    }
}
