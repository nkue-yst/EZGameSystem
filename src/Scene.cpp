/**
 * @author Yoshito Nakaue
 * @date 2020/09/04
 */

#include <EZGS/Scene.hpp>
#include <EZGS/System.hpp>

namespace ezgs
{
    namespace Scene
    {
        void SetBackgroundColor(uint8_t R, uint8_t G, uint8_t B)
        {
            System::GetSystem()->SetBackgroundColor(R, G, B);
        }
    }
}