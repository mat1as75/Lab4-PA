#include "../DataTypes/DTLeccion.h"

DTLeccion::DTLeccion() {
}
DTLeccion::~DTLeccion() {
	
}
DTLeccion::DTLeccion(string tema, string objAprendizaje, vector<DTEjercicio*> misEjercicios) {
	this->tema=tema;
	this->objAprendizaje=objAprendizaje;
	this->misEjercicios=misEjercicios;
}
void DTLeccion::setTema(string tema){
	this->tema=tema;
}
void DTLeccion::setObjAprendizaje(string objAprendizaje){
	this->objAprendizaje=objAprendizaje;
}

string DTLeccion::getObjAprendizaje(){
	return this->objAprendizaje;
}

vector<DTEjercicio*> DTLeccion::getDTEjercicios() {
    return this->misEjercicios;
}