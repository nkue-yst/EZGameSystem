/**
 * @author Yoshito Nakaue
 * @date 2020/09/05
 */

#include "EZGP_System.hpp"
#include <EZGP/Line.hpp>
#include <SDL2_gfxPrimitives.h>

namespace ezgp
{
    Line::Line(int x1, int y1, int x2, int y2)
    {
        x1_ = x1;  y1_ = y1;
        x2_ = x2;  y2_ = y2;
    }

    void Line::draw(int x1, int y1, int x2, int y2, int thick, Color color)
    {
        thickLineRGBA(System::GetSystem()->GetRenderer(), x1, y1, x2, y2,
            thick, color.red, color.green, color.blue, color.alpha);
    }
}
