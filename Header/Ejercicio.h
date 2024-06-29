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
using namespace std;

class Ejercicio: public ICollectible {
protected:
  string nombreEjercicio;
  string descripcionEjercicio;
public:
  Ejercicio();
  ~Ejercicio();
  Ejercicio(string nombreEjercicio, string descripcionEjercicio);

  string getNombreEjercicio();
  string getDescEjercicio();
};

#endif /* EJERCICIO_H */

