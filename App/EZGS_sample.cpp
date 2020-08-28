/**
 * @author Yoshito Nakaue
 * @date 2020/08/28
 */

#include <EZGS.hpp>

int ezgs_main()
{
    if (System::CreateWindow())
        return 1;

    Circle circle(50);
    Circle ellipse(100, 50);

    while (System::Update())
    {
        circle.draw(100, 100, Color(255, 0, 0, 100));
        ellipse.draw(200, 200, Color(0, 255, 0, 100));

        Circle::draw(400, 400, 100, Color(0, 0, 255, 100));
        Circle::draw(800, 500, 200, 100, Color(255, 165, 0, 100));

        circle.drawFrame(1050, 340, Color(123, 104, 238));
        Circle::drawFrame(700, 150, 300, 100, Color(255, 0, 255));
    }

    System::EZGS_Quit();
    return 0;
}
