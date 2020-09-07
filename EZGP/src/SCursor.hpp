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

        int GetState() { return button_state_; }
        void SetState(int state) { button_state_ = state; }

    protected:
        static SCursor* pCursor;
        SCursor(): button_state_(Cursor::NONE) {}

    private:
        int button_state_;
    };
}
