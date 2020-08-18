/**
 * @author Yoshito Nakaue
 * @date 2020/08/16
 */

#include <EZGS.hpp>

int main(int argc, char **argv)
{
    if (System::CreateWindow())
        return 1;

    Scene::SetBackgroundColor(0.5f, 0.5f, 0.5f);

    Actor* actor = new Actor();
    DrawComponent* dc = new DrawComponent(actor, "sample/image/sample.png");

    while (System::Update())
    {
        System::End();
    }

    System::Destroy();
    return 0;
}
