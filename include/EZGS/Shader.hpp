/**
 * @file Shader.hpp
 * @brief �V�F�[�_�[�Ǘ��N���X
 * @author Yoshito Nakaue
 * @date 2020/08/12
 */

#pragma once
#include <GL/glew.h>
#include <string>

namespace ezgs
{
    /**
     * @brief �V�F�[�_�[�Ǘ��N���X
     */
    class Shader
    {
    public:
        Shader();
        ~Shader();

        /**
         * @brief �V�F�[�_�[�v���O�������쐬
         * @param vert_name : ���_�V�F�[�_�[��
         * @param frag_name : �t���O�V�F�[�_�[��
         * @return ������ 0�A ���s�� 1
         */
        int Load(const std::string& vert_name, const std::string& frag_name);

    private:
        /**
         * @brief �V�F�[�_�[�R���p�C��
         * @param file_name : �V�F�[�_�[�t�@�C����
         * @param shader_type : �V�F�[�_�[�̎��
         * @param out_shader : �R���p�C�������V�F�[�_�[�v���O�����̊i�[��
         * @return ������ 0�A���s�� 1
         */
        int CompileShader(const std::string& file_name, GLenum shader_type, GLuint& out_shader);

        /**
         * @brief �V�F�[�_�[�R���p�C����������
         * @param shader : ���肷��V�F�[�_�[�v���O����
         * @return ������ 0�A���s��1
         */
        int IsCompiled(GLuint shader);

        /**
         * @brief �v���O�����̃����N���m�F
         * @return ������ 0�A���s��1
         */
        int IsValidProgram();
        
        // ���_�V�F�[�_�[ID
        GLuint id_vertex_shader_;

        // �t���O�V�F�[�_�[ID
        GLuint id_frag_shader_;

        // �V�F�[�_�[�v���O����
        GLuint shader_program_;
    };
}
