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
#include "Inscripcion.h"
#include "../DataTypes/DTProgresoCurso.h"
#include "../DataTypes/DTUsuario.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../DataTypes/DTRealizaEjercicio.h"
#include "../ICollection/interfaces/ICollection.h"
class DTRealizaEjercicio;
class Curso;


using namespace std;

class Estudiante: public Usuario{
private:
	string paisRes;
	Date* fecnac;
	ICollection* misInscripciones;
	IDictionary* cursosAprobados;
public:
	Estudiante();
	~Estudiante();
	Estudiante(string nickname, string password, string nombreUsuario, string descripcionUsuario, string paisRes, Date* fecnac);
	string getPaisRes();
	string getFecnac();
	string toString() override;
	DTUsuario* getInfo() override;
	/* Operaciones de EliminarCurso */
	void EliminarCurso(Curso* c, Inscripcion* i);

	/*Operaciones de consultar estadisticas*/
	vector<DTProgresoCurso*> obtenerProgreso();

	/*Operaciones de inscribirse a curso*/
	bool puedoCursar(vector<string> nomCursosP);
	bool cursasteCurso(string nomC);
	void inscribirseACurso(Curso* curso);

	/*Operaciones de Realizar ejercicio*/
	vector<string> obtenerCursos();
	vector<DTRealizaEjercicio*> obtenerDTREjercicios(string curso);
	vector<string> obtenerSolucion(string ejARealizar, string curso);
	void aprobasteEjercicio(string nomEjercicio, string nomCurso);
};

#endif /* ESTUDIANTE_H */

