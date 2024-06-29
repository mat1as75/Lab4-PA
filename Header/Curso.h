/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Curso.h
 * Author: matia
 *
 * Created on 22 de mayo de 2024, 5:39 p.m.
 */

#ifndef CURSO_H
#define CURSO_H

#include <string>
#include <vector>
#include "Idioma.h" /* Dependencia en Diagrama de Clases */
#include "Profesor.h"
class Profesor;
#include "Inscripcion.h"
class Inscripcion;
#include "Leccion.h" /* Dependencia en Diagrama de Clases */
#include "DTLeccion.h"
#include "../ICo.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IDictionary.h"
#include "Profesor.h"
#include "../DataTypes/DTCompletarFrase.h"
#include "../DataTypes/DTTraduccion.h"
using namespace std;

enum Dificultad {
	Principiante,
	Medio,
	Avanzado
};

class Curso: public ICollectible {
private:
	string nombreCurso;
	string descrpicionCurso;
	Dificultad dificultad;
	Profesor* profeCurso;
	Idioma* idiomaCurso; /* Idioma que se ensena en el Curso */
	IDictionary* cursosPrevios; /* Lista de cursos previos */
	IDictionary* soyPrevioDe; /* Coleccion de cursos de los que soy previo */
	IDictionary* misLecciones; /* Lista de lecciones */
	IDictionary* misInscripciones; /* Coleccion de inscripciones */
public:
	Curso();
	~Curso();
	Curso(string nombreCurso, string descrpicionCurso, Dificultad dificultad);
	string getNombreCurso();
	string getDificultad();

	void agregateProfesor(Profesor* profDeCurso);
	void agregateIdioma(Idioma* idiomaDeCurso);
	void agregateCursoPrevio(IKey* nombreCPrev, Curso* cPrev);

	/* Operaciones de AltaLeccion */
	void AgregateLeccion(DTLeccion* DTLec);
	void AgregateEjercicio(IDictionary* DTEjercicios);

	/* Operaciones de EliminarCurso */
    void EliminarProfesor();
    void EliminarInscripciones();
    void EliminarCursoPrevio(Curso* c);

	DTProgresoCurso* obtenerEstadisticasCursos();

};

#endif /* CURSO_H */
