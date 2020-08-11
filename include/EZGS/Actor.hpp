/**
 * @file Actor.hpp
 * @brief アクタークラス
 * @author Yoshito Nakaue
 * @date 2020/08/11
 */

#pragma once

namespace ezgs
{		
	/**
	 * @brief Actorの状態クラス
	 */
	enum class State
	{
		EPause,
		EActive,
		EDead,
	};

	/**
	 * @brief Actorクラス
	 */
	class Actor
	{
	public:
		/**
		 * @brief システムにActor追加
		 */
		Actor();

		/**
		 * @brief システムからActorを削除
		 */
		virtual ~Actor();

		/**
		 * @brief Actor全体の更新
		 * @return なし
		 */
		void Update(float dt);

		/**
		 * @brief アクター自身の更新
		 * @return なし
		 */
		virtual void UpdateActor(float dt);

	private:
		// Actorの状態
		State state_;
	};
}
