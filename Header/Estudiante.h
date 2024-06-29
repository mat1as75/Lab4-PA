/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Estudiante.h
 * Author: matia
 *
 * Created on 22 de mayo de 2024, 5:38 p.m.
 */


#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Usuario.h"
#include "Curso.h" /* Dependencia en Diagrama de Clases */
#include "Inscripcion.h" /* Dependencia en Diagrama de Clases */
#include "Date.h"
#include "../ICo.h"
#include "Inscripcion.h"
#include "DataTypes/DTProgresoCurso.h"
using namespace std;

class Estudiante: public Usuario{
protected:
	string paisRes;
	Date* fecnac;
	ICollection* misInscripciones;
public:
	Estudiante();
	~Estudiante();
	Estudiante(string nickname, string password, string nombreUsuario, string descripcionUsuario, string paisRes, Date* fecnac);
	string getPaisRes();
	string getFecnac();
	string toString() override;

	/* Operaciones de EliminarCurso */
	void EliminarCurso(Curso* c, Inscripcion* i);

	vector<DTProgresoCurso*> obtenerProgreso();

};

#endif /* ESTUDIANTE_H */

