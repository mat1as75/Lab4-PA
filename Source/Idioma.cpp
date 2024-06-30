/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "../Header/Idioma.h"

Idioma::Idioma() {
}

Idioma::~Idioma() {
}

Idioma::Idioma(string nombreIdioma) {
	this->nombreIdioma = nombreIdioma;
}

string Idioma::getNombreIdioma() {
	return this->nombreIdioma;
}
