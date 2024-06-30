#include "../DataTypes/DTInscripcion.h"


DTInscripcion::DTInscripcion() {
	
}

DTInscripcion::~DTInscripcion() {
	
}
DTInscripcion::DTInscripcion(string nombreCurso, string nickname, Date* fechaInscripcion) {
	this->nombreCurso=nombreCurso;
	this->nickname=nickname;
	this->fechaInscripcion=fechaInscripcion;
}

DTInscripcion::DTInscripcion(string nombre, Date* fechaInscripcion){
	this->nombre=nombre;
	this->fechaInscripcion=fechaInscripcion;
}
