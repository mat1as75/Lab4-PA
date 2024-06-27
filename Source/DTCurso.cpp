#include "DTCURSO.h"
#include "OrderedDictionary.h"
#include "Idioma.h"

DTCurso::DTCurso() {
	
}

DTCurso::DTCurso(string nombreCurso,string nombreProfesor,string descripcionCurso,string nombreIdioma, Dificultad dificultad, int cantLecciones, int cantEjercicios){
	this->nombreCurso=nombreCurso;
	this->nombreProfesor= nombreProfesor;
	this->descripcionCurso=descripcionCurso;
	this->nombreIdioma=nombreIdioma;
	this->dificultad=dificultad;
	this->cantLecciones= cantLecciones;
	this->cantEjercicios= cantEjercicios;
}
DTCurso::~DTCurso() {
	
}
