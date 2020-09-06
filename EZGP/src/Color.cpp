/**
 * @author Yoshito Nakaue
 * @date 2020/09/05
 */

#include <EZGP/Color.hpp>

namespace ezgp
{
    Color::Color(uint8_t R, uint8_t G, uint8_t B, uint8_t A)
    {
        red = R;
        green = G;
        blue = B;
        alpha = A;
    }
}