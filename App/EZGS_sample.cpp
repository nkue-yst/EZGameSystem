/**
 * @author Yoshito Nakaue
 * @date 2020/08/25
 */

#include <EZGS.hpp>

int ezgs_main()
{
    if (System::CreateWindow())
        return 1;
    
    Scene::SetBackgroundColor(30, 50, 85);

    Font font(50);
    Rect rect(100, 100);

    while (System::Update())
    {
        rect.draw(100, 100);

        Rect::draw(50, 50, 50, 50);
    }

    System::EZGS_Quit();
    return 0;
}
