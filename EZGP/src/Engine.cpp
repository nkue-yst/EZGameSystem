/**
 * @author Yoshito Nakaue
 * @date 2020/09/08
 */

#include "SCursor.hpp"
#include "SSystem.hpp"
#include <EZGP/Engine.hpp>

namespace ezgp
{
    void EZGP_Init()
    {
        SSystem::Create();
        SSystem::GetSystem()->CreateWindow();
        SCursor::Create();
    }

    bool Update()
    {
        return SSystem::GetSystem()->Update();
    }

    void EndLoop()
    {
        SSystem::GetSystem()->EndLoop();
    }

    void EZGP_Quit()
    {
        SCursor::Destroy();
        SSystem::GetSystem()->Quit();
        SSystem::Destroy();
    }
}
