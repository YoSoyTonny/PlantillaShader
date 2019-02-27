#include "stdafx.h"
#include "Shader.h"

GLuint shader::getID() {
	return shaderID;
}

shader::shader(const char * rutaVertex, const char * rutaFragment) {

	string codigoVertexShader;
	ifstream vertexShaderStream(rutaVertex, ios::in);
	if (vertexShaderStream.is_open()) {
		string linea;
		while (getline(vertexShaderStream, linea)){
			codigoVertexShader +=
			linea + "\n";
	}
	vertexShaderStream.close();
}
else {
		cout << "No se pudo abrir el archivo" << rutaVertex << endl;
	}


string codigoFragmentShader;
ifstream fragmentShaderStream(rutaFragment, ios::in);
if (fragmentShaderStream.is_open()) {
	string linea;
	while (getline(vertexShaderStream, linea)) {
		codigoVertexShader +=
			linea + "\n";
	}
	fragmentShaderStream.close();
}
else {
	cout << "No se pudo abrir el archivo" << rutaFragment << endl;
}

//Convertir de string a cadena de char
const char * cadenaCodigoVertex = codigoVertexShader.c_str();
const char * cadenaCodigoFragment = codigoFragmentShader.c_str();

//1.- crear el programa de shader
shaderID = glCreateProgram();
GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

//2.- Cargar el codigo del shader
glShaderSource(vertexShaderID, 1, &cadenaCodigoVertex, NULL);
glShaderSource(fragmentShaderID, 1, &cadenaCodigoFragment, NULL);

//3.- Compilar los Shader

glCompileShader(vertexShaderID);
glCompileShader(fragmentShaderID);

}

void Shader::verificarCompilacion(GLuint id) {
	GLint resultado = GL_FALSE;
	int longitudLog = 0;
}
