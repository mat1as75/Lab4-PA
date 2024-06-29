#include "../Header/Ejercicio.h"

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