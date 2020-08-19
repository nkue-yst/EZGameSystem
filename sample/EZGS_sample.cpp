/**
 * @author Yoshito Nakaue
 * @date 2020/08/19
 */

#include <EZGS.hpp>

int ezgs_main()
{
    if (System::CreateWindow())
        return 1;

    while (System::Update())
    {
        //System::End();
    }

    System::EZGS_Quit();
    return 0;
}
