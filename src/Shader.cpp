/**
 * @author Yoshito Nakaue
 * @date 2020/08/13
 */

#include <EZGS/Shader.hpp>
#include <EZGS/Math.hpp>
#include <fstream>
#include <sstream>
#include <SDL.h>

namespace ezgs
{
    Shader::Shader()
        :id_vertex_shader_(0)
        , id_frag_shader_(0)
        , shader_program_(0)
    {

    }

    Shader::~Shader()
    {

    }

    int Shader::Load(const std::string& vert_name, const std::string& frag_name)
    {
        if (!CompileShader(vert_name, GL_VERTEX_SHADER, id_vertex_shader_) ||
            !CompileShader(frag_name, GL_FRAGMENT_SHADER, id_frag_shader_))
        {
            return false;
        }

        shader_program_ = glCreateProgram();
        glAttachShader(shader_program_, id_vertex_shader_);
        glAttachShader(shader_program_, id_frag_shader_);
        glLinkProgram(shader_program_);

        if (!IsValidProgram())
        {
            return 1;
        }

        return 0;
    }

    void Shader::Unload()
    {
        glDeleteProgram(shader_program_);
        glDeleteShader(id_frag_shader_);
        glDeleteShader(id_vertex_shader_);
    }

    void Shader::SetActive()
    {
        glUseProgram(shader_program_);
    }

    void Shader::SetMatUniform(const char* name, const Mat4& mat)
    {
        GLuint loc_id = glGetUniformLocation(shader_program_, name);
        glUniformMatrix4fv(
            loc_id,
            1,
            GL_TRUE,
            mat.GetPointer()
        );
    }

    int Shader::CompileShader(const std::string& file_name, GLenum shader_type, GLuint& out_shader)
    {
        std::ifstream shader_file(file_name);
        if (shader_file.is_open())
        {
            std::stringstream s;
            s << shader_file.rdbuf();
            std::string contents = s.str();
            const char* contents_char = contents.c_str();

            out_shader = glCreateShader(shader_type);
            glShaderSource(out_shader, 1, &(contents_char), nullptr);
            glCompileShader(out_shader);

            if (!IsCompiled(out_shader))
            {
                SDL_Log("Failed to compile %s.", file_name.c_str());
                return 1;
            }
        }
        else
        {
            SDL_Log("Failed to find %s.", file_name.c_str());
            return 1;
        }

        return 0;
    }

    int Shader::IsCompiled(GLuint shader)
    {
        GLint status;

        glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
        if (status != GL_TRUE)
        {
            char buf[512];
            memset(buf, 0, 512);
            glGetShaderInfoLog(shader, 511, nullptr, buf);
            SDL_Log("Failed to compile GLSL. : \n%s", buf);
            return 1;
        }

        return 0;
    }

    int Shader::IsValidProgram()
    {
        GLint status;

        glGetProgramiv(shader_program_, GL_LINK_STATUS, &status);
        if (status != GL_TRUE)
        {
            char buf[512];
            memset(buf, 0, 512);
            glGetProgramInfoLog(shader_program_, 511, nullptr, buf);
            SDL_Log("Failed to link GLSL. : \n%s", buf);
            return 1;
        }

        return 0;
    }
}