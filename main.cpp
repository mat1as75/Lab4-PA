/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: matia
 *
 * Created on 22 de mayo de 2024, 4:21 p.m.
 */

#include <iostream>
#include <string>
#include <vector>
#include "ICo.h"
#include "Header/Fabrica.h"
#include "Header/IControlador.h"
#include "Header/Usuario.h"
#include "Header/Estudiante.h"
#include "Header/Profesor.h"
#include "Header/Idioma.h"
#include "Header/Date.h"
using namespace std;

int main () {
	
    /*Date* date1 = new Date(28, 07, 2002);
    Estudiante* e1 = new Estudiante("mat1", "matias702", "Matias Alfaro", "Buen estudiante", "Uruguay", date1);
    Profesor* p1 = new Profesor("gualbi", "gualbi123", "Gualberto Hernandez", "Buen profesor", "UTEC");
	
    cout << e1->toString() << endl;
    cout << p1->toString() << endl;*/
    
    //Fabrica* fb = new Fabrica();
    //IControlador* controller = fb->getControlador();
    
    cout << "Hello, I'm Matias!" << endl;
    //Collectible* e1 = new Estudiante();
        
    return 0;
}

/*int opcion = 0;
    
    do {
        cout << "Bienvenido al sistema" << "\n\n";
        cout << "1. Ingresar Usuario" << endl;
        cout << "2. Ingresar Curso" << endl;
        cout << "3. Salir" << "\n\n";
        cout << "Digite opcion: ";
        cin >> opcion;
        cin.ignore();
        
        system("clear");
        //cout << "\033[2J\033[1;1H"; // Limpiar pantalla
        
        switch(opcion) {
            case 1:
                
                controller->AltaUsuario();
                
                break;
            case 2:
                
                
                break;
            case 3:
                cout << "Gracias por usar nuestro sistema" << endl;
                break;
            default:
                cout << "Digite una opcion valida" << endl;
                
        }
    }while(opcion != 3); */