/**
 * @file Component.hpp
 * @brief コンポーネントクラス
 * @author Yoshito Nakaue
 * @date 2020/08/11
 */

#pragma once

namespace ezgs
{
    /**
     * @brief コンポーネント基底クラス
     */
    class Component
    {
    public:
        /**
         * @brief 所有アクター、更新優先度を設定
         */
        Component(class Actor* owner, int update_order = 100);

        /**
         * @brief 所有アクターからコンポーネントを削除
         */
        virtual ~Component();

        /**
         * @brief コンポーネントの更新
         * @return なし
         */
        virtual void Update(float dt);

        /**
         * @brief ワールド座標の計算
         * @return なし
         */
        virtual void NotifiedUpdateWorldTransform() {};

        /**
         * @brief 更新優先度の取得
         * @return コンポーネントの更新優先度（整数値）
         */
        int GetUpdateOrder() const { return update_order_; }

    protected:
        // 所有アクター
        class Actor* owner_;

        // 更新優先度
        int update_order_;
    };
}
