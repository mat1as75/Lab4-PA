/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   DTCurso.h
 * Author: matia
 *
 * Created on 13 de junio de 2024, 12:18 p. m.
 */

#ifndef DTCURSO_H
#define DTCURSO_H

#include <string>
#include "Header/Curso.h"
using namespace std;

class DTCurso {
private:
    string nombreCurso;
    string descCurso;
    string nombreProfesor;
    string nombreIdioma;
    Dificultad dificultad;
    int cantLecciones;
    int cantEjercicios;
public:
    DTCurso();
    DTCurso(string nombreCurso,string nombreProfesor,string descripcionCurso,string nombreIdioma, Dificultad dificultad, int cantLecciones, int cantEjercicios);
    virtual ~DTCurso(); 
};

#endif /* DTCURSO_H */

