/**
 * @author Yoshito Nakaue
 * @date 2020/08/18
 */

#include <EZGS/Scene.hpp>
#include <EZGS/System.hpp>
#include <GL/glew.h>

namespace ezgs
{
    namespace Scene
    {
        void SetBackgroundColor(float red, float green, float blue, float alpha)
        {
            bg_color.red   = red;
            bg_color.green = green;
            bg_color.blue  = blue;
            bg_color.alpha = alpha;
        }
    }
}