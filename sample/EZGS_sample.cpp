#include <EZGS.hpp>

int main(int argc, char **argv)
{
    System::CreateWindow();

    Actor* actor = new Actor();
    DrawComponent* dc = new DrawComponent(actor, "sample/image/sample.png");

    System::Destroy();
    return 0;
}
