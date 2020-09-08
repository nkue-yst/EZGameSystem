/**
 * @author Yoshito Nakaue
 * @date 2020/09/07
 */

#include <EZGP.hpp>
#include <random>
#include <iostream>

int ezgp_main()
{
    EZGP_Init();

/*    Font f(50);
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
    }*/

    Scene::SetBackgroundColor(200, 230, 255);

    std::random_device seed_gen;
    std::mt19937 rand_engine(seed_gen());
    int x, y, r, g, b;
    while (Update())
    {
        for (int i = 0; i < 100; i++)
        {
            x = rand_engine() % 1281;
            y = rand_engine() % 721;
            r = rand_engine() % 256;
            g = rand_engine() % 256;
            b = rand_engine() % 256;
            Circle::draw(x, y, 10, 10, Color(r, g, b, 100));
        }
    }

    EZGP_Quit();
    return 0;
}
