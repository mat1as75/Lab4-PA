#include "../DataTypes/DTCurso.h"
#include "OrderedDictionary.h"
#include "Idioma.h"

DTCurso::DTCurso() {
	
}

DTCurso::DTCurso(string nombreCurso,string nombreProfesor,string descripcionCurso,string nombreIdioma, Dificultad dificultad, int cantLecciones, int cantEjercicios){
	this->nombreCurso=nombreCurso;
	this->nombreProfesor= nombreProfesor;
	this->descCurso=descripcionCurso;
	this->nombreIdioma=nombreIdioma;
	this->dificultad=(Dificultad)dificultad;
	this->cantLecciones= cantLecciones;
	this->cantEjercicios= cantEjercicios;
}
DTCurso::~DTCurso() {
	
}

 DTCurso::DTCurso(string nombreCurso, string descCurso, Dificultad dif){
    this->nombreCurso = nombreCurso;
    this->descCurso = descCurso;
    this->dificultad = (Dificultad)dif;
 }

string DTCurso:: getNombreCurso(){
    return this->nombreCurso;
}
string DTCurso:: getDescCurso(){
       return this->descCurso;
}
Dificultad DTCurso:: getDificultad(){
    return this->dificultad;
}