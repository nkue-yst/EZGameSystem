/**
 * @file Texture.hpp
 * @brief �e�N�X�`���Ǘ��N���X
 * @author Yoshito Nakaue
 * @date 2020/08/13
 */

#pragma once
#include <string>
#include <GL/glew.h>

namespace ezgs
{
    /**
     * @brief �e�N�X�`���Ǘ��N���X
     */
    class Texture
    {
    public:
        Texture();
        ~Texture();

        /**
         * @brief �摜�f�[�^��ǂݍ���
         * @param file_name : �摜�t�@�C����
         * @return ������ 0�A���s�� 1
         */
        int LoadImage(const std::string& file_name);

        /**
         * @brief �摜�f�[�^���폜
         * @return �Ȃ�
         */
        void UnloadImage();

        /**
         * @brief �e�N�X�`�����A�N�e�B�u��Ԃ�
         * @return �Ȃ�
         */
        void SetActive() { glBindTexture(GL_TEXTURE_2D, texture_id_); }

        /* Getter */
        const int GetWidth()  const { return width_; }
        const int GetHeight() const { return height_; }

    private:
        // �e�N�X�`��ID
        unsigned int texture_id_;

        // �摜�̉���
        int width_;

        // �摜�̍���
        int height_;
    };
}