#version 330

uniform sampler2D texture_;

in vec2 frag_tex_coord;

out vec4 out_color;

void main()
{
    out_color = texture(texture_, frag_tex_coord);
}
