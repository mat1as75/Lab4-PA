#include "../DataTypes/DTInfoCurso.h"

DTInfoCurso::DTInfoCurso() {
	
}

DTInfoCurso::~DTInfoCurso() {
	
}

DTInfoCurso::DTInfoCurso(string nombreCurso,string descripcionCurso,Dificultad dificultad,string idiomaCurso,string nombreProfesor,vector<DTLeccion*>listaLecciones,vector<DTInscripcion*> listaInscripciones){
	this->nombreCurso=nombreCurso;
	this->descripcion=descripcionCurso;
	this->dificultad=dificultad;
	this->nombreIdioma=idiomaCurso;
	this->nombreProfesor=nombreProfesor;
	this->lecciones=listaLecciones;
	this->inscripciones=listaInscripciones;
}


vector<DTLeccion*> DTInfoCurso::getDTLecciones(){
	return this->lecciones;
}
vector<DTInscripcion*> DTInfoCurso::getDTInscripciones(){
	return this->inscripciones;
}

string DTInfoCurso::getNombreCurso(){
	return this->nombreCurso;
}

string DTInfoCurso::getDescripcion(){
	return this->descripcion;
}
string DTInfoCurso:: getDificultad(){
	switch (this->dificultad) {
	case Principiante:
		return "Principiante";
		break;
	case Medio:
		return "Medio";
		break;
	case Avanzado:
		return "Avanzado";
			break;
	default:
		return "desconocido";
	}
}
string DTInfoCurso::getNombreIdioma(){
	return this->nombreIdioma;
	
}
string DTInfoCurso::getNombreProfesor(){
	return this->nombreProfesor;
}
string DTInfoCurso::getHabilitado(){
	if(this->habilitado==true){
		return "Curso: Habilitado \n";
	}else{
		return "Curso: No Habilitado \n";
	}
}
