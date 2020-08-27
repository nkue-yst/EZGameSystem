/**
 * @author Yoshito Nakaue
 * @date 2020/08/27
 */

#include <EZGS/Cursor.hpp>
#include <SDL.h>

namespace ezgs
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
