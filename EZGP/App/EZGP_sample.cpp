/**
 * @author Yoshito Nakaue
 * @date 2020/11/02
 */

#include <EZGP.hpp>

int ezgp_main()
{
    EZGP_Init(640, 360);

    Rect rect(100, 100, 50, 50);
    Circle circle(200, 200, 50);
    while (Update())
    {
        rect.draw(rect.mouseOver() ? Color(100, 100, 100) : Color(200, 200, 200));
        circle.draw(circle.mouseOver() ? Color(100, 100, 100) : Color(200, 200, 200));
    }

    EZGP_Quit();
    return 0;
}
