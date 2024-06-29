/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   DTTraduccion.h
 * Author: matia
 *
 * Created on 13 de junio de 2024, 12:35 p. m.
 */

#ifndef DTTRADUCCION_H
#define DTTRADUCCION_H

#include "DTEjercicio.h"
#include <string>
using namespace std;

class DTTraduccion: public DTEjercicio {
private:
    string fraseATraducir;
    string fraseSolucion;
public:
    DTTraduccion();
    DTTraduccion(string tipoEjercicio, string nombreEjercicio, string descEjercicio, string fraseATraducir, string fraseSolucion);
    virtual ~DTTraduccion();

    string getFraseATraducir();
    string getFraseSolucion();
};

#endif /* DTTRADUCCION_H */

