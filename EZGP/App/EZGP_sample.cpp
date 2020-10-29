/**
 * @author Yoshito Nakaue
 * @date 2020/09/11
 */

#include <EZGP.hpp>

int ezgp_main()
{
    EZGP_Init();
    Scene::SetBackgroundColor(Color::RED + Color::BLUE);

    while (Update())
    {
    }

    EZGP_Quit();
    return 0;
}
