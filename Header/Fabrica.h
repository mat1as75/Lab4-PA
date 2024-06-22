/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Fabrica.h
 * Author: matia
 *
 * Created on 22 de mayo de 2024, 7:49 p.m.
 */

#ifndef FABRICA_H
#define FABRICA_H

#include "Controlador.h"
#include "IControlador.h"

class Fabrica {
public:
    Fabrica();
    Fabrica(const Fabrica& orig);
    virtual ~Fabrica();
    
    IControlador* getControlador();
private:
    
};

#endif /* FABRICA_H */

