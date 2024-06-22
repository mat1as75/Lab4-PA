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
//#include "Profesor.h" /* Dependencia en Diagrama de Clases */
//include "Inscripcion.h" /* Dependencia en Diagrama de Clases */
#include "Leccion.h" /* Dependencia en Diagrama de Clases */
#include "DTLeccion.h"
#include "../ICo.h"
#include "ICollection/interfaces/ICollectible.h"
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
	Idioma* idiomaCurso; /* Idioma que se ensena en el Curso */
	ICollection* cursosPrevios; /* Lista de cursos previos */
	ICollection* misLecciones; /* Lista de lecciones */
public:
	Curso();
	~Curso();
	Curso(string nombreCurso, string descrpicionCurso, Dificultad dificultad);
	string getNombreCurso();
	string getDificultad();
	Leccion* AgregateLeccion(DTLeccion* DTLec);
	void AgregateEjercicio(ICollection* DTEjercicios, Leccion* Leccion);
	/* Hacer Oper para obtener Cursos Previos */
};

#endif /* CURSO_H */
