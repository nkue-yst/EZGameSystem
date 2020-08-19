/**
 * @file System.hpp
 * @brief 描画システム関連
 * @author Yoshito Nakaue
 * @date 2020/08/20
 */

#pragma once
#include <EZGS/Color.hpp>
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
        namespace
        {
            // 作成したウィンドウを格納
            SDL_Window* window;

            // windowに描画するcontext
            SDL_GLContext context;

            // 背景色
            Color bg_color = { 1.0f, 1.0f, 1.0f, 1.0f };

            // Tickカウンター
            Uint32 ticks_count;

            // テクスチャ配列
            std::unordered_map<std::string, class Texture*> textures;

            // シェーダープログラム
            Shader* shader;

            // 頂点配列
            VertexArray* verts;

            // メインループの更新条件
            bool is_running = true;
        }

        /*****
         *** Public Function
         ****/

        /**
         * @brief 描画システムを初期化、ウィンドウを作成
         * @return 成功時 0、失敗時 1
         */
        int CreateWindow();

        /**
         * @brief メインループでの更新
         * @return メインループを更新するかどうか
         */
        bool Update();

        /**
         * @brief is_runningにfalseを代入しメインループを終了する
         * @return なし
         */
        void EndLoop();

        /**
         * @brief 描画システムの終了処理
         * @return なし
         */
        void EZGS_Quit();


        /*****
         *** Private Function
         ****/

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
         * @brief 入力を受け付ける
         * @return なし
         */
        void InputKeys();

        /**
         * @brief データ破棄
         * @return なし
         */
        void UnloadData();

        /**
         * @brief システムからテクスチャを読み込み・追加
         * @param file_name : 検索ファイル名
         * @return 検索・追加したテクスチャ
         */
        class Texture* GetTexture(const std::string& file_name);

        /**
         * @brief 背景色を設定 (Scene::SetBackgroundColorから呼び出し)
         * @param R : 赤 0.0 ~ 1.0
         * @param G : 緑 0.0 ~ 1.0
         * @param B : 青 0.0 ~ 1.0
         * @return なし
         */
        void SetBackgroundColor(float R, float G, float B);
    }
}

#define ezgs_main() main(int argc, char **argv)
