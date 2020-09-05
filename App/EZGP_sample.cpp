/**
 * @author Yoshito Nakaue
 * @date 2020/09/05
 */

#include <EZGP.hpp>

int ezgp_main()
{
    EZGP_Init();

    while (Update())
    {
        Triangle(10, 10, 10, 710, 640, 10).draw(Color(255, 0, 0));

        Triangle(1270, 710, 1270, 10, 640, 710).drawFrame(Color(0, 0, 255));
    }

    EZGP_Quit();
    return 0;
}
