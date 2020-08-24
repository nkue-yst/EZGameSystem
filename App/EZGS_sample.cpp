/**
 * @author Yoshito Nakaue
 * @date 2020/08/24
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
        font.draw("SAMPLE, SAMPLE, SAMPLE", 100, 100);
    }

    System::EZGS_Quit();
    return 0;
}
