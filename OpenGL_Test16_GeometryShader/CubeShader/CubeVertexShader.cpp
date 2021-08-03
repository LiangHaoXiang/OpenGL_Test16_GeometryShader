#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

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

uniform mat4 model;

out VS_OUT
{
    vec3 Normal;
    vec3 Position;
} vs_out;

void main()
{
    vs_out.Normal = mat3(transpose(inverse(model))) * aNormal;
    vs_out.Position = vec3(model * vec4(aPos, 1.0));
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}
