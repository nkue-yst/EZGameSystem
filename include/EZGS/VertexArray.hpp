/**
 * @file VertexArray.hpp
 * @brief ���_�z��֘A
 * @author Yoshito Nakaue
 * @date 2020/08/11
 */

#pragma once

namespace ezgs
{
    /**
     * @brief ���_�z��֘A�N���X
     */
    class VertexArray
    {
    public:
        VertexArray(const float* verts, unsigned int num_verts,
            const unsigned int* indices, unsigned int num_indices);
        ~VertexArray();

        /**
         * @brief �A�N�e�B�u��Ԃ֐ݒ�
         * @return �Ȃ�
         */
        void SetActive();

        /**
         * @brief ���_���擾
         * @return ���_���i�����Ȃ������j
         */
        unsigned int GetNumVerts() const { return num_verts_; }

        /**
         * @brief �C���f�b�N�X���擾
         * @return �C���f�b�N�X���i�����Ȃ������j
         */
        unsigned int GetNumIndices() const { return num_indices_; }

    private:
        // ���_��
        unsigned int num_verts_;

        // �C���f�b�N�X��
        unsigned int num_indices_;

        // ���_�o�b�t�@ID
        unsigned int id_vertex_buffer_;

        // �C���f�b�N�X�o�b�t�@ID
        unsigned int id_index_buffer_;

        // ���_�z��ID
        unsigned int id_vertex_array_;
    };
}
