﻿/**
 * @author Yoshito Nakaue
 * @date 2020/08/15
 */

#include <EZGS/System.hpp>
#include <EZGS/Math.hpp>
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

        void Destroy()
        {
            UnloadData();
            delete verts;
            shader->Unload();
            delete shader;
            SDL_GL_DeleteContext(context);
            SDL_DestroyWindow(window);
            SDL_Quit();
        }

        void Update()
        {
            while (is_running)
            {
                RunSystem();
                Draw();
            }
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

            /* アクターの更新 */
            is_actor_updating = true;
            for (auto actor : actors)
                actor->Update(dt);
            is_actor_updating = false;

            /* 待機アクターをactorsに移動 */
            for (auto actor : waiting_actors)
            {
                actor->ComputeWorldTransform();
                actors.emplace_back(actor);
            }
            waiting_actors.clear();

            /* 死亡アクターを一時保存後に破棄 */
            std::vector<Actor*> dead_actors;
            for (auto actor : actors)
                if (actor->GetState() == State::EDead)
                    dead_actors.emplace_back(actor);

            for (auto actor : dead_actors)
                delete actor;
        }

        void Draw()
        {
            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            shader->SetActive();
            verts->SetActive();

            for (auto component : d_components)
                component->Draw();

            SDL_GL_SwapWindow(window);
        }

        void UnloadData()
        {
            /* アクターを破棄 */
            while (!actors.empty())
                delete actors.back();

            /* テクスチャを破棄 */
            for (auto iter : textures)
            {
                iter.second->UnloadImage();
                delete iter.second;
            }
            textures.clear();
        }

        void AddActor(Actor* actor)
        {
            if (is_actor_updating)
                waiting_actors.emplace_back(actor);
            else
                actors.emplace_back(actor);
        }

        void RemoveActor(Actor* actor)
        {
            auto iter = std::find(waiting_actors.begin(), waiting_actors.end(), actor);
            if (iter != waiting_actors.end())
            {
                std::iter_swap(iter, waiting_actors.end() - 1);
                waiting_actors.pop_back();
            }

            iter = std::find(actors.begin(), actors.end(), actor);
            if (iter != actors.end())
            {
                std::iter_swap(iter, actors.end() - 1);
                actors.pop_back();
            }
        }

        void AddDrawComponent(DrawComponent* d_component)
        {
            int draw_order = d_component->GetDrawOrder();

            auto iter = d_components.begin();
            for (; iter != d_components.end(); ++iter)
                if (draw_order < (*iter)->GetDrawOrder())
                    break;

            d_components.insert(iter, d_component);
        }

        void RemoveDrawComponent(DrawComponent* d_component)
        {
            auto iter = std::find(d_components.begin(), d_components.end(), d_component);
            d_components.erase(iter);
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
                if (texture->LoadImage(file_name))
                    textures.emplace(file_name, texture);
                else
                {
                    delete texture;
                    texture = nullptr;
                }
            }
            return texture;
        }
    }
}
