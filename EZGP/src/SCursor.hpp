/**
 * @author Yoshito Nakaue
 * @date 2020/11/02
 */

#pragma once
#include <EZGP/Cursor.hpp>

namespace ezgp
{
    class SCursor
    {
    public:
        static void Create();
        static void Destroy();
        static SCursor* GetCursor() { return pCursor; }

    protected:
        static SCursor* pCursor;
        SCursor(){}
    };
}
