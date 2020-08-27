/**
 * @author Yoshito Nakaue
 * @date 2020/08/28
 */

#include <EZGS.hpp>

int ezgs_main()
{
    if (System::CreateWindow())
        return 1;

    Vec2 pos;

    while (System::Update())
    {
        pos = Cursor::Pos();
        Rect(30, 30).draw(pos.x-15, pos.y-15, Color(255, 0, 0, 100));
    }

    System::EZGS_Quit();
    return 0;
}
