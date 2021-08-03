#version 330 core
layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

in VS_OUT {
    vec3 Normal;
    vec3 Position;
} gs_in[];

out GS_OUT {
    vec3 Normal;
    vec3 Position;
} gs_out;

//爆破位移处理
vec4 explode(vec4 position, vec3 normal)
{
    vec3 direction = normal;
    return position + vec4(direction, 1.0);
//    return position;
}

void main()
{
    gl_Position = explode(gl_in[0].gl_Position, gs_in[0].Normal);
    gs_out.Normal = gs_in[0].Normal;
    gs_out.Position = gs_in[0].Position;
    EmitVertex();
    gl_Position = explode(gl_in[1].gl_Position, gs_in[1].Normal);
    gs_out.Normal = gs_in[1].Normal;
    gs_out.Position = gs_in[1].Position;
    EmitVertex();
    gl_Position = explode(gl_in[2].gl_Position, gs_in[2].Normal);
    gs_out.Normal = gs_in[2].Normal;
    gs_out.Position = gs_in[2].Position;
    EmitVertex();
    EndPrimitive();
}
