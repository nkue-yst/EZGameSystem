/**
 * @author Yoshito Nakaue
 * @date 2020/09/04
 */

#include <EZGS.hpp>

int ezgs_main()
{
    EZGS_Init();

    while (Update())
    {
        Line(20, 20, 1260, 20).draw(1, Color(255, 0, 0));
        Line(20, 40, 1260, 40).draw(5, Color(0, 255, 0));

        Line::draw(20, 60, 1260, 700, 50, Color(50, 50, 50));
    }

    EZGS_Quit();
    return 0;
}
