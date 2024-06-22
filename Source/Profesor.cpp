/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Profesor.h"

Profesor::Profesor(){
}

Profesor::~Profesor() {
}

Profesor::Profesor(string nickname, string password, string nombreUsuario, string descripcionUsuario, string instituto) {
	this->nickname = nickname;
	this->password = password;
	this->nombreUsuario = nombreUsuario;
	this->descripcionUsuario = descripcionUsuario;
	this->instituto = instituto;
}

string Profesor::getInstituto() {
	return this->instituto;
}

string Profesor::toString() {
	return "Profesor: " + this->nickname + ", " + this->nombreUsuario  + ", " + this->instituto;
}
