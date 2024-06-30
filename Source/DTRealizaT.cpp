#include "../DataTypes/DTRealizaT.h"

DTRealizaT::DTRealizaT() {
	
}

DTRealizaT::~DTRealizaT() {
	
}

DTRealizaT::DTRealizaT(string nombreEjercicio,string descEjercicio, string FraseATraducir):DTRealizaEjercicio( nombreEjercicio, descEjercicio) {
	this->FraseATraducir = FraseATraducir;
}
