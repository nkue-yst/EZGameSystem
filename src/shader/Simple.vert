#version 330

uniform mat4 world_transform;
uniform mat4 view_transform;

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec2 in_tex_coord;

out vec2 frag_tex_coord;

void main()
{
    vec4 pos = vec4(in_position, 1.0);

    gl_Position = pos * world_transform * view_transform;

    frag_tex_coord = in_tex_coord;
}
