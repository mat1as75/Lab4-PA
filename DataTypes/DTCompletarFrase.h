/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   DTCompletarFrase.h
 * Author: matia
 *
 * Created on 13 de junio de 2024, 12:33 p. m.
 */

#ifndef DTCOMPLETARFRASE_H
#define DTCOMPLETARFRASE_H

#include "DTEjercicio.h"
#include <string>
#include <vector>
using namespace std;

class DTCompletarFrase: public DTEjercicio {
private:
    string fraseIncompleta;
    vector<string> palabrasSolucion;
public:
    DTCompletarFrase();
    DTCompletarFrase(string tipoEjercicio, string nombre, string descripcion, string fraseIncompleta, vector<string> palabrasSolucion);
    virtual ~DTCompletarFrase();

    string getFraseIncompleta();
    vector<string> getPalabrasSolucion();
};

#endif /* DTCOMPLETARFRASE_H */

