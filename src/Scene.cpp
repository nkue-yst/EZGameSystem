/**
 * @author Yoshito Nakaue
 * @date 2020/08/20
 */

#include <EZGS/Scene.hpp>
#include <EZGS/System.hpp>

namespace ezgs
{
    namespace Scene
    {
        void SetBackgroundColor(float R, float G, float B)
        {
            ezgs::System::SetBackgroundColor(R, G, B);
        }
    }
}