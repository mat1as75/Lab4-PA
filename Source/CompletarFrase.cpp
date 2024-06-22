#include "../Header/CompletarFrase.h"

CompletarFrase::CompletarFrase() {

}

CompletarFrase::~CompletarFrase() {

}

CompletarFrase::CompletarFrase(string nombreEjericio, string descripcionEjercicio, string fraseIncompleta, vector<string> palabrasSolucion) {
    this->nombreEjercicio = nombreEjericio;
    this->descripcionEjercicio = descripcionEjercicio;
    this->fraseIncompleta = fraseIncompleta;
    this->palabrasSolucion = palabrasSolucion;
}



