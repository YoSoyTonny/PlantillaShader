#version 330 core
//La primera linea, siempre es la version... SIEMPREEEE!!! ESTA CLARO!?? ok...

//Atributos de enrtada (viene desde c++)
in vec3 posicion;
in vec4 color;

//Atributod de salida (Estos van hacia el fragment shader)
out vec4 fragmentColor;

//Establecer una funcion main
void main() {
	//Es la posicion de salida del vertice
	//Es del tipo vec4
	gl_Position.xyz = posicion;
	gl_Position.w = 1.0;

	//Establecer valores de atributos de salida
	fragmentColor = color;
}