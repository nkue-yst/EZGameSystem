/**
 * @author Yoshito Nakaue
 * @date 2020/09/08
 */

#include "SSystem.hpp"
#include <EZGP/Scene.hpp>
#include <EZGP/Color.hpp>

namespace ezgp
{
    namespace Scene
    {
        void SetBackgroundColor(Color color)
        {
            SSystem::GetSystem()->SetBackgroundColor(color);
        }
    }
}