/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Idioma.h
 * Author: matia
 *
 * Created on 22 de mayo de 2024, 6:17 p.m.
 */

#ifndef IDIOMA_H
#define IDIOMA_H

#include <string>
#include <vector>
using namespace std;

class Idioma {
private:
	string nombreIdioma;
public:
	Idioma();
	~Idioma();
	Idioma(string nombreIdioma);
	string getNombreIdioma();
};

#endif /* IDIOMA_H */

