#version 150 core
uniform mat4 projection;
uniform mat4 modelview;
in vec4 position;
void main(){
	gl_Position = projection * modelview * position;
}