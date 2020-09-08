/**
 * @author Yoshito Nakaue
 * @date 2020/09/08
 */

#include "SSystem.hpp"
#include <EZGP/Scene.hpp>

namespace ezgp
{
    namespace Scene
    {
        void SetBackgroundColor(uint8_t R, uint8_t G, uint8_t B)
        {
            SSystem::GetSystem()->SetBackgroundColor(R, G, B);
        }
    }
}