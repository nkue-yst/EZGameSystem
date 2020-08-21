/**
 * @author Yoshito Nakaue
 * @date 2020/08/21
 */

#include <EZGS/Color.hpp>
#include <EZGS/Font.hpp>
#include <EZGS/Math.hpp>
#include <EZGS/String.hpp>
#include <EZGS/System.hpp>
#include <SDL.h>

namespace ezgs
{
    Font::Font(int size)
        :size_(10)
        ,font_type_(nullptr)
    {
        font_type_ = TTF_OpenFont("lib/Font/default_font.ttf", size);
        if (!font_type_)
            SDL_Log("%s", TTF_GetError());
        size_ = size;
    }

    Font::~Font()
    {
        TTF_CloseFont(font_type_);
        strings.clear();
    }

    int Font::draw(const char* str, int x, int y)
    {
        if (strings.find(str) == strings.end())
        {
            String* string = new String(str);
            strings.insert(std::pair < const char*, String*> { str, string });
        }

        return 0;
    }
}