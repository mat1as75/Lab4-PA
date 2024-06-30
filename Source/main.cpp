#include <iostream>
#include <sstream>
//#include <ostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <vector>
#include "../Header/ICo.h"
#include "../Header/Fabrica.h"
#include "../Header/IControlador.h"
#include "../Header/Usuario.h"
#include "../Header/Estudiante.h"
#include "../Header/Profesor.h"
#include "../Header/Idioma.h"
#include "../Header/Date.h"
#include "../Header/Curso.h"
#include "../ICollection/String.h"
#include "../DataTypes/DTUsuario.h"
#include "../DataTypes/DTProgresoCurso.h"
using namespace std;

int main (int argc, char *argv[]) {
	
	Fabrica* fb = new Fabrica();
	IControlador* con = fb->getControlador();
	
	int opcion = 0;
	
	do{
		
		cout <<"       MENU    " << endl;
		cout <<" 1. Alta de Usuario" << endl;
		cout <<" 2. Consulta de usuario" << endl;
		cout <<" 3. Alta de Idioma" << endl;
		cout <<" 4. Consultar Idiomas" << endl;
		cout <<" 5. Alta de Curso" << endl;
		cout <<" 6. Agregar Leccion" << endl;
		cout <<" 7. Agregar Ejercicio" << endl;
		cout <<" 8. Habilitar Curso" << endl;
		cout <<" 9. Eliminar Curso" << endl;
		cout <<"10. Consultar Curso" << endl;
		cout <<"11. Inscribirse a Curso" << endl;
		cout <<"12. Realiar Ejercicio" << endl;
		cout <<"13. Consultar Estadisticas" << endl;
		cout <<"14. Salir" << "\n\n";
		cout <<"Digite opcion: ";
		cin >> opcion;
		
		switch(opcion) {
		case 1:{
			int opcionUsuario=0;
			int opcionIdioma=0;
			cout<<"Seleccione uno por favor... \n 1. Estudiante \n 2. Profesor"<<endl;
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
		};
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
		};
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
		};
		case 4:{
			vector<string> idiomas;
			idiomas=con->listarIdiomasDisponibles();
			
			for(int i=0; i<(int)idiomas.size();i++){
				cout<<idiomas[i] <<endl;
			}
			
			break;	
		};
		case 5:{
			string nombreCurso, nicknameProfe, descripcionCurso,nombreIdioma, nombreCursoPrev;
			char dificultad, op;
			vector<string> profesores;
			vector<string> idiomasEspProfesor;
			vector<string> cursosHab;
			profesores=con->listarProfesores();
			
			for(int i=0; i<(int)profesores.size();i++){
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
				con->ingresarDatosCurso(nicknameProfe,nombreCurso,descripcionCurso,(Dificultad)Avanzado);
				break;
			}
			case 'M':{
					con->ingresarDatosCurso(nicknameProfe,nombreCurso,descripcionCurso,(Dificultad)Medio);
					break; 
				}
			case 'P':{
						con->ingresarDatosCurso(nicknameProfe,nombreCurso,descripcionCurso,(Dificultad)Principiante);
						break;
					}
			}
			idiomasEspProfesor= con->listarIdiomasEspecializados();
			for(int i=0; (int)i<idiomasEspProfesor.size();i++){
				cout<<idiomasEspProfesor[i] <<endl;
			}
			cout<<"Ingrese idioma: "<<endl;
			fflush(stdin);
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
			//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!}
			
			string nombreCurso, temaLeccion, objAprendizajeLeccion, descEjercicio, fraseACompletar, palabrasSolucion, pal, fraseATraducir, fraseTraducida;
			vector<string> palabrasSol;
			int tipoEjercicio, cantComa;
			char op;
			
			cout << "Desea agregar lecciones? S/N";
			cin >> op;
			
			if(op == 'S') { /* INGRESO LECCION */
				
				do{
					cout << "Ingrese tema de la leccion: ";
					getline(cin, temaLeccion);
					
					cout << "Ingrese objetivo de aprendizaje de la leccion: ";
					getline(cin, objAprendizajeLeccion);
					
					con->IngresarLeccion(temaLeccion, objAprendizajeLeccion);
					
					cout << "Desea ingresar ejercicios? S/N";
					cin >> op;
					
					if(op == 'S') { /* INGRESO EJERCICIO */
						
						do{
							cout << " 1. Completar Frase \n 2. Traduccion" << endl;
							cout << "Ingrese tipo de ejercicio: ";
							cin >> tipoEjercicio;
							
							cout << "Ingrese descrpcion de ejercicio: ";
							getline(cin, descEjercicio);
							
							if(tipoEjercicio == 1) { /* Completar Frase */
								cout << "Ingrese la frase a completar (Mi --- es Juan y tengo 21 ---): \n>";
								getline(cin, fraseACompletar);
								
								cout << "Ingrese conjunto ordenado de palabras solucion (nombre, años): " << endl << "> ";
								getline(cin, palabrasSolucion);
								stringstream input_stringstream(palabrasSolucion);
								
								/* Ocurrencias del caracter , */
								for(int i = 0; i < (int)palabrasSolucion.size(); i++) {
									if(palabrasSolucion[i] == ',') {
										cantComa++;
									}
								}	
								
								/* Convierto Strings a Vector */
								for(int i = 0; i < cantComa; i++) {
									getline(input_stringstream, pal, ',');
									palabrasSol.push_back(pal);
								}
								
								con->IngresarEjercicioCF("CF", "", descEjercicio, fraseACompletar, palabrasSol);
							}else{ /* Traduccion */
								cout << "Ingrese frase a traducir: " << endl << "> ";
								getline(cin, fraseATraducir);
								
								cout << "Ingrese frase traducida" << endl << "> ";
								getline(cin, fraseTraducida);
								
								con->IngresarEjercicioT("T", "", descEjercicio, fraseATraducir, fraseTraducida);
							}
							
							cout << "Desea seguir ingresando ejercicio? S/N";
							cin >> op;
							system("cls");
							
						} while(op != 'N'); /* Mientras desee, Ingreso Ejercicio */
					}
					
					cout << "Desea seguir ingresando leccion? S/N";
					cin >> op;
					system("cls");
					
				} while(op != 'N'); /* Mientras desee, Ingreso Leccion */
			}
			
			
			if(con->AltaCurso()){
				cout<<"Curso creado con exito"<<endl;
				
			}else{
				cout<<"¡Este curso ya existe en el sistema!"<<endl;
			}
			
			break;
		};
		case 6:{
			
			string nombreCurso, temaLeccion, objAprendizajeLeccion, descEjercicio, fraseACompletar, palabrasSolucion, pal, fraseATraducir, fraseTraducida;
			vector<string> palabrasSol;
			int tipoEjercicio, cantComa;
			char op;
			con->listarCursosNoHabilitados();
			
			cout << "Ingrese nombre del curso: ";
			getline(cin, nombreCurso);
			con->SeleccionarCurso(nombreCurso);
			
			cout << "Ingrese tema de la leccion: ";
			getline(cin, temaLeccion);
			cout << "Ingrese objetivo de aprendizaje de la leccion: ";
			getline(cin, objAprendizajeLeccion);
			con->IngresarDatosLeccion(temaLeccion, objAprendizajeLeccion);
			
			cout << "Desea ingresar ejercicios? S/N";
			cin >> op;
			if(op == 'S') { 
				do{
					cout << " 1. Completar Frase \n 2. Traduccion" << endl;
					cout << "Ingrese tipo de ejercicio: ";
					cin >> tipoEjercicio;
					cout << "Ingrese descrpcion de ejercicio: ";
					getline(cin, descEjercicio);
					
					if(tipoEjercicio == 1) {/* Completar Frase */
						cout << "Ingrese la frase a completar (Mi --- es Juan y tengo 21 ---): \n>";
						getline(cin, fraseACompletar);
						
						cout << "Ingrese conjunto ordenado de palabras solucion (nombre, años): " << endl << "> ";
						getline(cin, palabrasSolucion);
						stringstream input_stringstream(palabrasSolucion);
						
						/* Ocurrencias del caracter , */
						for(int i = 0; i < (int)palabrasSolucion.size(); i++) {
							if(palabrasSolucion[i] == ',') {
								cantComa++;
							}
						}	
						
						/* Convierto Strings a Vector */
						for(int i = 0; i < cantComa; i++) {
							getline(input_stringstream, pal, ',');
							palabrasSol.push_back(pal);
						}
						
						con->IngresarEjercicioCF("CF", "", descEjercicio, fraseACompletar, palabrasSol);
					}else{ /* Traduccion */
						cout << "Ingrese frase a traducir: " << endl << "> ";
						getline(cin, fraseATraducir);
						
						cout << "Ingrese frase traducida" << endl << "> ";
						getline(cin, fraseTraducida);
						
						con->IngresarEjercicioT("T", "", descEjercicio, fraseATraducir, fraseTraducida);
					}
					cout << "Desea seguir ingresando ejercicio? S/N";
					cin >> op;
					system("cls");
				}while(op != 'N');
				
				con->AltaLeccion();
			}
			break;
		};
			/*!!!!!!!!!!!!!!!!!!!!!!!!!*/
			/*!!!!!INCOMPLETO!!!!!!!!!!*/
		case 7:{ /* AGREGAR EJERCICIO */ 
			vector<string> listaCursosNH, listaLecciones;
			string curso, leccion;
			bool delSistema;
			listaCursosNH = con->listarCursosNoHabilitados();
			for(int i=0; i< (int)listaCursosNH.size();i++){
				cout<<listaCursosNH[i]<<endl;
			}
			cout<<"Ingrese el nombre del curso:"<<endl;
			getline(cin,curso);
			delSistema = con->cursoPerteneceNoHab(curso);
			while(!delSistema){
				cout<<"El curso ingresado no corresponde. Por favor, ingrese uno de la siguiente lista:"<<endl;
				for(int i=0; i< (int)listaCursosNH.size();i++){
					cout<<listaCursosNH[i]<<endl;
				}
				getline(cin,curso);
				delSistema = con->cursoPerteneceNoHab(curso);
			}
			listaLecciones= con->listarLecciones(curso);
			for(int j=0; j< (int)listaLecciones.size();j++){
				cout<<listaLecciones[j]<<endl;
			}
			cout<<"Ingrese el tema de la leccion:"<<endl;
			getline(cin, leccion);
			bool esLeccion;
			for(int k=0;k<(int)listaLecciones.size();k++){
				if(leccion.compare(listaLecciones[k])==0){
					esLeccion=true;
				}else{
					esLeccion=false;
				}
			}
			while(!esLeccion){
				cout<<"El tema ingresado no corresponde. Por favor,ingrese un tema de la siguiente lista:"<<endl;
				getline(cin, leccion);
				for(int k=0;k<(int)listaLecciones.size();k++){
					if(leccion.compare(listaLecciones[k])==0){
						esLeccion=true;
					}else{
						esLeccion=false;
					}
				}
			}
			int op;
			con->seleccionarLeccion(leccion);
			cout<<"Que tipo de ejercicio desea ingresar:\n 1- Ejercicio de Completar Frase. \n 2- Ejercicio de Traduccion.\n 3- Cancelar."<<endl;
			fflush(stdin);
			cin>>op;
			
			break;
		};
		case 8:{
			string cursoAHab;
			cout<<"Por favor elija uno de los siguientes cursos:"<<endl;
			vector<string> cursos = con->listarCursosNoHabilitados();
			for(int i=0; i<(int)cursos.size();i++){
				cout<<cursos[i]<<endl;
			}
			fflush(stdin);
			getline(cin,cursoAHab);
			bool enSistema = con->cursoPerteneceNoHab(cursoAHab);
			while(!enSistema){
				cout<<"El curso ingresado no pertenece al sistema, por favor ingrese uno de los siguientes:"<<endl;
				for(int i=0; i<(int)cursos.size();i++){
					cout<<cursos[i]<<endl;
				}
				fflush(stdin);
				getline(cin,cursoAHab);
				enSistema = con->cursoPerteneceNoHab(cursoAHab);
			}
			if(con->habilitaCurso(cursoAHab)){
				system("cls");
				cout<<"El Curso fue habilitado con exito."<<endl;
				
			}else{
				cout<<"El curso no cumple con los requisitos para ser habilitado"<<endl;
			}
			
			break;
		};
		case 9:{
			string nombreCurso;
			con->listarCursos();
			
			cout << "Ingrese nombre de curso: ";
			getline(cin, nombreCurso);
			
			con->EliminarCurso(nombreCurso);
			
			break;
		};
		case 10:{ /* CONSULTAR CURSO */
			string curso;
			vector <string> cursos=con->listarCursos();
			for(int i=0; i<cursos.size();i++){
				cout<<cursos[i]<<endl;
			}
			string user;
			cout<<"¿De cual curso desea consultar la informacion?, seleccione uno: "<<endl;
			getline(cin, curso);
			
			DTInfoCurso* dtCurso=con->mostrarInfoCurso(curso);
			
			cout<<dtCurso->getNombreCurso()<<"\n"<<dtCurso->getDescripcion()<<"\n"<<dtCurso->getDificultad()<<"\n"<<dtCurso->getNombreIdioma()<<"\n"<<dtCurso->getNombreProfesor()<<"\n"<<dtCurso->getHabilitado()<<endl;
			
			if(!dtCurso->getDTLecciones().empty()){
				cout<<"INFO LECCIONES: "<<endl;
				for(int i=0; i<dtCurso->getDTLecciones().size() ; i++){
					cout<<dtCurso->getDTLecciones()[i]->getTema()<<"\n"<<dtCurso->getDTLecciones()[i]->getObjAprendizaje();
					if(!dtCurso->getDTLecciones()[i]->getDTEjercicios().empty()){
						cout<<endl;
						cout<<"INFO EJERCICIOS: "<<endl;
						for(int j=0; j<dtCurso->getDTLecciones()[i]->getDTEjercicios().size();j++){ 
							cout<<dtCurso->getDTLecciones()[i]->getDTEjercicios()[j]->getNombreEjercicio()<<"\n"<<dtCurso->getDTLecciones()[i]->getDTEjercicios()[j]->getDescEjercicio();
						}
						
					}
				}
			}
			
			if(!dtCurso->getDTInscripciones().empty()){
				cout<<endl;
				cout<<"INFO INSCRIPCIONES: "<<endl;
				for(int i=0; i<dtCurso->getDTInscripciones().size();i++){
					cout<<dtCurso->getDTInscripciones()[i]->getNombreEstudiante();
					cout<<dtCurso->getDTInscripciones()[i]->getFechaInscripcion()->getDia()<<"/"<<dtCurso->getDTInscripciones()[i]->getFechaInscripcion()->getMes()<<"/"<<dtCurso->getDTInscripciones()[i]->getFechaInscripcion()->getAnio()<<endl;
				}
				
			}
			
			break;
		};
		case 11:{
			string estudiante,cursoInsc;
			cout<<"Por favor ingrese uno de los siguientes estudiantes:"<<endl;
			vector<string> estudiantes=con->listarEstudiantes();
			for (int i=0; i<(int)estudiantes.size(); i++){
				cout<<estudiantes[i]<<endl;
			}
			fflush(stdin);
			getline(cin,estudiante);
			bool enSistema = con->estudiantePertenece(estudiante);
			while(!enSistema){
				cout<<"El estudiante ingresado no pertenece al sistema, por favor ingrese uno de los siguientes:"<<endl;
				for(int i=0; i<(int)estudiantes.size();i++){
					cout<<estudiantes[i]<<endl;
				}
				fflush(stdin);
				getline(cin,estudiante);
				enSistema = con->estudiantePertenece(estudiante);
			}
			vector<DTCurso*> cursosEstudiante = con->listarCursosHabilitadoEtudiante(estudiante);
			cout<<"Por favor indique a que curso desea inscribirse:"<<endl;
			for(int j=0; j<(int)cursosEstudiante.size(); j++){
				cout<<cursosEstudiante[j]<<endl;
			}
			fflush(stdin);
			getline(cin,cursoInsc);
			bool delSistema;
			for(int i=0;i<(int)cursosEstudiante.size();i++){
				if(cursoInsc.compare(cursosEstudiante[i]->getNombreCurso())==0){
					delSistema = true;
					break;
				}else{
					delSistema= false;
				}
			}
			while(!delSistema){
				cout<<"El curso ingresado no pertenece a los cursos habilitados para el estudiante."<<endl;
				cout<<"Por favor indique uno de la siguiente lista:"<<endl;
				for(int j=0; j<(int)cursosEstudiante.size(); j++){
					cout<<cursosEstudiante[j]<<endl;
				};
				fflush(stdin);
				getline(cin,cursoInsc);
				for(int i=0;i<(int)cursosEstudiante.size();i++){
					if(cursoInsc.compare(cursosEstudiante[i]->getNombreCurso())==0){
						delSistema = true;
						break;
					}else{
						delSistema= false;
					}
				}
			}
			con->inscripcionCurso(cursoInsc);
			break;
		};
		case 12:{ /* REALIZAR EJERCICIO */
			string usuario,curso, ejARealizar, solucionUsuario;
			vector<string> solucion;
			DTRealizaEjercicio* ej;
			vector<string> cursosIns;
			vector<DTRealizaEjercicio*> Ejercicios;
			cout<<"Ingrese el nickname del estudiante:"<<endl;
			fflush(stdin);
			getline(cin,usuario);
			bool enSistema= con->estudiantePertenece(usuario);
			if(!enSistema){
				cout<<"El nickname ingresado no pertenece al sistema."<<endl;
				cout<<"Por favor, ingrese un nickname nuevamente:"<<endl;
				getline(cin,usuario);
				enSistema= con->estudiantePertenece(usuario);
			}
			cursosIns = con->listarCursosInscripto(usuario);
			cout<<"Seleccione el curso:"<<endl;
			for(int i=0; i< (int)cursosIns.size();i++){
				cout<<cursosIns[i]<<endl;
			}
			getline(cin,curso);
			bool delSistema;
			for(int i=0;i<(int)cursosIns.size();i++){
				if(curso.compare(cursosIns[i])==0){
					delSistema = true;
					break;
				}else{
					delSistema= false;
				}
			}
			while(!delSistema){
				cout<<"El curso ingresado no pertenece al sistema."<<endl;
				cout<<"Por favor, ingrese un curso de la siguiente lista:"<<endl;
				for(int i=0; i< (int)cursosIns.size();i++){
					cout<<cursosIns[i]<<endl;
				}
				getline(cin,curso);
				
				for(int i=0;i<(int)cursosIns.size();i++){
					if(curso.compare(cursosIns[i])==0){
						delSistema = true;
						break;
					}else{
						delSistema= false;
					}
				}
			}
			Ejercicios = con->mostrarEjercicios(curso);
			for(int i=0; i< (int)Ejercicios.size();i++){
				cout<<Ejercicios[i]<<endl;
			}
			cout<<"Por favor, ingrese el nombre del ejercicio a realizar:"<<endl;
			getline(cin,ejARealizar);
			bool esEjercicio;
			for(int i=0;i<(int)Ejercicios.size();i++){
				if(ejARealizar.compare(Ejercicios[i]->getNombre())==0){
					esEjercicio = true;
					break;
				}else{
					esEjercicio= false;
				}
			}
			while(!esEjercicio){
				system("cls");
				cout<<"El ejercicio ingresado no corresponde a ninguno de los disponible."<<endl;
				cout<<"Por favor, ingrese un nombre de ejercicio de la siguiente lista:"<<endl;
				for(int i=0; i< (int)Ejercicios.size();i++){
					cout<<Ejercicios[i]<<endl;
				}
				getline(cin,ejARealizar);
				for(int i=0;i<(int)Ejercicios.size();i++){
					if(ejARealizar.compare(Ejercicios[i]->getNombre())==0){
						esEjercicio = true;
						ej= Ejercicios[i];
						break;
					}else{
						esEjercicio= false;
					}
				}
			}
			solucion = con->obtenerSolucionEjercicio(ejARealizar, curso);
			cout<<"El ejercicio a realizar es:"<<endl;
			cout<<ej<<endl;
			if(solucion[1].compare("CF")==0){
				cout<<"Por favor ingrese su solucion en el siguiente formato:"<<endl;
				cout<<"Palabra1-Palabra2-(etc.)"<<endl;
			}else{
				cout<<"Por favor ingrese su solucion:"<<endl;
			}
			getline(cin,solucionUsuario);
			bool aprobo;
			aprobo = con->apruebaEjercicio(solucionUsuario, solucion[0],curso);
			if(aprobo){
				cout<<"Felicitaciones! Aprobo el ejercicio."<<endl;
			}else{
				cout<<"Lamentablemente el ejercicio no fue aprobado. Vuelva a intentarlo despues."<<endl;
			}
			break;
		};
		case 13:{ /* CONSULTAR ESTADISTICAS */
			cout<<"Seleccione uno por favor...  \n 1.Estadisticas de Estudiantes \n 2.Estadisticas de Profesores \n 3.Estadisticas de cursos \n 4.Salir: "<<endl;
			cin>>opcion;
			fflush(stdin);
			cout<<endl;
			if(opcion == 4){
				break;
			}
			while(opcion != 1 && opcion != 2 && opcion != 3){
				if(opcion == 4){
					break;
				}
				cout<<"Seleccione una opcion correcta por favor...  \n 1.Estadisticas de Estudiantes \n 2.Estadisticas de Profesores \n 3.Estadisticas de cursos \n 4.Salir: "<<endl;
				cin>>opcion;
				fflush(stdin);
				cout<<endl;
			}
			switch(opcion){
			case 1:{
				if(con->getEstudiantes()->getSize() == 0) {
					cout << "error: No hay estudiantes en el Sistema" << endl;
					break;
				}else{
					string user;
					vector<string> estudiantes=con->listarEstudiantes();
					for (int i=0; i<(int)estudiantes.size(); i++){
						cout<<"Nombre del Estudiante " << i+1 << ":" <<estudiantes[i]<<endl;
					}
					cout<<"Seleccione un estudiante : "<<endl;
					getline(cin,user);
					
					const char* userChar=user.c_str();
					IKey* key= new String(userChar);
					
					if(con->getEstudiantes()->member(key)==false){
						cout<<endl;
						while(con->getEstudiantes()->member(key)==false){
							cout<<"El estudiante ingresado no existe, ingrese uno valido: "<<endl;
							cout<<endl;
							cout<<"Estudiantes disponibles :"<<endl;
							cout<<endl;
							for (int i=0; i<(int)estudiantes.size(); i++){
								cout<<"Nombre del Estudiante " << i+1 << ":" <<estudiantes[i]<<endl;
							}
							cout<<endl;
							cout<<"> ";
							getline(cin,user);
							userChar=user.c_str();
							key= new String(userChar);
						}
					}
					cout<<endl;
					vector<DTProgresoCurso*> Stats =  con->ListarEstadisticasEstudiante(user);
					for( int i=0; i<(int)Stats.size(); i++){
						cout<<Stats[i]<<endl;
					}
					cout<<endl<<endl;
					break;
				}
			};
			case 2: {
				if(con->getProfesores()->getSize() == 0) {
					cout << "error: No hay profesores en el Sistema" << endl;
					break;
				}else{
					string user;
					vector<string> profesores=con->listarProfesores();
					for (int i=0; i<(int)profesores.size(); i++){
						cout<<"Nombre del Profesor" << i+1 << ":" <<profesores[i]<<endl;
					}
					cout<<"Seleccione un profesor : "<<endl;
					getline(cin,user);
					
					const char* userChar=user.c_str();
					IKey* key= new String(userChar);
					
					if(con->getProfesores()->member(key)==false){
						cout<<endl;
						while(con->getProfesores()->member(key)==false){
							cout<<"El profesor ingresado no existe, ingrese uno valido: "<<endl;
							cout<<endl;
							cout<<"Profesores disponibles :"<<endl;
							cout<<endl;
							for (int i=0; i<(int)profesores.size(); i++){
								cout<<"Nombre del Profesores " << i+1 << ":" <<profesores[i]<<endl;
							}
							cout<<endl;
							cout<<"> ";
							getline(cin,user);
							userChar=user.c_str();
							key= new String(userChar);
						}
					}
					cout<<endl;
					vector<DTProgresoCurso*> Stats =  con->ListarCursosPropuestosPor(user);
					for( int i=0; i<(int)Stats.size(); i++){
						cout<<Stats[i]<<endl;
					}
					cout<<endl<<endl;
					break;
				}
			};
			case 3:{
				if(con->getCursosHabilitados()->getSize() == 0) {
					cout << "error: No hay cursos en el Sistema" << endl;
					break;
				}else{
					string user;
					vector<string> cursosHab=con->listarCursosHabilitados();
					for (int i=0; i<(int)cursosHab.size(); i++){
						cout<<"Nombre del Curso" << i+1 << ":" <<cursosHab[i]<<endl;
					}
					cout<<"Seleccione un Curso: "<<endl;
					getline(cin,user);
					
					const char* userChar=user.c_str();
					IKey* key= new String(userChar);
					
					if(con->getCursosHabilitados()->member(key)==false){
						cout<<endl;
						while(con->getCursosHabilitados()->member(key)==false){
							cout<<"El curso ingresado no existe, ingrese uno valido: "<<endl;
							cout<<endl;
							cout<<"Cursos disponibles :"<<endl;
							cout<<endl;
							for (int i=0; i<(int)cursosHab.size(); i++){
								cout<<"Nombre del Curso" << i+1 << ":" <<cursosHab[i]<<endl;
							}
							cout<<endl;
							cout<<"> ";
							getline(cin,user);
							userChar=user.c_str();
							key= new String(userChar);
						}
					}
					cout<<endl;
					DTProgresoCurso* Stats =  con->MostrarProgresoCurso(user);
					cout << Stats <<endl;
					cout<<endl<<endl;
				}
				
				break;
			};
			};
		};
		};
		
	} while(opcion != 14);
	
	
	return 0;
}
