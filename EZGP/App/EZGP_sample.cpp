/**
 * @author Yoshito Nakaue
 * @date 2020/11/02
 */

#include <EZGP.hpp>

int ezgp_main()
{
    EZGP_Init();

    Scene::SetBackgroundColor(Color::BLACK);

    Font f(20);
    
    int i = 0;
    while (Update())
    {
        if (MouseLeft.down)
            std::cout << ++i << std::endl;

        if (MouseLeft.pressed)
            f.draw("Pressed");
    }

    EZGP_Quit();
    return 0;
}
