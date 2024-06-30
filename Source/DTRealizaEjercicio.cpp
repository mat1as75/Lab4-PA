#include "../DataTypes/DTRealizaEjercicio.h"

DTRealizaEjercicio::DTRealizaEjercicio() {
	
}

DTRealizaEjercicio::~DTRealizaEjercicio() {
	
}

DTRealizaEjercicio::DTRealizaEjercicio(string nombreEjercicio,string descEjercicio) {
	this->nombreEjercicio=nombreEjercicio;
	this->descEjercicio=descEjercicio;
}
string DTRealizaEjercicio::getNombre(){
	return this->nombreEjercicio;
}
