/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   DTLeccion.h
 * Author: matia
 *
 * Created on 13 de junio de 2024, 12:28 p. m.
 */

#ifndef DTLECCION_H
#define DTLECCION_H

#include <string>
#include <vector>
#include "DTEjercicio.h"
using namespace std;

class DTLeccion {
private:
    string tema;
    string objAprendizaje;
    vector<DTEjercicio*> misEjercicios;
public:
    DTLeccion();
    DTLeccion(const DTLeccion& orig);
    virtual ~DTLeccion();
};

#endif /* DTLECCION_H */

