/**
 * @file System.hpp
 * @brief 描画システム関連
 * @author Yoshito Nakaue
 * @date 2020/08/10
 */

#pragma once
#include <EZGS/Actor.hpp>
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

		// メインループの更新条件
		static bool is_running;

		// アクター配列
		static std::vector<Actor*> actors;
		
		// 街状態のアクター用配列
		static std::vector<Actor*> waiting_actors;

		// アクターを更新中かどうか
		static bool is_actor_updating;

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
	}
}
