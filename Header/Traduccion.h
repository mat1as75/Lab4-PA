/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Traduccion.h
 * Author: matia
 *
 * Created on 22 de mayo de 2024, 6:18 p.m.
 */

#ifndef TRADUCCION_H
#define TRADUCCION_H

#include <Ejercicio.h>
using namespace std;

class EJERCICIO {
private:
  string nombreEjercicio;
  string descripcionEjercicio;
public:
  Ejercicio();
  ~Ejercicio();
  Ejercicio(string nombreEjercicio, string descripcionEjercicio);
  virtual string toString() = 0;
};

#endif /* TRADUCCION_H */

