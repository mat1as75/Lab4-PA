/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */


#include "../Header/Estudiante.h"
#include "DataTypes/DTProgresoCurso.h"
#include "../DataTypes/DTEstudiante.h"
#include "String.h"
#include <ctime>
#include "../Header/Inscripcion.h"
class Inscripcion;
#include "../DataTypes/DTRealizaEjercicio.h"



Estudiante::Estudiante() {
}

Estudiante::~Estudiante() {
}

Estudiante::Estudiante(string nickname, string password, string nombreUsuario, string descripcionUsuario, string paisRes, Date* fecnac) {
	this->nickname = nickname;
	this->password = password;
	this->nombreUsuario = nombreUsuario;
	this->descripcionUsuario = descripcionUsuario;
	this->paisRes = paisRes;
	this->fecnac = fecnac;
}

string Estudiante::getPaisRes() {
	return this->paisRes;
}

string Estudiante::getFecnac() {
	return fecnac->toString();
}

string Estudiante::toString() {
	return "Estudiante: " + this->nickname + ", " + this->nombreUsuario  + ", " + this->paisRes + ", " + getFecnac();
}


void Estudiante::EliminarCurso(Curso* c, Inscripcion* i) {
    
    IIterator* iter = this->misInscripciones->getIterator();
    while(iter->hasCurrent()) {
        Inscripcion* i = (Inscripcion*) iter->getCurrent();
        /* 4.2*.1.1 member(c) */
        bool esMiembro = this->misInscripciones->member(i->getCurso());
        
        if(esMiembro) { /* [es Miembro] */
            this->misInscripciones->remove(i->getCurso()); /* 4.2*.1.2remove(c) */
            this->misInscripciones->remove(this); /* 4.2*1.3 remove(i) */
        }
        
        iter->next();
    }
}

vector<DTProgresoCurso*> Estudiante::obtenerProgreso(){
	vector<DTProgresoCurso*> DTProgresos;
	IIterator* it= this->misInscripciones->getIterator(); 
	while(it->hasCurrent()){ 
		DTProgresoCurso* DTProg;
		Inscripcion* aux=(Inscripcion*)it->getCurrent(); 
		DTProg = aux->getProgresoCurso();
		DTProgresos.push_back(DTProg);
		it->next();
	}
	return DTProgresos;
}


DTUsuario* Estudiante::getInfo(){
	DTUsuario* dataU= new DTEstudiante(this->getNombreU(),this->getDescripcionU(),this->getPaisRes());
	
	return dataU;
}

bool Estudiante::puedoCursar(vector<string> nomCursosP){
	bool puedo;
	
	for(int i=0; i<(int)nomCursosP.size();i++){
		const char* curso=nomCursosP[i].c_str();
		IKey* key = new String(curso);
		puedo = this->cursosAprobados->member(key);
		if(!puedo){
			return false;
			break;
		}
		
	}
	return true;
}

bool Estudiante::cursasteCurso(string nomC){
	const char* curso=nomC.c_str();
	IKey* key = new String(curso);
	return this->cursosAprobados->member(key);
}
void Estudiante::inscribirseACurso(Curso* curso){
	// Obtiene el tiempo actual
	time_t t = time(nullptr);
	
	// Convierte el tiempo a una estructura tm
	tm* now = localtime(&t);
	
	// Variables para almacenar el día, mes y año
	int dia = now->tm_mday;
	int mes = now->tm_mon + 1; // tm_mon está en el rango [0, 11]
	int anio = now->tm_year + 1900; // tm_year es el número de años desde 1900

	Date* fechaInsc = new Date(dia,mes,anio);
	Leccion* leccionInsc= curso->getUltimaLeccionACursar();
	Inscripcion* inscripcion = new Inscripcion(fechaInsc, curso, leccionInsc);
	inscripcion->cursoAgregaInscripcion();
	this->misInscripciones->add(inscripcion);
}
vector<string> Estudiante::obtenerCursos(){
	vector<string> nombresCursos;
	IIterator* iter = this->misInscripciones->getIterator();
	while(iter->hasCurrent()){
		Inscripcion* aux = (Inscripcion*)iter->getCurrent();
		nombresCursos.push_back(aux->getNombreCurso());
		iter->next();
	}
	return nombresCursos;
}

vector<DTRealizaEjercicio*> Estudiante::obtenerDTREjercicios(string curso){
	vector<DTRealizaEjercicio*> ejercicios;
	Inscripcion* aux;
	IIterator* iter = this->misInscripciones->getIterator();
	while(iter->hasCurrent()){
		aux = (Inscripcion*)iter->getCurrent();
		bool es = (curso.compare(aux->getNombreCurso())==0);
		if(!es){
			iter->next();
		}else{
			break;
		}
	}
	ejercicios = aux->obtenerEjercicios();
	return ejercicios;
	
}
vector<string> Estudiante::obtenerSolucion(string ejARealizar, string curso){
	vector<string> solucion;
	Inscripcion* aux;
	IIterator* iter = this->misInscripciones->getIterator();
	while(iter->hasCurrent()){
		aux = (Inscripcion*)iter->getCurrent();
		bool es = (curso.compare(aux->getNombreCurso())==0);
		if(!es){
			iter->next();
		}else{
			break;
		}
	}
	solucion = aux->obtenerSolucion(ejARealizar);
	return solucion;
}

void Estudiante::aprobasteEjercicio(string nomEjercicio, string nomCurso){
	Inscripcion* aux;
	IIterator* iter = this->misInscripciones->getIterator();
	while(iter->hasCurrent()){
		aux = (Inscripcion*)iter->getCurrent();
		bool es = (nomCurso.compare(aux->getNombreCurso())==0);
		if(!es){
			iter->next();
		}else{
			break;
		}
	}
	aux->agregarEjercicioAprobado(nomEjercicio);
	
}

