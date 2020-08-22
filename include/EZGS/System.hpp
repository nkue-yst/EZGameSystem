/**
 * @file System.hpp
 * @brief 描画システム関連
 * @author Yoshito Nakaue
 * @date 2020/08/21
 */

#pragma once
#include <EZGS/Color.hpp>
#include <EZGS/Texture.hpp>
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

            // 背景色
            Color bg_color = { 255, 255, 255, 255 };

            // Tickカウンター
            Uint32 ticks_count;

            // テクスチャ配列
            std::unordered_map<std::string, class Texture*> textures;

            // メインループの更新条件
            bool is_running = true;
        }

        extern SDL_Renderer* renderer;

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
         * @param file_name 検索ファイル名
         * @return 検索・追加したテクスチャ
         */
        class Texture* GetTexture(const std::string& file_name);

        /**
         * @brief 背景色を設定 (Scene::SetBackgroundColorから呼び出し)
         * @param R 赤(0~255)
         * @param G 緑(0~255)
         * @param B 青(0~255)
         * @return なし
         */
        void SetBackgroundColor(uint8_t R, uint8_t G, uint8_t B);
    }
}
