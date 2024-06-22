/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Leccion.h
 * Author: matia
 *
 * Created on 22 de mayo de 2024, 6:16 p.m.
 */

#ifndef LECCION_H
#define LECCION_H

#include <string>
#include <vector>
#include "Ejercicio.h" /* Dependencia en Diagrama de Clases */
#include "DTEjercicio.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/ICollection.h"
using namespace std;

class Leccion: public ICollectible {
private:
  string tema;
  string objAprendizaje;
  ICollection* misEjercicios; /* Lista de ejercicios */
public:
  Leccion();
  ~Leccion();
  Leccion(string tema, string objAprendizaje);

  void AgregateEjercicio(DTEjercicio* DTEjer);
};

#endif /* LECCION_H */

