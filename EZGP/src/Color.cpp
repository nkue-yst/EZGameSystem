/**
 * @author Yoshito Nakaue
 * @date 2020/09/10
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

    const Color Color::AZURE(240, 255, 255);
    const Color Color::BLACK(0, 0, 0);
    const Color Color::BLUE(0, 0, 255);
    const Color Color::BROWN(165, 42, 42);
    const Color Color::CREAM(255, 237, 179);
    const Color Color::CYAN(0, 255, 255);
    const Color Color::GRAY(128, 128, 128);
    const Color Color::GREEN(0, 128, 0);
    const Color Color::IVORY(255, 255, 240);
    const Color Color::KHAKI(240, 230, 140);
    const Color Color::LEMON(255, 244, 80);
    const Color Color::LIME(0, 255, 0);
    const Color Color::MAGENTA(255, 0, 255);
    const Color Color::NAVY(0, 0, 128);
    const Color Color::ORANGE(255, 165, 0);
    const Color Color::PINK(255, 192, 203);
    const Color Color::PURPLE(128, 0, 128);
    const Color Color::RED(255, 0, 0);
    const Color Color::SKY(135, 206, 235);
    const Color Color::SNOW(255, 250, 250);
    const Color Color::VIOLET(238, 130, 238);
    const Color Color::WHITE(255, 255, 255);
    const Color Color::YELLOW(255, 255, 0);
}