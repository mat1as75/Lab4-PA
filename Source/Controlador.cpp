/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <string>
#include "../Header/Controlador.h"
#include "../ICo.h"
#include "../Header/Usuario.h"
#include "../Header/Curso.h"
using namespace std;

Controlador* Controlador::miInstancia = nullptr;

Controlador::Controlador() {
	this->Estudiantes=new OrderedDictionary();
	this->Profesores= new OrderedDictionary();
	this->Idiomas=new OrderedDictionary();
	this->misIdiomasAuxiliares=new OrderedDictionary();
    this->CursosHabilitados=new OrderedDictionary();
    this->CursosNoHabilitados=new OrderedDictionary();
    this->auxCursosPrev=new OrderedDictionary();
    this->auxIdiomaDeCurso=new Idioma;
    this->auxProfDeCurso=new Profesor;
    this->cursoACrear=new DTCurso;

}


Controlador* Controlador::getInstance() {
    if (Controlador::miInstancia == nullptr) {
        Controlador::miInstancia = new Controlador();
    }
    return (Controlador::miInstancia);
}

IDictionary* Controlador::getCursosNoHabilitados() {
    return this->CursosNoHabilitados;
}

IDictionary* Controlador::getCursosHabilitados() {
    return this->CursosHabilitados;
}

IDictionary* Controlador::getEstudiantes() {
    return this->Estudiantes;
}

IDictionary* Controlador::getProfesores() {
    return this->Profesores;
}

IDictionary* Controlador::getIdiomas() {
    return this->Idiomas;
}

vector<string> Controlador::listarCursosNoHabilitados() {
    IIterator* iter = this->CursosNoHabilitados->getIterator();
    vector<string> nombresNoHabilitados;

	/* Recorro coleccion de cursos no habilitados */
    while(iter->hasCurrent()) {
        nombresNoHabilitados.push_back(dynamic_cast<Curso*>(iter->getCurrent())->getNombreCurso());
        iter->next(); // Siguiente
    }

    return nombresNoHabilitados;
}

void Controlador::SeleccionarCurso(string nombreCurso) {
    IIterator* iter = this->CursosNoHabilitados->getIterator();
    while(iter->hasCurrent()) {
        // Si lo encuentra lo guardo en ptr auxiliar
        if(((Curso*)iter->getCurrent())->getNombreCurso() == nombreCurso) {
            this->auxCurso = dynamic_cast<Curso*>(iter->getCurrent());
            break;
        }
        iter->next(); // Siguiente
    }

}

void Controlador::IngresarDatosLeccion(string tema, string objAprendizaje) {
    // Asigno los datos en un datatype
    this->auxDTLeccion->setTema(tema);
    this->auxDTLeccion->setObjAprendizaje(objAprendizaje);
}

void Controlador::AltaLeccion() {
    // 1 agregateLeccion()
    Leccion* Lec = this->auxCurso->AgregateLeccion(this->auxDTLeccion);

    this->auxCurso->AgregateEjercicio(this->auxDTEjercicios, Lec);
}

vector <string> Controlador::listarIdiomasEspecializados(){
	vector<string> listaIdiomasEsp;
	
	cout<<"Los idiomas especializados de este profesor son:\n " <<endl;
	IIterator* it=this->auxProfDeCurso->getIdiomasEspecializado()->getIterator();
	while(it->hasCurrent()){
		Idioma* nuevoIdioma=(Idioma*)it->getCurrent();

		listaIdiomasEsp.push_back(nuevoIdioma->getNombreIdioma());
		it->next();
	}
	return listaIdiomasEsp;
	
}

vector <string> Controlador::listarProfesores(){
	vector<string> listaProfesores;
	IIterator* it=this->Profesores->getIterator();
	while(it->hasCurrent()){
		Profesor* profe=(Profesor*) it->getCurrent();
		listaProfesores.push_back(profe->getNickname());
		it->next();
	}
	
	return listaProfesores;
	
}

void Controlador::ingresarDatosCurso(string nicknameP, string nombre, string descripcion, Dificultad dif){
	const char* profe=nicknameP.c_str();
	IKey* key=new String(profe);
	
	
	this->auxProfDeCurso = dynamic_cast<Profesor*>(this->misProfesores->find(key));
	
	this->cursoACrear->nombreCurso=nombre;
	this->cursoACrear->descCurso=descripcion;
	this->cursoACrear->dificultad=dif;
}

void Controlador::buscarIdioma(string nombreIdioma){
	const char* idioma=nombreIdioma.c_str();
	IKey* key=new String(idioma);
	this->auxIdiomaDeCurso = dynamic_cast<Idioma*>(this->misIdiomas->find(key));
}

vector <string> Controlador::listarCursosHabilitados(){
	vector<string> listaCursosHab;
	IIterator* it=this->CursosHabilitados->getIterator();
	while(it->hasCurrent()){
		Curso* curso=(Curso*) it->getCurrent();
		listaCursosHab.push_back(curso->getNombreCurso());
		it->next();
	}
	
	return listaCursosHab;
}

void Controlador::buscarCursoPrevio(string nombreCursoPrev){
	const char* cursoP=nombreCursoPrev.c_str();
	IKey* key=new String(cursoP);
	
	
	ICollectible* auxCursoPrevio = this->CursosHabilitados->find(key);
	this->auxCursosPrev->add(key,auxCursoPrevio);
	
	
}

