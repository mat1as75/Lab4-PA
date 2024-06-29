#include "../DataTypes/DTCompletarFrase.h"

DTCompletarFrase::DTCompletarFrase() {
}

DTCompletarFrase::DTCompletarFrase(string tipoEjercicio, string nombre, string descripcion, string fraseIncompleta, vector<string> palabrasSolucion) {
    this->tipoEjercicio = tipoEjercicio;
    this->nombreEjercicio = nombre;
    this->descEjercicio = descripcion;
    this->fraseIncompleta = fraseIncompleta;
    this->palabrasSolucion = palabrasSolucion;
}

DTCompletarFrase::~DTCompletarFrase() {
}

string DTCompletarFrase::getFraseIncompleta() {
    return this->fraseIncompleta;
}

vector<string> DTCompletarFrase::getPalabrasSolucion() {
    return this->palabrasSolucion;
}