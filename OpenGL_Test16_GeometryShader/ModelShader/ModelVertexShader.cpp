#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

layout (std140) uniform Matrices_Projection
{
                        // 基准对齐量       // 对齐偏移量
    mat4 projection;    //  16                  0
};

layout (std140) uniform Matrices_View
{
                        // 基准对齐量       // 对齐偏移量
    mat4 view;          //  0                  16
};

out VS_OUT {
    vec2 texCoords;
} vs_out;

uniform mat4 model;

void main()
{
    vs_out.texCoords = aTexCoords;
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}
