#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;
uniform sampler2D texture_normal1;
uniform sampler2D texture_height1;

void main()
{
    vec4 diffuse = texture(texture_diffuse1, TexCoords);
    vec4 specular = texture(texture_specular1, TexCoords);
    vec4 normal = texture(texture_normal1, TexCoords);
    vec4 height = texture(texture_height1, TexCoords);
    FragColor = diffuse * 0.8 + specular * 0.05 + normal * 0.05 + height * 0.15;
}
