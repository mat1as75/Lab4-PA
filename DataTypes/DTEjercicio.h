/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   DTEjercicio.h
 * Author: matia
 *
 * Created on 13 de junio de 2024, 12:31 p. m.
 */

#ifndef DTEJERCICIO_H
#define DTEJERCICIO_H

#include <string>
#include <vector>
#include "../ICo.h"
#include "../ICollection/interfaces/ICollectible.h"
using namespace std;

class DTEjercicio: public ICollectible{
protected:
    string tipoEjercicio;
    string nombreEjercicio;
    string descEjercicio;
public:
    DTEjercicio();
    DTEjercicio(string tipoEjercicio, string nombre, string descripcion);
    virtual ~DTEjercicio();

    string getTipoEjercicio();
    string getNombreEjercicio();
    string getDescEjercicio();

    virtual string getFraseIncompleta() = 0;
    virtual vector<string> getPalabrasSolucion() = 0;
    virtual string getFraseATraducir() = 0;
    virtual string getFraseSolucion() = 0;
};

#endif /* DTEJERCICIO_H */

