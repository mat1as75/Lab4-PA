/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Date.h
 * Author: matia
 *
 * Created on 22 de mayo de 2024, 6:19 p.m.
 */

#ifndef DATE_H
#define DATE_H

#include <string>
#include <vector>
using namespace std;

class Date {
private:
	int dia;
	int mes;
	int anio;
public:
	Date();
	Date(int dia, int mes, int anio);
	int getDia();
	int getMes();
	int getAnio();
	string toString();
};

#endif /* DATE_H */