bool Controlador::AltaCurso(){
	bool retorno;
	string nombreC = this->cursoACrear->nombreCurso;
	const char* curso=nombreC.c_str();
	string desc = this->cursoACrear->descCurso;
	Dificultad dif = this->cursoACrear->dificultad;
	IKey* ik=new String(curso);
	bool existe= this->CursosHabilitados->member(ik);
	if(!existe){
		existe = this->CursosNoHabilitados->member(ik);
		if(!existe){
			Curso* cursoNuevo = new Curso(nombreC,desc,dif);
			cursoNuevo->agregateProfesor(this->auxProfDeCurso);
			cursoNuevo->agregateIdioma(this->auxIdiomaDeCurso);
			bool cPrevios = this->auxCursosPrev->isEmpty();
			if(!cPrevios){
				IIterator* it =this->auxCursosPrev->getIterator();
				while(it->hasCurrent()){
					Curso* cPrev = (Curso*) it->getCurrent();
					const char* nombreCPrev=cPrev->getNombreCurso().c_str();
					IKey* key = new String(nombreCPrev);
					cursoNuevo->agregateCursoPrevio(key, cPrev);
					this->misIdiomasAuxiliares->remove(key);
					it->next();
				}
			}
			//###########################################
			//###########################################
			//!!!!!!! Las Lecciones y ejercicios!!!!!!!!!
			//###########################################
			//###########################################
			
			
			this->CursosNoHabilitados->add(ik,(ICollectible*)cursoNuevo);
			retorno = true;
		}
		else{
			bool cPrevios = this->auxCursosPrev->isEmpty();
			if(!cPrevios){
				IIterator* it =this->auxCursosPrev->getIterator();
				while(it->hasCurrent()){
					Curso* cPrev = (Curso*) it->getCurrent();
					const char* nombreCPrev=cPrev->getNombreCurso().c_str();
					IKey* key = new String(nombreCPrev);
					this->misIdiomasAuxiliares->remove(key);
					it->next();
				}
			}
			this->auxProfDeCurso = NULL;
			this->auxIdiomaDeCurso = NULL;
			delete this->cursoACrear;
			retorno = false;
		}
		
	}else{
		bool cPrevios = this->auxCursosPrev->isEmpty();
		if(!cPrevios){
			IIterator* it =this->auxCursosPrev->getIterator();
			while(it->hasCurrent()){
				Curso* cPrev = (Curso*) it->getCurrent();
				const char* nombreCPrev=cPrev->getNombreCurso().c_str();
				IKey* key = new String(nombreCPrev);
				this->misIdiomasAuxiliares->remove(key);
				it->next();
			}
		}
		this->auxProfDeCurso = NULL;
		this->auxIdiomaDeCurso = NULL;
		delete this->cursoACrear;
		retorno = false;
	}
	
	return retorno;
}


/*Alta Usuario*/

void Controlador::ingresarDatosEstudiante(string nickname, string contrasena, string nombre, string descripcion, string paisRes, Date* fecNac){
	this->nickname=nickname;
	this->contrasena=contrasena;
	this->nombre=nombre;
	this->descripcion=descripcion;
	this->fecNac=fecNac;
	this->paisRes=paisRes;
}

void Controlador::ingresarDatosProfesor(string nickname, string contrasena, string nombre, string descripcion, string instituto){
	this->nickname=nickname;
	this->contrasena=contrasena;
	this->nombre=nombre;
	this->descripcion=descripcion;
	this->instituto=instituto;
}

IDictionary* Controlador::getProfesores(){
	return this->Profesores;
}

bool Controlador::altaUsuario(){
	
	bool retorno;
	if (this->paisRes.compare("")!=0){ // si hay datos de Estudiante ingresados(paisRes)
		
		const char* nick=this->nickname.c_str(); // convierto string a char*
		IKey* ik=new String(nick);
		
		bool existe= this->Estudiantes->member(ik);
		if(!existe){
			ICollectible* estudiante = new Estudiante(this->nickname,this->contrasena,this->nombre,this->descripcion,this->paisRes,this->fecNac);
			this->Estudiantes->add(ik,estudiante);
			this->paisRes="";
			retorno= true;
		}else{
			
			retorno= false;
		}
	}else if(this->instituto.compare("")!=0){ // si la variable instituto no esta vacia significa que hay un PROFESOR ingresado
		
		const char* nick=this->nickname.c_str(); // convierto string a char*
		IKey* ik = new String(nick);
		bool existe = this->Profesores->member(ik);
		if(!existe){
			
			Profesor* profesor = new Profesor(this->nickname,this->contrasena,this->nombre,this->descripcion,this->instituto);
			IIterator* it =this->misIdiomasAuxiliares->getIterator();
			
			while(it->hasCurrent()){
				Idioma* idiomaAux=(Idioma*)it->getCurrent();
				const char* idioma=idiomaAux->getNombreIdioma().c_str();
				IKey* nuevaIK= new String(idioma);

				profesor->getIdiomasEspecializado()->add(nuevaIK,it->getCurrent());
				this->misIdiomasAuxiliares->remove(nuevaIK);
				it->next();
				
			}

			
			this->Profesores->add(ik,(ICollectible*)profesor);
			
			this->instituto="";
			retorno= true;
		}else{
			IIterator* it = this->misIdiomasAuxiliares->getIterator();
			while(it->hasCurrent()){
				Idioma* idioma = (Idioma*) it->getCurrent();
				const char* nombreIdioma=idioma->getNombreIdioma().c_str();
				IKey* key = new String(nombreIdioma);
			
				this->misIdiomasAuxiliares->remove(key);
				
				it->next();
			}
		
			retorno= false;
		}
	}
	return retorno;
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