/**
 * @author Yoshito Nakaue
 * @date 2020/08/10
 */

#include <EZGS/System.hpp>
#include <GL/glew.h>

namespace ezgs
{
    namespace System
    {
        int CreateWindow()
        {
            if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
            {
                SDL_Log("Failed to initialize SDL2 : %s", SDL_GetError());
                return 1;
            }

            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
            SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
            SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
            SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
            SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
            SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
            SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

            window = SDL_CreateWindow(
                "Window Title",
                100,
                100,
                1280,
                720,
                SDL_WINDOW_OPENGL
            );

            if (!window)
            {
                SDL_Log("Failed to create window : %s", SDL_GetError());
                return 1;
            }
            context = SDL_GL_CreateContext(window);

            glewExperimental = GL_TRUE;
            if (glewInit() != GLEW_OK)
            {
                SDL_Log("Failed to initialize GLEW.");
                return 1;
            }
            glGetError();

            return 0;
        }

        void Destroy()
        {
            SDL_GL_DeleteContext(context);
            SDL_DestroyWindow(window);
            SDL_Quit();
        }

        void Update()
        {
            while (is_running)
            {

            }
        }
    }
}
