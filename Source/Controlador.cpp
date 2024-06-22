/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include "Controlador.h"
#include "ICollection/Integer.h"
#include "ICollection/interfaces/IKey.h"
#include "Usuario.h"
#include "Curso.h"
using namespace std;

Controlador* Controlador::miInstancia = nullptr;

Controlador::Controlador() {
}

Controlador::~Controlador() {
}

Controlador* Controlador::getInstance() {
    if (Controlador::miInstancia == nullptr) {
        Controlador::miInstancia = new Controlador();
    }
    return (Controlador::miInstancia);
}

vector<string> Controlador::listarCursosNoHabilitados() {
    vector<string> nombresCursos;
	/* Recorro coleccion de cursos no habilitados */
    for(int i = 0; i < (int)noHabilitados.size(); i++) {
        nombresCursos.push_back(noHabilitados[i]->getNombreCurso());
    }
    return nombresCursos;
}

/* FALTA HACER LINKS Y PASAR SET DE USUARIO POR REFERENCIA
void Controlador::AltaUsuario() {
    // Atributos en comun entre Usuarios
    string nicknameUsuario, passUsuario, nombreUsuario, descUsuario;

    int opcionU;
    cout << "Alta de Usuario" << "\n\n";
    cout << "1. Ingresar Estudiante" << endl;
    cout << "2. Ingresar Profesor" << "\n\n";
    cout << "Digite opcion: ";
    cin >> opcionU;
    cin.ignore();

    system("clear");
    //cout << "\033[2J\033[1;1H"; // Limpiar pantalla

    // Ingresar Estudiante
    if (opcionU == 1) {
        string paisResEstudiante;
        Date* fecNacEstudiante;
        int dia, mes, anio;

        cout << "Datos Estudiante" << "\n\n";
        cout << "Ingrese nickname: ";
        getline(cin, nicknameUsuario);
        cout << "Ingrese contrasena: ";
        getline(cin, passUsuario);
        cout << "Ingrese nombre: ";
        getline(cin, nombreUsuario);
        cout << "Ingrese descripcion: ";
        getline(cin, descUsuario);
        cout << "Ingrese pais de residencia: ";
        getline(cin, paisResEstudiante);
        cout << "Ingrese fecha de nacimiento (dd/mm/aaaa): ";
        scanf("%d/%d/%d", &dia, &mes, &anio);

        fecNacEstudiante = new Date(dia, mes, anio);
        
        Usuario* estudiante = this->ingresarEstudiante(nicknameUsuario, passUsuario, nombreUsuario, descUsuario, paisResEstudiante, fecNacEstudiante);
        cout << estudiante->toString() << endl;
    } else {
        // Ingresar Profesor
        if (opcionU == 2) {
            string institutoProfesor;

            cout << "Datos Estudiante" << "\n\n";
            cout << "Ingrese nickname: ";
            getline(cin, nicknameUsuario);
            cout << "Ingrese contrasena: ";
            getline(cin, passUsuario);
            cout << "Ingrese nombre: ";
            getline(cin, nombreUsuario);
            cout << "Ingrese descripcion: ";
            getline(cin, descUsuario);
            cout << "Ingrese instituto: ";
            getline(cin, institutoProfesor);

            Usuario* profesor = this->ingresarProfesor(nicknameUsuario, passUsuario, nombreUsuario, descUsuario, institutoProfesor);
            cout << profesor->toString() << endl;
        }
    }
} */