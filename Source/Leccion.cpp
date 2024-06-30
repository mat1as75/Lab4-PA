#include "../Header/Leccion.h"

Leccion::Leccion() {

}
Leccion::~Leccion() {

}
Leccion::Leccion(string tema, string objAprendizaje) {
    this->tema = tema;
    this->objAprendizaje = objAprendizaje;
}

string Leccion::getTema() {
    return this->tema;
}

string Leccion::getObjAprendizaje() {
    return this->objAprendizaje;
}

void Leccion::AgregateEjercicio(DTEjercicio* ej) {
    
    DTCompletarFrase* DTEjer = (DTCompletarFrase*) ej;
    Ejercicio* Ejer;
    if(DTEjer->getTipoEjercicio().compare("CF") == 0)  /* Es DTCompletarFrase */
        Ejer = new CompletarFrase(ej);
    else /* Es DTTraduccion */
        Ejer = new Traduccion(ej);
    
    this->misEjercicios->add((ICollectible*) Ejer);
}

void Leccion::EliminarEjercicios() {
    
    /* 4.5*.1* [for each] E := next() */
    IIterator* iter = this->misEjercicios->getIterator();
    while(iter->hasCurrent()) {
        Ejercicio* c = (Ejercicio*) iter->getCurrent();
        delete(c); /* 4.5*.2* destroy(e) */
        iter->next();
    }
}