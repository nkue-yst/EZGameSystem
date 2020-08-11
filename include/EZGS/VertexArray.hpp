/**
 * @file VertexArray.hpp
 * @brief 頂点配列関連
 * @author Yoshito Nakaue
 * @date 2020/08/11
 */

#pragma once

namespace ezgs
{
    /**
     * @brief 頂点配列関連クラス
     */
    class VertexArray
    {
    public:
        VertexArray(const float* verts, unsigned int num_verts,
            const unsigned int* indices, unsigned int num_indices);
        ~VertexArray();

        /**
         * @brief アクティブ状態へ設定
         * @return なし
         */
        void SetActive();

        /**
         * @brief 頂点数取得
         * @return 頂点数（符号なし整数）
         */
        unsigned int GetNumVerts() const { return num_verts_; }

        /**
         * @brief インデックス数取得
         * @return インデックス数（符号なし整数）
         */
        unsigned int GetNumIndices() const { return num_indices_; }

    private:
        // 頂点数
        unsigned int num_verts_;

        // インデックス数
        unsigned int num_indices_;

        // 頂点バッファID
        unsigned int id_vertex_buffer_;

        // インデックスバッファID
        unsigned int id_index_buffer_;

        // 頂点配列ID
        unsigned int id_vertex_array_;
    };
}
