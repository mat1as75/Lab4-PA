/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Inscripcion.h
 * Author: matia
 *
 * Created on 15 de junio de 2024, 10:35 p. m.
 */

#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include <string>
#include <vector>
#include "Date.h"
#include "Estudiante.h"
class Estudiante;
#include "Curso.h"
class Curso;
#include "../ICollection/interfaces/ICollectible.h"
#include "DataTypes/DTProgresoCurso.h"
#include "DataTypes/DTInscripcion.h"
#include "DataTypes/DTRealizaEjercicio.h"
class DTRealizaEjercicio;
#include "Leccion.h"
class Leccion;
#include "Ejercicio.h"
class Ejercicio;


class Inscripcion: public ICollectible{
private:
    Date* fechaInscripcion;
    float progresoCurso;
    Estudiante* miEstudiante;
    Curso* miCurso;
    Leccion* leccionActual;
    IDictionary* ejerciciosAprobados;
public:
    string getNombreCurso();
    Inscripcion();
    Inscripcion(const Inscripcion& orig);
    Inscripcion(Date* fechaInsc, Curso* curso, Leccion* leccion);
    virtual ~Inscripcion();
    ICollectible* getCurso();

    /* Operaciones de EliminarCurso */
    void EliminarCurso(Curso* c);
    
    DTProgresoCurso* getProgresoCurso();
	float obtenerProgreso();

    /*Operaciones de Conultar Curso*/
    DTInscripcion* getInfo();

    /*Operaciones de inscribirse a curso*/
    void cursoAgregaInscripcion();
    string getNombreCurso();

    /*Operaciones de Realizar Ejercicio*/
    vector<DTRealizaEjercicio*> obtenerEjercicios();
    vector<string> obtenerSolucion(string ejARealizar );
	void agregarEjercicioAprobado(string nomEjercicio);
	void agregameComoAprobado(Ejercicio* ej);

};

#endif /* INSCRIPCION_H */

