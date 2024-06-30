#include "../Header/Traduccion.h"
#include "../DataTypes/DTEjercicio.h"

Traduccion::Traduccion() {
    
}

Traduccion::~Traduccion() { 
      
}

Traduccion::Traduccion(DTEjercicio* DTEj) {
    this->nombreEjercicio = DTEj->getNombreEjercicio();
    this->descripcionEjercicio = DTEj->getDescEjercicio();
    this->fraseATraducir = DTEj->getFraseATraducir();
    this->fraseSolucion = DTEj->getFraseSolucion();
}

Traduccion::Traduccion(string nombreEjercicio, string descEjercicio, string fraseATraducir, string fraseSolucion) {
    this->nombreEjercicio = nombreEjercicio;
    this->descripcionEjercicio = descEjercicio;
    this->fraseATraducir = fraseATraducir;
    this->fraseSolucion = fraseSolucion;
}

string Traduccion::getFraseATraducir() {
    return this->fraseATraducir;
}

string Traduccion::getFraseSolucion() {
    return this->fraseSolucion;
}
string Traduccion::getSolucion(){
	return this->fraseSolucion;
}
