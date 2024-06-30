#include "../Header/Leccion.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "../DataTypes/DTLeccion.h"
#include <vector>
#include "../DataTypes/DTRealizaEjercicio.h"
#include "../Header/Inscripcion.h"
#include "String.h"


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
    
    const char* nomEj = (Ejer->getNombreEjercicio()).c_str();
    IKey* key = new String(nomEj);
    this->misEjercicios->add(key, Ejer);
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

DTLeccion* Leccion::getInfo(){
	vector<DTEjercicio*> listaEjercicios;
	IIterator* it=this->misEjercicios->getIterator();
	while(it->hasCurrent()){
		DTEjercicio* ejer = (DTEjercicio*) it->getCurrent();
		listaEjercicios.push_back(ejer);
		it->next();
	}
	
	DTLeccion* dtLec= new DTLeccion(this->tema,this->objAprendizaje,listaEjercicios);
	return dtLec;
}
int Leccion::obtenerCantEjercicios(){
	return this->misEjercicios->getSize();
}

vector<DTRealizaEjercicio*> Leccion::obtenerEjercicios(IDictionary* ejerciciosIns){
	vector<DTRealizaEjercicio*> ejercicios;
	IIterator* iter = this->misEjercicios->getIterator();
	while(iter->hasCurrent()){
		Ejercicio* ej = (Ejercicio*)iter->getCurrent();
		const char* nomEj=(ej->getNombreEjercicio()).c_str();
		IKey* key = new String(nomEj);
		bool aprobado = ejerciciosIns->member(key);
		if(!aprobado){
			ejercicios.push_back(ej->getRealizaEjercicio());
		}
		iter->next();
	}
	return ejercicios;
}
vector<string>Leccion::obtenerSolucion(string ejARealizar){
	vector<string> solucion;
	string tipoEj, solucionEj;
	IIterator* iter = this->misEjercicios->getIterator();
	while(iter->hasCurrent()){
		Ejercicio* ej = (Ejercicio*)iter->getCurrent();
		if(ej->getNombreEjercicio().compare(ejARealizar)==0){
			tipoEj = ej->getTipo();
			solucionEj = ej->getSolucion();
			solucion.push_back(tipoEj);
			solucion.push_back(solucionEj);
			break;
		}
		iter->next();
	}
	return solucion;
}
void Leccion::agregarEjercicioAprobado(string nomEjercicio, Inscripcion* ins){
	const char* nomE=nomEjercicio.c_str();
	IKey* key = new String(nomE);
	
	Ejercicio* ej = (Ejercicio*)this->misEjercicios->find(key);
	ej->apruebaEjercicio(ins);
}