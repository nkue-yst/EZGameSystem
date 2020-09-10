/**
 * @file EZGP_System.hpp
 * @brief 描画システム関連
 * @author Yoshito Nakaue
 * @date 2020/09/08
 */

#pragma once
#include <EZGP/Color.hpp>
#include <EZGP/Cursor.hpp>
#include <EZGP/Texture.hpp>
#include <vector>
#include <SDL.h>

namespace ezgp
{
    class SSystem
    {
    public:
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
         * @brief 背景色を設定 (Scene::SetBackgroundColorから呼び出し)
         * @param Color color
         * @return なし
         */
        void SetBackgroundColor(Color color);

        /**
         * @brief is_runningにfalseを代入しメインループを終了する
         * @return なし
         */
        void EndLoop();

        /**
         * @brief 描画システムの終了処理
         * @return なし
         */
        void Quit();

        SDL_Renderer* GetRenderer() { return renderer_; }


        // インスタンスの作成
        static void Create();
        // インスタンスの破棄
        static void Destroy();
        // インスタンスの取得
        static SSystem* GetSystem() { return pSystem; }

    protected:
        // インスタンス
        static SSystem* pSystem;
        // 非公開コンストラクタ
        SSystem():renderer_(nullptr), ticks_count_(0), window_(nullptr) {}

    private:
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

        // 作成したウィンドウを格納
        SDL_Window* window_;

        // レンダラー
        SDL_Renderer* renderer_;

        // 背景色
        Color bg_color_ = { 255, 255, 255, 255 };

        // Tickカウンター
        Uint32 ticks_count_;

        // メインループの更新条件
        bool is_running_ = true;
    };
}
