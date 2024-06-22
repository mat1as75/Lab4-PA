/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <string>
#include "Date.h"

Date::Date() {
}

Date::Date(int dia, int mes, int anio) {
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}

int Date::getDia() {
	return this->dia;
}

int Date::getMes() {
	return this->mes;
}

int Date::getAnio() {
	return this->anio;
}

string Date::toString() {
	return to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->anio);
}
