/**
 * @author Yoshito Nakaue
 * @date 2020/08/20
 */

#include <EZGS/System.hpp>
#include <EZGS/Math.hpp>
#include <GL/glew.h>
#include <SDL_image.h>

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

            int flags = IMG_INIT_JPG | IMG_INIT_PNG;
            int initted = IMG_Init(flags);
            if ((initted&flags) != flags)
            {
                SDL_Log("Failed to initialize SDL2_image : %s", SDL_GetError());
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

            /* シェーダー読み込み */
            if (LoadShader())
            {
                SDL_Log("Failed to load shader.");
                return 1;
            }

            CreateVerts();

            ticks_count = SDL_GetTicks();

            return 0;
        }

        int LoadShader()
        {
            shader = new Shader();
            if (shader->Load("src/shader/Simple.vert", "src/shader/Simple.frag"))
                return 1;

            shader->SetActive();
            Mat4 simple_view = Mat4::CreateSimpleView(1280.f, 720.f);
            shader->SetMatUniform("view_transform", simple_view);
            return 0;
        }

        void CreateVerts()
        {
            float vertices[] = {
                -0.5f,  0.5f,  0.f, 0.f, 0.f,
                 0.5f,  0.5f,  0.f, 1.f, 0.f,
                 0.5f, -0.5f,  0.f, 1.f, 1.f,
                -0.5f, -0.5f,  0.f, 0.f, 1.f
            };

            unsigned int indices[] = {
                0, 1, 2,
                2, 3, 0
            };

            verts = new VertexArray(vertices, 4, indices, 6);
        }

        void EZGS_Quit()
        {
            UnloadData();
            delete verts;
            shader->Unload();
            delete shader;
            SDL_GL_DeleteContext(context);
            SDL_DestroyWindow(window);
            IMG_Quit();
            SDL_Quit();
        }

        bool Update()
        {
            InputKeys();
            RunSystem();
            Draw();

            return is_running;
        }

        void EndLoop()
        {
            is_running = false;
        }

        void RunSystem()
        {
            // 60FPS制限
            while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticks_count + 16))
                ;

            float dt = (SDL_GetTicks() - ticks_count) / 1000.0f;
            if (dt > 0.05f)
                dt = 0.05f;

            ticks_count = SDL_GetTicks();
        }

        void Draw()
        {
            glClearColor(bg_color.red, bg_color.green, bg_color.blue, bg_color.alpha);
            glClear(GL_COLOR_BUFFER_BIT);

            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            System::shader->SetActive();
            System::verts->SetActive();

            // Draw

            SDL_GL_SwapWindow(window);
        }

        void InputKeys()
        {
            SDL_Event ev;
            while (SDL_PollEvent(&ev))
            {
                switch (ev.type)
                {
                    case SDL_QUIT:
                        is_running = false;
                        break;
                    default:
                        break;
                }
                break;
            }

            const Uint8* key_state = SDL_GetKeyboardState(NULL);
            if (key_state[SDL_SCANCODE_ESCAPE])
                is_running = false;
        }

        void UnloadData()
        {
            /* テクスチャを破棄 */
            for (auto iter : textures)
            {
                iter.second->UnloadImage();
                delete iter.second;
            }
            textures.clear();
        }

        Texture* GetTexture(const std::string& file_name)
        {
            Texture* texture = nullptr;

            auto iter = textures.find(file_name);
            if (iter != textures.end())
                texture = iter->second;
            else
            {
                texture = new Texture();
                if (!texture->LoadImage(file_name))
                    textures.emplace(file_name, texture);
                else
                {
                    delete texture;
                    texture = nullptr;
                }
            }
            return texture;
        }

        void SetBackgroundColor(float R, float G, float B)
        {
            bg_color.red = R;
            bg_color.green = G;
            bg_color.blue = B;
            bg_color.alpha = 1.0f;
        }
    }
}
