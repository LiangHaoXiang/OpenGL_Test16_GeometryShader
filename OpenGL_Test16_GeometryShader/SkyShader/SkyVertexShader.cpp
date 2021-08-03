#version 330 core
layout (location = 0) in vec3 aPos;

layout (std140) uniform Matrices_Projection
{
                        // 基准对齐量       // 对齐偏移量
    mat4 projection;    //  16                  0
};

out vec3 TexCoords;

uniform mat4 view;

void main()
{
    TexCoords = aPos;
    vec4 pos = projection * view * vec4(aPos, 1.0);
    gl_Position = pos;
}
