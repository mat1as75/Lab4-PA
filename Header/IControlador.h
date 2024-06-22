/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   IControlador.h
 * Author: matia
 *
 * Created on 22 de mayo de 2024, 7:44 p.m.
 */

#ifndef ICONTROLADOR_H
#define ICONTROLADOR_H

#include <string>
#include <vector>
#include "Curso.h"
#include "Usuario.h"
#include "Profesor.h"
#include "Date.h"
using namespace std;

class IControlador {
private:
    
    
    
public:
    
    virtual void AltaUsuario() = 0;
    virtual Usuario* ingresarEstudiante(string nicknameEstudiante, string passEstudiante, string nombreEstudiante, string descEstudiante, string paisResEstudiante, Date* fecNacEstudiante) = 0;
    virtual Usuario* ingresarProfesor(string nicknameProfesor, string passProfesor, string nombreProfesor, string descProfesor, string institutoProfesor) = 0;
    virtual vector<string> listarCursosNoHabilitados() = 0;
};

#endif /* ICONTROLADOR_H */

