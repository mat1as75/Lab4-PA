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
#include "../ICollection/interfaces/ICollectible.h"
#include "DataTypes/DTProgresoCurso.h"

class Inscripcion: public ICollectible{
private:
    Date* fechaInscripcion;
    float progresoCurso;
    Estudiante* miEstudiante;
    Curso* miCurso;
public:
    string getNombreCurso();
    Inscripcion();
    Inscripcion(const Inscripcion& orig);
    virtual ~Inscripcion();
    ICollectible* getCurso();

    /* Operaciones de EliminarCurso */
    void EliminarCurso(Curso* c);
    
    DTProgresoCurso* getProgresoCurso();
	float obtenerProgreso();
};

#endif /* INSCRIPCION_H */

