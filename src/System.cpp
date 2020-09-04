/**
 * @author Yoshito Nakaue
 * @date 2020/09/04
 */

#include <EZGS/System.hpp>
#include <EZGS/Font.hpp>
#include <SDL_image.h>
#include <SDL_ttf.h>

namespace ezgs
{
    int System::CreateWindow()
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

        window_ = SDL_CreateWindow(
            "Window Title",
            100,
            100,
            1280,
            720,
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

    bool System::Update()
    {
        InputKeys();
        Draw();
        RunSystem();

        return is_running_;
    }

    void System::SetBackgroundColor(uint8_t R, uint8_t G, uint8_t B)
    {
        bg_color_.red = R;
        bg_color_.green = G;
        bg_color_.blue = B;
        bg_color_.alpha = 255;
    }

    void System::EndLoop()
    {
        is_running_ = false;
    }

    void System::Quit()
    {
        UnloadData();
        SDL_DestroyRenderer(renderer_);
        SDL_DestroyWindow(window_);
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
    }

    void System::RunSystem()
    {
        while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticks_count_ + 16))
            ;

        float dt = (SDL_GetTicks() - ticks_count_) / 1000.0f;
        if (dt > 0.05f)
            dt = 0.05f;

        ticks_count_ = SDL_GetTicks();
    }

    void System::Draw()
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

    void System::InputKeys()
    {
        SDL_Event ev;
        while (SDL_PollEvent(&ev))
        {
            switch (ev.type)
            {
                case SDL_QUIT:
                    is_running_ = false;
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

    void System::UnloadData()
    {
        /* テクスチャを破棄 */
        for (auto iter : textures_)
        {
            iter.second->UnloadImage();
            delete iter.second;
        }
        textures_.clear();
    }

    Texture* System::GetTexture(const std::string& file_name)
    {
        Texture* texture = nullptr;

        auto iter = textures_.find(file_name);
        if (iter != textures_.end())
            texture = iter->second;
        else
        {
            texture = new Texture();
            if (!texture->LoadImage(file_name))
                textures_.emplace(file_name, texture);
            else
            {
                delete texture;
                texture = nullptr;
            }
        }
        return texture;
    }

    void System::Create()
    {
        if (!iSystem)
            iSystem = new System();
    }

    void System::Destroy()
    {
        delete iSystem;
        iSystem = NULL;
    }


    // インスタンス
    System* System::iSystem = NULL;

    void EZGS_Init()
    {
        System::Create();
        System::GetSystem()->CreateWindow();
    }

    bool Update()
    {
        return System::GetSystem()->Update();
    }

    void EZGS_Quit()
    {
        System::GetSystem()->Quit();
        System::Destroy();
    }
}
