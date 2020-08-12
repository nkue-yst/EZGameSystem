/**
 * @file Shader.hpp
 * @brief シェーダー管理クラス
 * @author Yoshito Nakaue
 * @date 2020/08/13
 */

#pragma once
#include <GL/glew.h>
#include <string>

namespace ezgs
{
    /**
     * @brief シェーダー管理クラス
     */
    class Shader
    {
    public:
        Shader();
        ~Shader();

        /**
         * @brief シェーダープログラムを作成
         * @param vert_name : 頂点シェーダー名
         * @param frag_name : フラグシェーダー名
         * @return 成功時 0、 失敗時 1
         */
        int Load(const std::string& vert_name, const std::string& frag_name);

        /**
         * @brief シェーダープログラムを破棄
         * @return なし
         */
        void Unload();

        /**
         * @brief アクティブ状態にセットする
         * @return なし
         */
        void SetActive();

        /**
         * @brief ---
         * @param name : 行列名
         * @param mat : 行列
         * @return なし
         */
        void SetMatUniform(const char* name, const class Mat4& mat);

    private:
        /**
         * @brief シェーダーコンパイル
         * @param file_name : シェーダーファイル名
         * @param shader_type : シェーダーの種類
         * @param out_shader : コンパイルしたシェーダープログラムの格納先
         * @return 成功時 0、失敗時 1
         */
        int CompileShader(const std::string& file_name, GLenum shader_type, GLuint& out_shader);

        /**
         * @brief シェーダーコンパイル成功判定
         * @param shader : 判定するシェーダープログラム
         * @return 成功時 0、失敗時1
         */
        int IsCompiled(GLuint shader);

        /**
         * @brief プログラムのリンクを確認
         * @return 成功時 0、失敗時1
         */
        int IsValidProgram();
        
        // 頂点シェーダーID
        GLuint id_vertex_shader_;

        // フラグシェーダーID
        GLuint id_frag_shader_;

        // シェーダープログラム
        GLuint shader_program_;
    };
}
