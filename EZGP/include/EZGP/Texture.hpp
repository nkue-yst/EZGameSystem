/**
 * @file Texture.hpp
 * @brief �e�N�X�`���Ǘ��N���X
 * @author Yoshito Nakaue
 * @date 2020/09/06
 */

#pragma once
#include <SDL.h>

namespace ezgp
{
    /**
     * @brief �e�N�X�`���Ǘ��N���X
     */
    class Texture
    {
    public:
        // �t�@�C�������w�肵�ēǂݍ���
        Texture(const char* file_name);
        ~Texture();

        /**
         * @brief �w����W�ɉ摜��`��
         * @param x x���W
         * @param y y���W
         * @return �Ȃ�
         */
        void draw(int x, int y);

        /**
         * @brief �w�肵���T�C�Y�Ɋg��k��
         * @param width ���T�C�Y��̉���
         * @param height ���T�C�Y��̍���
         * @return �Ȃ�
         */
        void resize(int width, int height);

        /**
         * @brief �g��k�������ĕ`�悷��
         * @param x x���W
         * @param y y���W
         * @param width ���T�C�Y��̉���
         * @param height ���T�C�Y��̍���
         * @return �Ȃ�
         */
        void resizeAt(int x, int y, int width, int height);

        /**
         * @brief �摜����]�����ĕ`�悷��
         * @param x x���W
         * @param y y���W
         * @param angle ��]�p�x(�x���@)
         * @return �Ȃ�
         */
        void rotateAt(int x, int y, int angle);

        /* Getter */
        const int GetWidth()  const { return width_; }
        const int GetHeight() const { return height_; }

    private:
        /**
         * @brief �摜�f�[�^��ǂݍ���
         * @param file_name : �摜�t�@�C����
         * @return �摜����쐬�����e�N�X�`��
         */
        SDL_Texture* LoadImage(const char* file_name);

        /**
         * @brief �摜�f�[�^���폜
         * @return �Ȃ�
         */
        void UnloadImage();

        // �e�N�X�`���f�[�^
        SDL_Texture* texture_;

        // �摜�̉���
        int width_;

        // �摜�̍���
        int height_;
    };
}
