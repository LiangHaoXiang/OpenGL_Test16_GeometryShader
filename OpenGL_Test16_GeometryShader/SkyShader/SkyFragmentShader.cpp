#version 330 core
out vec4 FragColor;

in vec3 TexCoords;

uniform samplerCube skybox;

void main()
{
//    vec3 reverse = vec3(TexCoords.x, -TexCoords.y, TexCoords.z);
//    FragColor = texture(skybox, reverse);
    FragColor = texture(skybox, TexCoords);
}
