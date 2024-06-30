/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Inscripcion.cpp
 * Author: matia
 * 
 * Created on 15 de junio de 2024, 10:35 p. m.
 */

#include "../Header/Inscripcion.h"
#include "../Header/Estudiante.h"
#include "../DataTypes/DTProgresoCurso.h"
#include "../DataTypes/DTRealizaEjercicio.h"
#include "../ICollection/String.h"

Inscripcion::Inscripcion() {
}

Inscripcion::Inscripcion(const Inscripcion& orig) {
}

Inscripcion::~Inscripcion() {
}

ICollectible* Inscripcion::getCurso() {
    return(ICollectible*) this->miCurso;
}

void Inscripcion::EliminarCurso(Curso* c) {
    /* 4.2*.1 eliminarCurso */
    this->miEstudiante->EliminarCurso(c, this);
}

string Inscripcion :: getNombreCurso() {
	return this->miCurso->getNombreCurso();
}

DTProgresoCurso* Inscripcion::getProgresoCurso(){
	string nombreCurso = this->getNombreCurso();
	DTProgresoCurso* DTProgreso = new DTProgresoCurso(nombreCurso,progresoCurso);
	return DTProgreso;
}

float Inscripcion:: obtenerProgreso(){
	return this->progresoCurso;
}



DTInscripcion* Inscripcion::getInfo(){
	DTInscripcion* dtInsc=new DTInscripcion(this->miEstudiante->getNombreU(),this->fechaInscripcion);
	return dtInsc;
}

void Inscripcion::cursoAgregaInscripcion(){
	this->miCurso->agregateInscripcion(this);
}

string Inscripcion::getNombreCurso(){
	return this->miCurso->getNombreCurso();
}
vector<DTRealizaEjercicio*> Inscripcion::obtenerEjercicios(){
	vector<DTRealizaEjercicio*> ejercicios;
	ejercicios = this->leccionActual->obtenerEjercicios(this->ejerciciosAprobados);
	return ejercicios;
	
}
vector<string> Inscripcion::obtenerSolucion(string ejARealizar){
	vector<string> solucion;
	solucion = this->leccionActual->obtenerSolucion( ejARealizar);
	return solucion;
}

void Inscripcion::agregarEjercicioAprobado(string nomEjercicio){
	this->leccionActual->agregarEjercicioAprobado(nomEjercicio, this);
}
void Inscripcion::agregameComoAprobado(Ejercicio* ej){
	const char* ejercicio=(ej->getNombreEjercicio()).c_str();
	IKey* key = new String(ejercicio);
	this->ejerciciosAprobados->add(key ,ej);
}