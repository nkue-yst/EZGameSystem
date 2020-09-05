/**
 * @author Yoshito Nakaue
 * @date 2020/09/05
 */

#include <EZGP/Scene.hpp>
#include <EZGP/System.hpp>

namespace ezgp
{
    namespace Scene
    {
        void SetBackgroundColor(uint8_t R, uint8_t G, uint8_t B)
        {
            System::GetSystem()->SetBackgroundColor(R, G, B);
        }
    }
}