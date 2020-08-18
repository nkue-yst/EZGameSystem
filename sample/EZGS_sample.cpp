/**
 * @author Yoshito Nakaue
 * @date 2020/08/16
 */

#include <EZGS.hpp>

int main(int argc, char **argv)
{
    if (System::CreateWindow())
        return 1;

    Actor actor;
    DrawComponent* dc = new DrawComponent(&actor, "sample/image/sample.png");

    while (System::Update)
    {

    }

    System::Destroy();
    return 0;
}
