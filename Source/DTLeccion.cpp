#include "../DataTypes/DTLeccion.h"

DTLeccion::DTLeccion() {
}

DTLeccion::DTLeccion(string tema, string objAprendizaje) {
    this->tema = tema;
    this->objAprendizaje = objAprendizaje;
}

vector<DTEjercicio*> DTLeccion::getMisEjercicios() {
    return this->misEjercicios;
}