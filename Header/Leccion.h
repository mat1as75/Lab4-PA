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
#include "CompletarFrase.h"
#include "Traduccion.h"
#include "../ICollection/interfaces/ICollection.h"
#include "../DataTypes/DTEjercicio.h"
#include "../DataTypes/DTCompletarFrase.h"
#include "../DataTypes/DTTraduccion.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "../DataTypes/DTLeccion.h"
#include "Inscripcion.h"
class Inscripcion;
#include "../DataTypes/DTRealizaEjercicio.h"


using namespace std;

class Leccion: public ICollectible {
private:
  string tema;
  string objAprendizaje;
  IDictionary* misEjercicios; /* Lista de ejercicios */
public:
  Leccion();
  ~Leccion();
  Leccion(string tema, string objAprendizaje);
  string getTema();
  string getObjAprendizaje();

  /* Operacione de AltaLeccion */
  void AgregateEjercicio(DTEjercicio* ej);

  /* Operacions de EliminarCurso */
  void EliminarEjercicios();

  /*Operaciones de consultar curso*/
  DTLeccion* getInfo();

  /*Operaciones de inscribirse a curso*/
  int obtenerCantEjercicios();

  /*Operaciones de Realizar ejercicio*/
  void agregarEjercicioAprobado(string nomEjercicio, Inscripcion* ins);
  vector<DTRealizaEjercicio*> obtenerEjercicios(IDictionary* ejerciciosIns);
  vector<string> obtenerSolucion(string ejARealizar);

  


};

#endif /* LECCION_H */

