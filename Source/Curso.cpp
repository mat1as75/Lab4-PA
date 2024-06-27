/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "../Header/Curso.h"
#include "../ICollection/interfaces/ICollectible.h"

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

/*Leccion* Curso::AgregateLeccion(DTLeccion* DTLec) {
	// 1.1 L := create () : LECCION
    ICollectible* Lec = new Leccion(DTLec->getTema(), DTLec->getObjAprendizaje());

	// 1.2 add(L)
    this->misLecciones->add(Lec);

	return (Leccion*)Lec;
}*/

void Curso::AgregateEjercicio(ICollection* DTEjercicios, Leccion* Leccion) {
	// [for all DATAEJERCICIO in set<DATAEJERCICIO>]
	// 2* AgregateEjercicio(DATAEJERCICIO)
	IIterator* iter = DTEjercicios->getIterator();

	while (iter->hasCurrent()) {
		// Convierto el ICollectible a DTEjercicio
		DTEjercicio* ej = (DTEjercicio*) iter->getCurrent();
		Leccion->AgregateEjercicio(ej);
		iter->next();
	}

}

void Curso::agregateCursoPrevio(IKey* nombreCPrev, Curso* cPrev){
	
	this->cursosPrevios->add(nombreCPrev ,cPrev);

}
void Curso::agregateIdioma(Idioma* idiomaDeCurso){
	this->idiomaCurso = idiomaDeCurso;
}

void Curso::agregateProfesor(Profesor* profDeCurso){
	this->profeCurso = profDeCurso;
	
}