/**
 * @author Yoshito Nakaue
 * @date 2020/09/05
 */

#include "EZGP_System.hpp"
#include <EZGP/EZGPmain.hpp>

namespace ezgp
{
    void EZGP_Init()
    {
        System::Create();
        System::GetSystem()->CreateWindow();
    }

    bool Update()
    {
        return System::GetSystem()->Update();
    }

    void EZGP_Quit()
    {
        System::GetSystem()->Quit();
        System::Destroy();
    }
}
