#include "../Header/Ejercicio.h"
#include "../DataTypes/DTEjercicio.h"
#include "../DataTypes/DTRealizaEjercicio.h"
#include "../Header/Inscripcion.h"
#include "../DataTypes/DTRealizaCF.h"
#include "../Header/CompletarFrase.h"

Ejercicio::Ejercicio() {

}

Ejercicio::~Ejercicio() {

}

Ejercicio::Ejercicio(string nombreEjercicio, string descripcionEjercicio) {
    this->nombreEjercicio = nombreEjercicio;
    this->descripcionEjercicio = descripcionEjercicio;
}

string Ejercicio::getNombreEjercicio() {
    return this->nombreEjercicio;
}

string Ejercicio::getDescEjercicio() {
    return this->descripcionEjercicio;
}
DTEjercicio* Ejercicio::getInfo(){
	DTEjercicio* DTEjer= new DTEjercicio(this->nombreEjercicio,this->descripcionEjercicio);
	
	return DTEjer;
}

DTRealizaEjercicio* Ejercicio::getRealizaEjercicio(){
	DTRealizaEjercicio* DTEj;
	
	DTEj = this->getRealizaEjercicio();
	return DTEj;
}
void Ejercicio::apruebaEjercicio(Inscripcion* ins){
	ins->agregameComoAprobado(this);
}
string Ejercicio::getTipo(){
	return this->tipoEjercicio;
}