/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Ejercicio.h
 * Author: matia
 *
 * Created on 22 de mayo de 2024, 6:17 p.m.
 */

#ifndef EJERCICIO_H
#define EJERCICIO_H

#include <string>
#include <vector>
#include "../DataTypes/DTEjercicio.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "../DataTypes/DTRealizaEjercicio.h"
#include "../Header/Inscripcion.h"
using namespace std;

class Ejercicio: public ICollectible {
protected:
  string nombreEjercicio;
  string descripcionEjercicio;
  string tipoEjercicio;
public:
  Ejercicio();
  ~Ejercicio();
  Ejercicio(string nombreEjercicio, string descripcionEjercicio);
  /*Operaciones de Consultar curso*/
  DTEjercicio* getInfo();
  /*Operaciones de realizar ejercicio*/
  DTRealizaEjercicio* getRealizaEjercicio();
  void apruebaEjercicio(Inscripcion* ins);
  virtual string getSolucion()= 0;
  string getNombreEjercicio();
  string getDescEjercicio();
  string getTipo();
};

#endif /* EJERCICIO_H */

