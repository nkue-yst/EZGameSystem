/**
 * @author Yoshito Nakaue
 * @date 2020/08/11
 */

#include <EZGS/VertexArray.hpp>
#include <GL/glew.h>

namespace ezgs
{
    VertexArray::VertexArray(const float* verts, unsigned int num_verts,
        const unsigned int* indices, unsigned int num_indices)
        :num_verts_(num_verts)
        ,num_indices_(num_indices)
    {
        /* 頂点配列オブジェクトの作成 */
        glGenVertexArrays(1, &id_vertex_array_);
        glBindVertexArray(id_vertex_array_);

        /* 頂点バッファの作成 */
        glGenBuffers(1, &id_vertex_buffer_);
        glBindBuffer(GL_ARRAY_BUFFER, id_vertex_buffer_);
        glBufferData(
            GL_ARRAY_BUFFER,
            num_verts * 5 * sizeof(float),
            verts,
            GL_STATIC_DRAW
        );

        /* インデックスバッファの作成 */
        glGenBuffers(1, &id_index_buffer_);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_index_buffer_);
        glBufferData(
            GL_ELEMENT_ARRAY_BUFFER,
            num_indices * sizeof(unsigned int),
            indices,
            GL_STATIC_DRAW
        );

        /* 頂点属性の設定 */
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(
            0,
            3,
            GL_FLOAT,
            GL_FALSE,
            sizeof(float) * 5,
            0
        );
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(
            1,
            2,
            GL_FLOAT,
            GL_FALSE,
            sizeof(float) * 5,
            reinterpret_cast<void*>(sizeof(float) * 3)
        );
    }

    VertexArray::~VertexArray()
    {
        glDeleteBuffers(1, &id_index_buffer_);
        glDeleteBuffers(1, &id_vertex_buffer_);
        glDeleteVertexArrays(1, &id_vertex_array_);
    }

    void VertexArray::SetActive()
    {
        glBindVertexArray(id_vertex_array_);
    }
}