#version 430 core 
in vec3 vposition;
in vec3 vcolor;

out vec3 color;

void main()
{
	color = vcolor;

	gl_Position = vec4(vposition, 1.0);
}
