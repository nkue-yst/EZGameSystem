/**
 * @author Yoshito Nakaue
 * @date 2020/08/22
 */

#include <EZGS.hpp>

int ezgs_main()
{
    if (System::CreateWindow())
        return 1;
    
    Scene::SetBackgroundColor(30, 50, 85);

    Font* font = new Font(50);

    while (System::Update())
    {
        font->draw("Hello, World!!");
    }

    delete font;
    System::EZGS_Quit();
    return 0;
}
