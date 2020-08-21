/**
 * @author Yoshito Nakaue
 * @date 2020/08/21
 */

#include <EZGS/Scene.hpp>
#include <EZGS/System.hpp>

namespace ezgs
{
    namespace Scene
    {
        void SetBackgroundColor(uint8_t R, uint8_t G, uint8_t B)
        {
            ezgs::System::SetBackgroundColor(R, G, B);
        }
    }
}