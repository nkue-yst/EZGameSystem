/**
 * @author Yoshito Nakaue
 * @date 2020/08/29
 */

#include <EZGS/Line.hpp>
#include <EZGS/System.hpp>
#include <SDL2_gfxPrimitives.h>

namespace ezgs
{
    Line::Line(int x1, int y1, int x2, int y2)
    {
        x1_ = x1;  y1_ = y1;
        x2_ = x2;  y2_ = y2;
    }

    void Line::draw(int x1, int y1, int x2, int y2, int thick, Color color)
    {
        thickLineRGBA(System::renderer, x1, y1, x2, y2,
            thick, color.red, color.green, color.blue, color.alpha);
    }
}
