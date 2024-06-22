/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Controlador.h
 * Author: matia
 *
 * Created on 22 de mayo de 2024, 7:28 p.m.
 */

#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <string>
#include <vector>
#include "IControlador.h"
#include "Curso.h" /* Dependencia en Diagrama de Clases */
#include "Usuario.h" /* Dependencia en Diagrama de Clases */
#include "Idioma.h" /* Dependencia en Diagrama de Clases */
#include "Date.h"
using namespace std;

class Controlador: public IControlador {
private:
    Controlador(); // 1 de Singleton
    static Controlador* miInstancia; // 2 de Singleton
    vector<Curso*> noHabilitados;
public:
    static Controlador* getInstance(); // 3 de Singleton
    virtual ~Controlador();
    
    Usuario* ingresarEstudiante(string nicknameEstudiante, string passEstudiante, string nombreEstudiante, string descEstudiante, string paisResEstudiante, Date* fecNacEstudiante) override;
    Usuario* ingresarProfesor(string nicknameProfesor, string passProfesor, string nombreProfesor, string descProfesor, string institutoProfesor) override;
    
    /* Recibe sets de Usuarios y hacer el alta 
        de dicho usuario en el sistema
            (haciendo los links)*/
    void AltaUsuario() override;
    
    vector<string> listarCursosNoHabilitados() override;
};

#endif /* CONTROLADOR_H */

