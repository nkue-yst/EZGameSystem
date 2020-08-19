/**
 * @author Yoshito Nakaue
 * @date 2020/08/20
 */

#include <EZGS.hpp>

int ezgs_main()
{
    if (System::CreateWindow())
        return 1;

    Scene::SetBackgroundColor(0.5f, 0.5f, 0.5f);

    while (System::Update())
    {
        //System::End();
    }

    System::EZGS_Quit();
    return 0;
}
