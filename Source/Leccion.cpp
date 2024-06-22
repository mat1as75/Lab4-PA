#include "../Header/Leccion.h"
#include "../ICollection/interfaces/ICollectible.h"

Leccion::Leccion() {

}
Leccion::~Leccion() {

}
Leccion::Leccion(string tema, string objAprendizaje) {
    this->tema = tema;
    this->objAprendizaje = objAprendizaje;
}

void Leccion::AgregateEjercicio(DTEjercicio* DTEjer) {
   
}
