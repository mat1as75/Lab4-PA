/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Estudiante.h"
#include "DataTypes/DTProgresoCurso.h"

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
