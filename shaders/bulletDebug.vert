#version 120

//Vertex Properties
attribute vec4 vPosition;
attribute vec4 vColor;

varying vec4 fColor;

uniform mat4 MVP;

void main()
{
	gl_Position=MVP*vPosition; //MVP * vPosition
	fColor=vColor;
}
