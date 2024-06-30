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

#include "Ejercicio.h"
using namespace std;

class Traduccion: public Ejercicio {
private:
  string fraseATraducir;
  string fraseSolucion;
public:
  Traduccion();
  ~Traduccion();
  Traduccion(DTEjercicio* DTEj);
  Traduccion(string nombreEjericio, string descripcionEjercicio, string fraseATraducir, string fraseSolucion);
  string getSolucion() override;
  string getFraseATraducir();
  string getFraseSolucion();
};

#endif /* TRADUCCION_H */

