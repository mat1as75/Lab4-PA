#include "../DataTypes/DTTraduccion.h"

DTTraduccion::DTTraduccion() {
}

DTTraduccion::DTTraduccion(string tipoEjercicio, string nombre, string descripcion, string fraseATraducir, string fraseSolucion) {
    this->tipoEjercicio = tipoEjercicio;
    this->nombreEjercicio = nombre;
    this->descEjercicio = descripcion;
    this->fraseATraducir = fraseATraducir;
    this->fraseSolucion = fraseSolucion;
}

DTTraduccion::~DTTraduccion() {
}

string DTTraduccion::getFraseATraducir() {
    return this->fraseATraducir;
}

string DTTraduccion::getFraseSolucion() {
    return this->fraseSolucion;
}