#version 330

// @author Yoshito Nakaue
// @date 2020/08/13

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec2 in_tex_coord;

out vec2 frag_tex_coord;

void main()
{
    vec4 pos = vec4(in_position, 1.0);

    gl_Position = pos * world_transform * view_transform;

    frag_tex_coord = in_tex_coord;
}
