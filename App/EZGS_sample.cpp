/**
 * @author Yoshito Nakaue
 * @date 2020/08/21
 */

#include <EZGS.hpp>

int ezgs_main()
{
    if (System::CreateWindow())
        return 1;
    
    Scene::SetBackgroundColor(0, 0, 20);

    while (System::Update())
    {
    }

    System::EZGS_Quit();
    return 0;
}
