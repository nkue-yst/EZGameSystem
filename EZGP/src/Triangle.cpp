/**
 * @author Yoshito Nakaue
 * @date 2020/09/08
 */

#include "SSystem.hpp"
#include <EZGP/Triangle.hpp>
#include <SDL2_gfxPrimitives.h>

namespace ezgp
{
    Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
    {
        x_[0] = x1;  y_[0] = y1;
        x_[1] = x2;  y_[1] = y2;
        x_[2] = x3;  y_[2] = y3;
    }

    void Triangle::draw(Color color)
    {
        filledTrigonRGBA(
            SSystem::GetSystem()->GetRenderer(),
            x_[0], y_[0],
            x_[1], y_[1],
            x_[2], y_[2],
            color.red,
            color.green,
            color.blue,
            color.alpha
        );

        this->drawFrame(color);
    }

    void Triangle::drawFrame(Color color)
    {
        aatrigonRGBA(
            SSystem::GetSystem()->GetRenderer(),
            x_[0], y_[0],
            x_[1], y_[1],
            x_[2], y_[2],
            color.red,
            color.green,
            color.blue,
            color.alpha
        );
    }
}