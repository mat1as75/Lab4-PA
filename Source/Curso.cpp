/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Curso.h"

Curso::Curso() {
}

Curso::~Curso() {
}

Curso::Curso(string nombreCurso, string descrpicionCurso, Dificultad dificultad) {
	this->nombreCurso = nombreCurso;
	this->descrpicionCurso = descrpicionCurso;
	this->dificultad = dificultad;
}

string Curso::getNombreCurso() {
	return this->nombreCurso;
}

string Curso::getDificultad() {
	string Dificultad;
	
	if (this->dificultad == Principiante)
		Dificultad = "Principiante";
	else
		if (this->dificultad == Medio)
			Dificultad = "Medio";
		else
			if (this->dificultad == Avanzado)
				Dificultad = "Avanzado";
	
	return Dificultad;
}
