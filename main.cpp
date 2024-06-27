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
#include <ostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <vector>
#include "ICo.h"
#include "Header/Fabrica.h"
#include "Header/IControlador.h"
#include "Header/Usuario.h"
#include "Header/Estudiante.h"
#include "Header/Profesor.h"
#include "Header/Idioma.h"
#include "Header/Date.h"
#include "Header/Curso.h"
#include "ICollection/String.h"
#include "DataTypes/DTUsuario.h"
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
        
    int main (int argc, char *argv[]) {
	
	
	Fabrica* fb = new Fabrica();
	IControlador* con = fb->getControlador();
	//Date* date1 = new Date(28, 07, 2002);

	
	int opcion=0;
	
	do{
		cout<<"       MENU    "<<endl;
		cout<<" 1.Alta Usuario \n 2.Consultar Usuario \n 3.Alta Idioma \n 4.Consultar Idiomas \n 5.Alta Curso "<<endl;
		
		cin>>opcion;
		
		fflush(stdin);
		cout<<endl;
		
		switch(opcion){
		case 1:{
			
			int opcionUsuario=0;
			int opcionIdioma=0;
			cout<<"Seleccione uno por favor... \n 1.Estudiante \n 2.Profesor"<<endl;
			cin>>opcionUsuario;
			fflush(stdin);
			string nickname,contrasena,nombre,descripcion,paisRes,instituto;;
			Date* fecNac;
			int dia, mes, anio;
				
			if(opcionUsuario==1){
				
				
				
				cout<<"Ingrese Nickname: "<<endl;
				getline(cin,nickname);
				cout<<"Ingrese Contrasena: "<<endl;
				
				getline(cin,contrasena);
				cout<<"Ingrese Nombre: "<<endl;
				getline(cin,nombre);
				cout<<"Ingrese Descripcion: "<<endl;
				getline(cin,descripcion);
				cout<<"Ingrese Pais de Residencia: "<<endl;
				getline(cin,paisRes);
				cout<<"Ingrese Fecha de Nacimiento: "<<endl;
				scanf("%d/%d/%d", &dia, &mes, &anio);
				fecNac = new Date(dia, mes, anio);
				
				
				con->ingresarDatosEstudiante(nickname, contrasena, nombre,descripcion,paisRes,fecNac);
				if(con->altaUsuario()){
					cout<<"Usuario creado con exito"<<endl;
				}else{
					cout<<"Usuario no creado"<<endl;
				}
				
			}else{ // si no, eligio profesor 
				if(con->getIdiomas()->getSize() == 0) {
					cout << "error: No existe Idiomas en el Sistema" << endl;
				}else{
					
					cout<<"Ingrese Nickname: "<<endl;
					getline(cin,nickname);
					cout<<endl;
					
					do {
						cout<<"Ingrese Contrasena (al menos 6 caracteres): "<<endl;
						getline(cin,contrasena);
					} while(contrasena.length() < 6);
					cout<<"Ingrese Nombre: "<<endl;
					getline(cin,nombre);
					cout<<endl;
					cout<<"Ingrese Descripcion: "<<endl;
					getline(cin,descripcion);
					cout<<endl;
					cout<<"Ingrese Instituto: "<<endl;
					getline(cin,instituto);
					cout<<endl;
					
					vector<string> idiomas;   
					con->ingresarDatosProfesor(nickname, contrasena, nombre,descripcion,instituto);
					
					cout<<endl; 
					
					cout<<"Seleccione los idiomas en los cual se especializa: "<<endl;
					cout<<endl;
					idiomas=con->listarIdiomasDisponibles();
						
					for(int i=0; i<(int)idiomas.size();i++){
						cout<<idiomas[i] <<endl;
					}
					cout<<endl;
					
					cout<<"> ";
					string idiomaEsp;
					getline(cin,idiomaEsp);
					cout<<endl;
					
					const char* idioma = idiomaEsp.c_str();
					IKey* ik = new String(idioma);
					bool existeIdioma=con->getIdiomas()->member(ik);
					bool existeIdiomaEspecializado;
					/* Existe Idioma seleccionado en el sistema */
					if(existeIdioma ) {
						con->ingresarIdiomaEspecializado(idiomaEsp);
						while (opcionIdioma != 2 && (con->getIdiomasAuxiliares()->getSize() != con->getIdiomas()->getSize())) { // controla que el usuario no ingrese mas idiomas especializados de los que ya hay en el sistama
							// Tu código existente
							
							cout << "Desea agregar otro idioma? " << endl;
							cout << "1. SI\n2. NO" << endl;
							cout<<endl;
							cin >> opcionIdioma;
							cout<<endl;
							
							if (opcionIdioma == 1) {
								for(int i=0; i<(int)idiomas.size();i++){
									cout<<idiomas[i] <<endl;
								}
								
								fflush(stdin);
								cout<<endl;
								cout<<"Seleccione el idioma: "<<endl;
								cout<<"> ";
								getline(cin,idiomaEsp);
								idioma = idiomaEsp.c_str();
								ik = new String(idioma);
								existeIdioma=con->getIdiomas()->member(ik);
								existeIdiomaEspecializado=con->getIdiomasAuxiliares()->member(ik);
								if(existeIdioma and !existeIdiomaEspecializado) {
									con->ingresarIdiomaEspecializado(idiomaEsp);
								}else{
									
									if(existeIdiomaEspecializado){
										while(existeIdiomaEspecializado){
										cout<<"Ya selecciono este idioma, ingrese otro por favor: "<<endl<<endl;
										for(int i=0; i<(int)idiomas.size();i++){
											cout<<idiomas[i] <<endl;
										}
										cout<<endl;
										cout<<"> ";
										getline(cin,idiomaEsp);
										idioma = idiomaEsp.c_str();
										ik = new String(idioma);
										existeIdiomaEspecializado=con->getIdiomasAuxiliares()->member(ik);
										}
									}
									while(!existeIdioma){
										cout << "error: No existe Idioma en el Sistema, seleccione uno valido" << endl;
										getline(cin,idiomaEsp);
										idioma = idiomaEsp.c_str();
										ik = new String(idioma);
										existeIdioma=con->getIdiomas()->member(ik);
									}
									con->ingresarIdiomaEspecializado(idiomaEsp);
								}
							}
							
							cout << con->getIdiomasAuxiliares()->getSize() << "==" << con->getIdiomas()->getSize() << endl;
							cout << opcionIdioma << endl;
						}
					}else{
						do{
							cout << "error: No existe Idioma en el Sistema, ingrese uno valido: " << endl<<endl;
							for(int i=0; i<(int)idiomas.size();i++){
								cout<<idiomas[i] <<endl;
							}
							cout<<"> ";
							getline(cin,idiomaEsp);
							
							const char* idioma = idiomaEsp.c_str();
							IKey* ik = new String(idioma);
							 existeIdioma=con->getIdiomas()->member(ik);
							
						} while(existeIdioma!=true);
						con->ingresarIdiomaEspecializado(idiomaEsp);
						while (opcionIdioma != 2 && (con->getIdiomasAuxiliares()->getSize() != con->getIdiomas()->getSize())) { // controla que el usuario no ingrese mas idiomas especializados de los que ya hay en el sistama
							// Tu código existente
							
							cout << "Desea agregar otro idioma? " << endl;
							cout << "1. SI\n2. NO" << endl<<endl;
							cin >> opcionIdioma;
							
							
							if (opcionIdioma == 1) {
								for(int i=0; i<(int)idiomas.size();i++){
									cout<<idiomas[i] <<endl;
								}
								
								fflush(stdin);
								cout<<"Seleccione el idioma: "<<endl;
								cout<<"> ";
								getline(cin,idiomaEsp);
								idioma = idiomaEsp.c_str();
								ik = new String(idioma);
								existeIdioma=con->getIdiomas()->member(ik);
								existeIdiomaEspecializado=con->getIdiomasAuxiliares()->member(ik);
								if(existeIdioma and !existeIdiomaEspecializado) {
									con->ingresarIdiomaEspecializado(idiomaEsp);
								}else{
									if(existeIdiomaEspecializado){
										while(existeIdiomaEspecializado){
											cout<<"Ya selecciono este idioma, ingrese otro por favor: "<<endl<<endl;
											for(int i=0; i<(int)idiomas.size();i++){
												cout<<idiomas[i] <<endl;
											}
											cout<<endl;
											cout<<"> ";
											getline(cin,idiomaEsp);
											idioma = idiomaEsp.c_str();
											ik = new String(idioma);
											existeIdiomaEspecializado=con->getIdiomasAuxiliares()->member(ik);
										}
									}
									while(!existeIdioma){
										cout << "error: No existe Idioma en el Sistema, seleccione uno valido: " << endl<<endl;
										for(int i=0; i<(int)idiomas.size();i++){
											cout<<idiomas[i] <<endl;
										}
										cout<<"> ";
										getline(cin,idiomaEsp);
										idioma = idiomaEsp.c_str();
										ik = new String(idioma);
										existeIdiomaEspecializado=con->getIdiomasAuxiliares()->member(ik);
										existeIdioma=con->getIdiomas()->member(ik);
										
										if(existeIdiomaEspecializado){
											while(existeIdiomaEspecializado){
												cout<<"Ya selecciono este idioma, ingrese otro por favor: "<<endl<<endl;
												for(int i=0; i<(int)idiomas.size();i++){
													cout<<idiomas[i] <<endl;
												}
												cout<<endl;
												cout<<"> ";
												getline(cin,idiomaEsp);
												idioma = idiomaEsp.c_str();
												ik = new String(idioma);
												existeIdiomaEspecializado=con->getIdiomasAuxiliares()->member(ik);
											}
										}
										
									}
									con->ingresarIdiomaEspecializado(idiomaEsp);
								}
							}
							
							cout << con->getIdiomasAuxiliares()->getSize() << "==" << con->getIdiomas()->getSize() << endl;
							cout << opcionIdioma << endl;
						}
						
						
						
					}
					
					
					
					if(con->altaUsuario()){
						cout<<"Usuario creado con exito"<<endl;
					}else{
						cout<<"¡Este usuario ya existe en el sistema!"<<endl;
					}
				}
			}
			
			
			cout<<endl;
			break;
		}
		case 2:{
			string user;
			vector<string> usuarios=con->listarUsuarios();
			for (int i=0; i<(int)usuarios.size(); i++){
				cout<<usuarios[i]<<endl;
			}
			
			
			cout<<"Seleccione un usuario : "<<endl;
			getline(cin,user);
			
			const char* userChar=user.c_str();
			IKey* key= new String(userChar);
			
			if(con->getEstudiantes()->member(key)==false && con->getProfesores()->member(key)==false){
				cout<<endl;
				while(con->getEstudiantes()->member(key)==false && con->getProfesores()->member(key)==false ){
					
					cout<<"El usuario ingresado no existe, ingrese uno valido: "<<endl;
					cout<<endl;
					cout<<"Usuarios disponibles :"<<endl;
					
					cout<<endl;
					for (int i=0; i<(int)usuarios.size(); i++){
						cout<<usuarios[i]<<endl;
					}
					cout<<endl;
					cout<<"> ";
					getline(cin,user);
					userChar=user.c_str();
					key= new String(userChar);
					
				}
			}
			
			
			cout<<endl;
			DTUsuario* usuario=con->mostrarInfoUsuario(user);
			cout<<usuario->toString();
			cout<<endl<<endl;
			break;
			}
			
			
		case 3:{
			string idioma;
			cout<<"Ingrese Nombre Idioma: "<<endl;
			getline(cin,idioma);
				
			if(con->ingresarIdioma(idioma)){
				cout<<"Idioma creado con exito"<<endl;
			}else{
				cout<<"error: Idioma ya existe en el Sistema"<<endl;
			}
			cout<<endl<<endl;
			break;
			}
			
			
		case 4:{
			
			vector<string> idiomas;
			idiomas=con->listarIdiomasDisponibles();
			
			for(int i=0; i<(int)idiomas.size();i++){
				cout<<idiomas[i] <<endl;
			}
			break;
			}
		case 5:{
			
            string nombreCurso, nicknameProfe, descripcionCurso,nombreIdioma, nombreCursoPrev;
			char dificultad, op;
			vector<string> profesores;
			vector<string> idiomasEspProfesor;
			vector<string> cursosHab;
			profesores=con->listarProfesores();
				
			for(int i=0; i<profesores.size();i++){
				cout<<profesores[i] <<endl;
			}
			cout<<"Ingrese nombre del curso: "<<endl;
			getline(cin,nombreCurso);
			cout<<"Ingrese nick del profesor: "<<endl;
			getline(cin,nicknameProfe);
			cout<<"Ingsrese Decripcion: "<<endl;
			getline(cin,descripcionCurso);
			cout<<"Ingrese dificultad (Principiante(P)/Medio(M)/Avanzado(A): "<<endl;
			scanf("%c",&dificultad);
			while(dificultad != 'A' && dificultad != 'M' && dificultad != 'P'){
				cout<<"La dificultad ingresada no corresponde, por favor ingrese una de las siguiente opciones."<<endl;
				cout<<"Ingrese dificultad (Principiante(P)/Medio(M)/Avanzado(A): "<<endl;
				scanf("%c",&dificultad);
			};
			switch(dificultad){
			case 'A':{
				con->ingresarDatosCurso(nicknameProfe,nombreCurso,descripcionCurso,Avanzado);
				break;
			}
			case 'M':{
				con->ingresarDatosCurso(nicknameProfe,nombreCurso,descripcionCurso,Medio);
				break; 
			}
			case 'P':{
				con->ingresarDatosCurso(nicknameProfe,nombreCurso,descripcionCurso,Principiante);
				break;
			}
			}
			idiomasEspProfesor= con->listarIdiomasEspecializados;
			for(int i=0; i<idiomasEspProfesor.size();i++){
				cout<<idiomasEspProfesor[i] <<endl;
			}
			cout<<"Ingrese idioma: "<<endl;
			getline(cin,nombreIdioma);
			con->buscarIdioma(nombreIdioma);
			cout<<"Desea Ingresar Cursos Previos (S/N): "<<endl;
			scanf("%c",&op);
			if(op == 'S' or op == 's'){
				do{
					system("clear");
					cursosHab = con->listarCursosHabilitados();
					cout<<"Ingrese nombre del curso previo: "<<endl;
					getline(cin,nombreCursoPrev);
					con->buscarCursoPrevio(nombreCursoPrev);
					cout<<"Desea Ingresar otro Curso Previo (S/N): "<<endl;
					scanf("%c",&op);
					
					
				} while(op == 'S' or op == 's');
			}
			//AQUI VA LO REFERENCIADO EN AGREGAR LECCION/EJERCICIO!!!!!
			//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			
			if(con->AltaCurso()){
				cout<<"Curso creado con exito"<<endl;
			}else{
				cout<<"¡Este curso ya existe en el sistema!"<<endl;
			}
			
			





			break;
			};
		};
	} while(opcion!=6);
	
	
	
	














    return 0;
};

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