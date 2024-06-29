#include "../DataTypes/DTEjercicio.h"

DTEjercicio::DTEjercicio() {
}

DTEjercicio::DTEjercicio(string tipoEjercicio, string nombre, string descripcion) {
    this->tipoEjercicio = tipoEjercicio;
    this->nombreEjercicio = nombre;
    this->descEjercicio = descripcion;
}

DTEjercicio::~DTEjercicio() {
}

string DTEjercicio::getTipoEjercicio() {
    return this->tipoEjercicio;
}

string DTEjercicio::getNombreEjercicio() {
    return this->nombreEjercicio;
}

string DTEjercicio::getDescEjercicio() {
    return this->descEjercicio;
}