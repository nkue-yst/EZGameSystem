/**
 * @author Yoshito Nakaue
 * @date 2020/11/02
 */

#include "SSystem.hpp"
#include "SCursor.hpp"
#include <EZGP/Mouse.hpp>
#include <EZGP/Font.hpp>
#include <SDL_image.h>
#include <SDL_ttf.h>

namespace ezgp
{
    int SSystem::CreateWindow(int win_width, int win_height)
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

        win_width_  = win_width;
        win_height_ = win_height;

        window_ = SDL_CreateWindow(
            "Window Title",
            100,
            100,
            win_width_,
            win_height_,
            0
        );

        if (!window_)
        {
            SDL_Log("Failed to create window : %s", SDL_GetError());
            return 1;
        }

        renderer_ = SDL_CreateRenderer(
            window_,
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
        );
        SDL_SetRenderDrawBlendMode(renderer_, SDL_BLENDMODE_BLEND);


        ticks_count_ = SDL_GetTicks();

        return 0;
    }

    bool SSystem::Update()
    {
        InputKeys();
        Draw();
        RunSystem();

        return is_running_;
    }

    void SSystem::SetBackgroundColor(Color color)
    {
        bg_color_.red = color.red;
        bg_color_.green = color.green;
        bg_color_.blue = color.blue;
        bg_color_.alpha = 255;
    }

    void SSystem::EndLoop()
    {
        is_running_ = false;
    }

    void SSystem::Quit()
    {
        SDL_DestroyRenderer(renderer_);
        SDL_DestroyWindow(window_);
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
    }

    void SSystem::RunSystem()
    {
        while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticks_count_ + 16))
            ;

        float dt = (SDL_GetTicks() - ticks_count_) / 1000.0f;
        if (dt > 0.05f)
            dt = 0.05f;

        ticks_count_ = SDL_GetTicks();
    }

    void SSystem::Draw()
    {
        SDL_RenderPresent(renderer_);

        SDL_SetRenderDrawColor(
            renderer_,
            bg_color_.red,
            bg_color_.green,
            bg_color_.blue,
            bg_color_.alpha
        );
        SDL_RenderClear(renderer_);
    }

    void SSystem::InputKeys()
    {
        // 押下時の反応を初期化
        MouseLeft.down = false;
        MouseRight.down = false;
        MouseMiddle.down = false;

        SDL_Event ev;
        while (SDL_PollEvent(&ev))
        {
            switch (ev.type)
            {
            case SDL_QUIT:
                is_running_ = false;
                break;

            case SDL_MOUSEBUTTONDOWN:
                if (ev.button.button == SDL_BUTTON_LEFT)
                {
                    if (!MouseLeft.pressed)
                        MouseLeft.down = true;
                    MouseLeft.pressed = true;
                }
                else if (ev.button.button == SDL_BUTTON_RIGHT)
                {
                    if (!MouseRight.pressed)
                        MouseRight.down = true;
                    MouseRight.pressed = true;
                }
                else if (ev.button.button == SDL_BUTTON_MIDDLE)
                {
                    if (!MouseMiddle.pressed)
                        MouseMiddle.down = true;
                    MouseMiddle.pressed = true;
                }
                break;

            case SDL_MOUSEBUTTONUP:
                if (ev.button.button == SDL_BUTTON_LEFT)
                    MouseLeft.pressed = false;
                else if (ev.button.button == SDL_BUTTON_RIGHT)
                    MouseRight.pressed = false;
                else if (ev.button.button == SDL_BUTTON_MIDDLE)
                    MouseMiddle.pressed = false;
                break;

            default:
                break;
            }
            break;
        }

        const Uint8* key_state = SDL_GetKeyboardState(NULL);
        if (key_state[SDL_SCANCODE_ESCAPE])
            is_running_ = false;
    }

    void SSystem::Create()
    {
        if (!pSystem)
            pSystem = new SSystem();
    }

    void SSystem::Destroy()
    {
        delete pSystem;
        pSystem = NULL;
    }

    // インスタンス
    SSystem* SSystem::pSystem = NULL;
}
