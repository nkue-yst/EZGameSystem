/**
 * @author Yoshito Nakaue
 * @date 2020/11/02
 */

#include "SCursor.hpp"
#include "SSystem.hpp"
#include <EZGP/Engine.hpp>

namespace ezgp
{
    void EZGP_Init(int win_width, int win_height)
    {
        SSystem::Create();
        SSystem::GetSystem()->CreateWindow(win_width, win_height);
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
