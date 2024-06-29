#include "DTProfesor.h"
#include "OrderedDictionary.h"
#include "Idioma.h"
DTProfesor::DTProfesor() {
	
}



DTProfesor::DTProfesor(string nombre, string descripcion,string instituto, IDictionary* idiomasEspecializado): DTUsuario(nombre,descripcion){
	this->idiomasEspecializado=new OrderedDictionary();
	this->instituto=instituto;
	this->idiomasEspecializado=idiomasEspecializado;
}

DTProfesor::~DTProfesor() {
	
}

string DTProfesor::toString() {
	string retorno= "Profesor: \n Nombre: " + this->nombre + "\n " + "Descripcion: "+ this->descripcion  + "\n " +"Instituto: " +this->instituto + "\n Idiomas Especializados :  ";
	IIterator* it=this->idiomasEspecializado->getIterator();
	while(it->hasCurrent()){
		Idioma* idioma = (Idioma*) it->getCurrent();
		retorno= retorno + idioma->getNombreIdioma() + ", ";
		it->next();
	}
	retorno=retorno+"\n";
	return retorno;
}
