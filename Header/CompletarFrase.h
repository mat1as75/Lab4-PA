/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   CompletarFrase.h
 * Author: matia
 *
 * Created on 22 de mayo de 2024, 6:18 p.m.
 */

#ifndef COMPLETARFRASE_H
#define COMPLETARFRASE_H

#include <Ejercicio.h>
using namespace std;

class CompletarFrase: public Ejercicio{
private:
  string fraseATraducir;
  string fraseSolucion;
public:
  CompletarFrase();
  ~CompletarFrase();
  CompletarFrase(string fraseATraducir, string fraseSolucion);
  string toString() override;
};

#endif /* COMPLETARFRASE_H */

