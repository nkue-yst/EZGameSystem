/**
 * @author Yoshito Nakaue
 * @date 2020/11/02
 */

#pragma once

namespace ezgp
{
    class Mouse
    {
    public:
        Mouse()
            : down(false)
            , pressed(false)
        {}

        bool down;
        bool pressed;
    };

    extern Mouse MouseLeft;
    extern Mouse MouseRight;
    extern Mouse MouseMiddle;
}
