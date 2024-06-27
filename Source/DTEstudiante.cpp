#include "DTEstudiante.h"

DTEstudiante::DTEstudiante() {
	
}

DTEstudiante::DTEstudiante(string nombre, string descripcion, string paisRes): DATAUSUARIO(nombre,descripcion) {
	this->paisRes=paisRes;
}

string DTEstudiante::toString() {
	return "Estudiante: " + this->nombre + ", " + this->descripcion  + ", " + this->paisRes + "\n" ;
}
DTEstudiante::~DTEstudiante() {
	
}