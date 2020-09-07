/**
 * @author Yoshito Nakaue
 * @date 2020/09/07
 */

#include <EZGP.hpp>

int ezgp_main()
{
    EZGP_Init();

    Font f(50);
    int state;

    while (Update())
    {
        Scene::SetBackgroundColor(126, 126, 126);
        state = Cursor::GetState();

        if (state == Cursor::LEFT_ON)
            f.draw("Left");
        else if (state == Cursor::RIGHT_ON)
            f.draw("Right");
        else if (state == Cursor::MIDDLE_ON)
            f.draw("Middle");
    }

    EZGP_Quit();
    return 0;
}
