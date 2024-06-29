/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Inscripcion.cpp
 * Author: matia
 * 
 * Created on 15 de junio de 2024, 10:35 p. m.
 */

#include "../Header/Inscripcion.h"

Inscripcion::Inscripcion() {
}

Inscripcion::Inscripcion(const Inscripcion& orig) {
}

Inscripcion::~Inscripcion() {
}

ICollectible* Inscripcion::getCurso() {
    return(ICollectible*) this->miCurso;
}

void Inscripcion::EliminarCurso(Curso* c) {
    /* 4.2*.1 eliminarCurso */
    this->miEstudiante->EliminarCurso(c, this);
}