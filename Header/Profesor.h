/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Profesor.h
 * Author: matia
 *
 * Created on 22 de mayo de 2024, 5:39 p.m.
 */

#ifndef PROFESOR_H
#define PROFESOR_H

#include "Usuario.h" /* Dependencia en Diagrama de Clases */
#include "Curso.h" /* Dependencia en Diagrama de Clases */
#include "Idioma.h" /* Dependencia en Diagrama de Clases */
#include "../DataTypes/DTUsuario.h"
#include "../DataTypes/DTProgresoCurso.h"
#include "../ICollection/interfaces/IDictionary.h"

using namespace std;

class Profesor: public Usuario {
private:
	string instituto;
	IDictionary* idiomasEspecializado; /* Lista de idiomas en los que se especializa el profesor */
	ICollection* misCursos;
public:
	Profesor();
	~Profesor();
	Profesor(string nickname, string password, string nombreUsuario, string descripcionUsuario, string instituto);
	string getInstituto();
	string toString() override;
	IDictionary* getIdiomasEspecializado();
	void setIdiomasEspecializado(IKey* key, ICollectible* collect);
	void setIdiomasEspecializado(IDictionary* idiomas);
	DTUsuario* getInfo();
	vector<DTProgresoCurso*> obtenerEstadisticasCursos();

	//Curso* proponerCurso(string nombreCurso, string descripcionCurso, Dificultad dificultad /* Agregar lista de Cursos Previos */);

	/* Opearaciones de EliminarCurso */
	void EliminarCurso(Curso* c);
    
};

#endif /* PROFESOR_H */

