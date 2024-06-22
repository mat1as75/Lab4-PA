/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Usuario.h"

Usuario::Usuario() {
}

Usuario::~Usuario() {
}

Usuario::Usuario(string nickname, string password, string nombreUsuario, string descripcionUsuario) {
	this->nickname = nickname;
	this->password = password;
	this->nombreUsuario = nombreUsuario;
	this->descripcionUsuario = descripcionUsuario;
}

string Usuario::getNickname() {
	return this->nickname;
}

string Usuario::getNombreU() {
	return this->nombreUsuario;
}

string Usuario::getDescripcionU() {
	return this->descripcionUsuario;
}

