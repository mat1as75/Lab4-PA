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
using namespace std;

class DTEjercicio {
protected:
    string nombreEjercicio;
    string descEjercicio;
public:
    DTEjercicio();
    DTEjercicio(const DTEjercicio& orig);
    virtual ~DTEjercicio();
};

#endif /* DTEJERCICIO_H */

