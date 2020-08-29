/**
 * @author Yoshito Nakaue
 * @date 2020/08/29
 */

#include <EZGS.hpp>

int ezgs_main()
{
    if (System::CreateWindow())
        return 1;

    while (System::Update())
    {
        Line(20, 20, 1260, 20).draw(1, Color(255, 0, 0));
        Line(20, 40, 1260, 40).draw(5, Color(0, 255, 0));

        Line::draw(20, 60, 1260, 700, 50, Color(50, 50, 50));
    }

    System::EZGS_Quit();
    return 0;
}
