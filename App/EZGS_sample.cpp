/**
 * @author Yoshito Nakaue
 * @date 2020/08/26
 */

#include <EZGS.hpp>

int ezgs_main()
{
    if (System::CreateWindow())
        return 1;

    Rect rect(100, 100);

    while (System::Update())
    {
        rect.draw(80, 80, Color(0, 255, 0));
        rect.drawFrame(80, 80, Color(255, 0, 0));

        Rect::draw(50, 50, 50, 50, Color(255, 0, 0, 150));
    }

    System::EZGS_Quit();
    return 0;
}
