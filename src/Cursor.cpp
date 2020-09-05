/**
 * @author Yoshito Nakaue
 * @date 2020/09/05
 */

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
    }
}
