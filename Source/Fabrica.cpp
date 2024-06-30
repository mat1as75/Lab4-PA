/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "../Header/Fabrica.h"

Fabrica::Fabrica() {
}

Fabrica::Fabrica(const Fabrica& orig) {
}

Fabrica::~Fabrica() {
}

IControlador* Fabrica::getControlador() {
    Controlador::getInstance();
}