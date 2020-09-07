/**
 * @author Yoshito Nakaue
 * @date 2020/09/07
 */

#include "SCursor.hpp"
#include "SCursor.hpp"
#include <EZGP/Cursor.hpp>
#include <SDL.h>


namespace ezgp
{
    namespace Cursor
    {
        Vec2 Pos()
        {
            Vec2 pos;
            SDL_GetMouseState(&pos.x, &pos.y);
            return pos;
        }

        int GetState()
        {
            return SCursor::GetCursor()->GetState();
        }
    }

    void SCursor::Create()
    {
        if (!pCursor)
            pCursor = new SCursor();
    }

    void SCursor::Destroy()
    {
        delete pCursor;
        pCursor = NULL;
    }

    SCursor* SCursor::pCursor = NULL;
}
