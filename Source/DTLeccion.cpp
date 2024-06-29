#include "../DataTypes/DTLeccion.h"

DTLeccion::DTLeccion() {
}

DTLeccion::DTLeccion(string tema, string objAprendizaje) {
    this->misEjercicios = new OrderedDictionary();
    this->tema = tema;
    this->objAprendizaje = objAprendizaje;
}

