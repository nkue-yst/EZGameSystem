/**
 * @author Yoshito Nakaue
 * @date 2020/10/31
 */

#include <EZGP.hpp>

int ezgp_main()
{
    EZGP_Init();

    while (Update())
    {
        Circle(200, 200, 50).drawFrame();
    }

    EZGP_Quit();
    return 0;
}
