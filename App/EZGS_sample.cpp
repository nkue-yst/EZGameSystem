/**
 * @author Yoshito Nakaue
 * @date 2020/08/23
 */

#include <EZGS.hpp>

int ezgs_main()
{
    if (System::CreateWindow())
        return 1;
    
    Scene::SetBackgroundColor(30, 50, 85);

    Font font(50);

    while (System::Update())
    {
        font.draw("Hello, World!!", 150, 150);
    }

    System::EZGS_Quit();
    return 0;
}
