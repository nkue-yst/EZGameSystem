/**
 * @file System.hpp
 * @brief 描画システム関連
 * @author Yoshito Nakaue
 * @date 2020/08/15
 */

#pragma once
#include <EZGS/Actor.hpp>
#include <EZGS/DrawComponent.hpp>
#include <EZGS/Shader.hpp>
#include <EZGS/Texture.hpp>
#include <EZGS/VertexArray.hpp>
#include <unordered_map>
#include <vector>
#include <SDL.h>

namespace ezgs
{
    namespace System
    {
        // 作成したウィンドウを格納
        static SDL_Window* window;

        // windowに描画するcontext
        static SDL_GLContext context;

        // Tickカウンター
        static Uint32 ticks_count;

        // アクター配列
        static std::vector<Actor*> actors;

        // 待機状態のアクター用配列
        static std::vector<Actor*> waiting_actors;

        // 描画コンポーネント用配列
        static std::vector<DrawComponent*> d_components;

        // テクスチャ配列
        static std::unordered_map<std::string, class Texture*> textures;

        // シェーダープログラム
        static Shader* shader;

        // 頂点配列
        static VertexArray* verts;

        // メインループの更新条件
        static bool is_running = true;

        // アクターを更新中かどうか
        static bool is_actor_updating = false;

        /**
         * @brief 描画システムを初期化、ウィンドウを作成
         * @return 成功時 0、失敗時 1
         */
        int CreateWindow();

        /**
         * @brief シェーダー読み込み
         * @return 成功時 0、失敗時 1
         */
        int LoadShader();

        /**
         * @brief 頂点配列を作成
         * @return なし
         */
        void CreateVerts();

        /**
         * @brief 描画システムの終了処理
         * @return なし
         */
        void Destroy();

        /**
         * @brief メインループでの更新
         * @return なし
         */
        void Update();

        /**
         * @brief システム全体の更新
         * @return なし
         */
        void RunSystem();

        /**
         * @brief 描画物を描画
         * @return なし
         */
        void Draw();

        /**
         * @brief データ破棄
         * @return なし
         */
        void UnloadData();

        /**
         * @brief Actorを追加
         * @return なし
         */
        void AddActor(Actor* actor);

        /**
         * @brief Actorを削除
         * @return なし
         */
        void RemoveActor(Actor* actor);

        /**
         * @brief 描画コンポーネントをシステムに追加
         * @param d_component : 追加するコンポーネント
         * @return なし
         */
        void AddDrawComponent(class DrawComponent* d_component);

        /**
         * @brief 描画コンポーネントをシステムから削除
         * @param d_component : 削除するコンポーネント
         * @return なし
         */
        void RemoveDrawComponent(class DrawComponent* d_component);

        /**
         * @brief システムからテクスチャを読み込み・追加
         * @param file_name : 検索ファイル名
         * @return 検索・追加したテクスチャ
         */
        class Texture* GetTexture(const std::string& file_name);
    }
}
