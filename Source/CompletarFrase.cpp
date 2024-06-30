#include "../Header/CompletarFrase.h"
#include "../DataTypes/DTEjercicio.h"
#include <string.h>
#include "String.h"


CompletarFrase::CompletarFrase() {
    
}

CompletarFrase::~CompletarFrase() {
    
}

CompletarFrase::CompletarFrase(DTEjercicio* DTEj) {
    this->nombreEjercicio = DTEj->getNombreEjercicio();
    this->descripcionEjercicio = DTEj->getDescEjercicio();
    this->fraseIncompleta = DTEj->getFraseIncompleta();
    this->palabrasSolucion = DTEj->getPalabrasSolucion();
}

CompletarFrase::CompletarFrase(string nombreEjercicio, string descEjercicio, string fraseIncompleta, vector<string> palabrasSolucion) {
    this->nombreEjercicio = nombreEjercicio;
    this->descripcionEjercicio = descEjercicio;
    this->fraseIncompleta = fraseIncompleta;
    this->palabrasSolucion = palabrasSolucion;
}

string CompletarFrase::getFraseIncompleta() {
    return this->fraseIncompleta;
}

vector<string> CompletarFrase::getPalabrasSolucion() {
    return this->palabrasSolucion;
}
string CompletarFrase::getSolucion(){
	string solucionConCat;
	for(int i=0; i< (int)this->palabrasSolucion.size(); i++){
		if(i==0){
			solucionConCat = solucionConCat + palabrasSolucion[i];
		}else{
			solucionConCat = solucionConCat + "-" + palabrasSolucion[i];
		}
	}
	return solucionConCat;
}


