#include "../DataTypes/DTRealizaCF.h"

DTRealizaCF::DTRealizaCF() {
	
}

DTRealizaCF::~DTRealizaCF() {
	
}

DTRealizaCF::DTRealizaCF(string nombreEjercicio,string descEjercicio, string FraseACompletar):DTRealizaEjercicio(nombreEjercicio , descEjercicio) {
	this->FraseIncompleta = FraseACompletar;
}
