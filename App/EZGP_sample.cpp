/**
 * @author Yoshito Nakaue
 * @date 2020/09/06
 */

#include <EZGP.hpp>

int ezgp_main()
{
    EZGP_Init();

    Texture tex("App/Resouces/sample.png");

    while (Update())
    {
        tex.draw(20, 20);
        tex.rotateAt(100, 100, 90);
        tex.resizeAt(150, 150, 20, 20);
    }

    EZGP_Quit();
    return 0;
}
