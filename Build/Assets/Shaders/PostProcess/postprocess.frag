#version 430 core 
  
in vec2 texcoord; 
  
out vec4 fcolor; 

uniform float offset; 
  
uniform sampler2D textureMap; 

  
void main() 
{ 
	//normal color
	fcolor = texture(textureMap, texcoord);

	// black / white 
	/*vec3 color = texture(textureMap, texcoord).rgb; 
	float avg = (color.r + color.g + color.b) / 3.0; 
	fcolor = vec4(vec3(avg), 1);*/

	//darken
//	vec3 color = texture(textureMap, texcoord).rgb;
//	fcolor = vec4(color / 2, 1);

	//brighten
//	vec3 color = texture(textureMap, texcoord).rgb;
//	fcolor = vec4(color * 3, 1);

	// invert 
//	vec3 color = texture(textureMap, texcoord).rgb; 
//  
//	fcolor = vec4(1.0 - color, 1); 


	//Wave
//	vec2 ttexcoord = texcoord; 
//	ttexcoord.x += sin(ttexcoord.y * 30.0 + offset) / 100.0; 
//	fcolor = texture(textureMap, ttexcoord); 
} 