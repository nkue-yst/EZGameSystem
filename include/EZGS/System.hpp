/**
 * @file System.hpp
 * @brief 描画システム関連
 * @author Yoshito Nakaue
 * @date 2020/08/10
 */

#pragma once
#include <SDL.h>

namespace ezgs
{
	namespace System
	{
		// 作成したウィンドウを格納
		static SDL_Window* window;

		// windowに描画するcontext
		static SDL_GLContext context;

		// メインループの更新条件
		static bool is_running;

		/**
		 * @brief 描画システムを初期化、ウィンドウを作成
		 * @return 成功時 0、失敗時 1
		 */
		int CreateWindow();

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
	}
}
