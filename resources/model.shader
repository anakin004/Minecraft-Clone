#shader vertex
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec2 TexCoords;

uniform mat4 u_camMatrix;

void main()
{
    TexCoords = aTexCoords;    
    gl_Position = u_camMatrix * vec4(aPos, 1.0);
}

#shader fragment
#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;

void main()
{    
    FragColor = texture(texture_diffuse1, TexCoords) + texture(texture_specular1, TexCoords) ;
 
}
