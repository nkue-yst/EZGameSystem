/**
 * @author Yoshito Nakaue
 * @date 2020/08/21
 */

#include <EZGS/System.hpp>
#include <EZGS/Font.hpp>
#include <EZGS/Math.hpp>
#include <SDL_image.h>
#include <SDL_ttf.h>

namespace ezgs
{
    namespace System
    {
        // windowに描画するレンダラー
        SDL_Renderer* renderer;

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
                SDL_Log("Failed to initialize SDL2_image : %s", IMG_GetError());
                return 1;
            }

            if (TTF_Init() == -1)
            {
                SDL_Log("Failed to initialize SDL2_ttf : %s", TTF_GetError());
                return 1;
            }

            window = SDL_CreateWindow(
                "Window Title",
                100,
                100,
                1280,
                720,
                0
            );

            if (!window)
            {
                SDL_Log("Failed to create window : %s", SDL_GetError());
                return 1;
            }

            renderer = SDL_CreateRenderer(
                window,
                -1,
                SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
            );

            ticks_count = SDL_GetTicks();

            return 0;
        }

        void EZGS_Quit()
        {
            UnloadData();
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            TTF_Quit();
            IMG_Quit();
            SDL_Quit();
        }

        bool Update()
        {
            InputKeys();
            Draw();
            RunSystem();

            return is_running;
        }

        void EndLoop()
        {
            is_running = false;
        }

        void RunSystem()
        {
            while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticks_count + 16))
                ;

            float dt = (SDL_GetTicks() - ticks_count) / 1000.0f;
            if (dt > 0.05f)
                dt = 0.05f;

            ticks_count = SDL_GetTicks();
        }

        void Draw()
        {
            SDL_SetRenderDrawColor(
                renderer,
                bg_color.red,
                bg_color.green,
                bg_color.blue,
                bg_color.alpha
            );
            SDL_RenderClear(renderer);
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

        void SetBackgroundColor(uint8_t R, uint8_t G, uint8_t B)
        {
            bg_color.red = R;
            bg_color.green = G;
            bg_color.blue = B;
            bg_color.alpha = 255;
        }
    }
}
