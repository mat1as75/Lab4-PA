/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <string.h>
#include "Header/Controlador.h"
#include "Header/Usuario.h"
#include "Header/Curso.h"
#include "DTCurso.h"
#include "DataTypes/DTProgresoCurso.h"
#include "../ICo.h"
#include "String.h"
#include "Estudiante.h"
#include "Profesor.h"
#include <vector>
#include "Idioma.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "DTUsuario.h"
#include "../ICollection/interfaces/ICollectible.h"

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

}


Controlador* Controlador::getInstance() {
    if (Controlador::miInstancia == nullptr) {
        Controlador::miInstancia = new Controlador();
    }
    return (Controlador::miInstancia);
}
/*Getters de IDictionarys*/
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

IDictionary* Controlador::getIdiomasAuxiliares(){
	return this->misIdiomasAuxiliares;
}



/*Operaciones de Alta Usuario*/
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

vector <string> Controlador::listarIdiomasDisponibles(){
	vector<string> listaIdiomas;
	IIterator* it= this->Idiomas->getIterator(); //instancio un iterador con el primer elemento de la lista
	while(it->hasCurrent()){ // mientras it no sea null recorro
		Idioma* aux=(Idioma*)it->getCurrent(); // casteo ( convierto) el ICollectible Estudiante a tipo Estudiante* para obtener acceso a sus atributos
		listaIdiomas.push_back(aux->getNombreIdioma());
		it->next(); // me muevo al siguiente puntero de la coleccion ( IDictionary misEstudiantes)
	}
	
	return listaIdiomas;
}

void Controlador::ingresarIdiomaEspecializado(string nombreIdioma){
	const char* idioma=nombreIdioma.c_str();
	IKey* key=new String(idioma);
	
	
	ICollectible* idiomaAux = this->Idiomas->find(key);
	this->misIdiomasAuxiliares->add(key,idiomaAux);
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

			
			this->Profesores->add(ik,(ICollectible*) profesor);
			
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

bool Controlador::ingresarIdioma(string idioma){
	
	const char* idiom=idioma.c_str();
	
	IKey* key =new String(idiom);
	
	
	bool existe=this->Idiomas->member(key);
	if(!existe){
		
		ICollectible* nuevoIdioma= new Idioma(idioma);
		
		this->Idiomas->add(key,nuevoIdioma);
		
		return true;
	}else{
		return false;
	}
	
	
}

/*Operaciones de Alta Leccion */

vector<string> Controlador::listarCursosNoHabilitados() {
    IIterator* iter = this->CursosNoHabilitados->getIterator();
    vector<string> nombresNoHabilitados;

	/* Recorro coleccion de cursos no habilitados */
    while(iter->hasCurrent()) {
		Curso* c = (Curso*) iter->getCurrent();
        nombresNoHabilitados.push_back(c->getNombreCurso());
        iter->next(); // Siguiente
    }

    return nombresNoHabilitados;
}

void Controlador::SeleccionarCurso(string nombreCurso) {
    const char* nombreC = nombreCurso.c_str();
    OrderedKey* ik = new String(nombreC);
    this->cursoSeleccionado = (Curso*)this->CursosNoHabilitados->find(ik);
}

void Controlador::IngresarDatosLeccion(string tema, string objAprendizaje) {
    // Asigno los datos en un datatype
    this->auxDTLeccion->setTema(tema);
    this->auxDTLeccion->setObjAprendizaje(objAprendizaje);
}

void Controlador::IngresarLeccion(string tema, string objAprendizaje) {
	/* Creo un DTLeccion y la agrego a la coleccion 
	de DTLeccionesAux del controlador */
	DTLeccion* DTLec = new DTLeccion(tema, objAprendizaje);
	this->DTLeccionesAux.push_back(DTLec);
}

void Controlador::AltaLeccion() {
    // 1 agregateLeccion()
    this->cursoSeleccionado->AgregateLeccion(this->auxDTLeccion);

    this->cursoSeleccionado->AgregateEjercicio(this->auxDTEjercicios);
}

void Controlador::IngresarEjercicioCF(string tipoEjercicio, string nombreEjercicio, string descripcion, string fraseACompletar, vector<string> palabrasSolucion) {
    DTCompletarFrase* aux = new DTCompletarFrase("CF", nombreEjercicio, descripcion, fraseACompletar, palabrasSolucion);
    
    /* Agrego DTEjercicio a coleccion de DTEjercicios auxiliar */
    this->auxDTEjercicios.push_back(aux);
}

void Controlador::IngresarEjercicioT(string tipoEjercicio, string nombreEjercicio, string descripcion, string fraseATraducir, string fraseTraducida) {
    DTTraduccion* aux = new DTTraduccion("T", nombreEjercicio, descripcion, fraseATraducir, fraseTraducida);
    
    /* Agrego DTEjercicio a coleccion de DTEjercicios auxiliar */
    this->auxDTEjercicios.push_back(aux);
}

vector<string> Controlador::ListarCursos() {
    vector<string> nombresCursos;
    
    /* Recorro coleccion de cursos habilitados */
    IIterator* it1 = this->CursosHabilitados->getIterator();
    while(it1->hasCurrent()) {
        Curso* c = (Curso*) it1->getCurrent();
        nombresCursos.push_back(c->getNombreCurso());
        it1->next();
    }
    
    /* Recorro coleccion de cursos no habilitados */
    IIterator* it2 = this->CursosNoHabilitados->getIterator();
    while(it2->hasCurrent()) {
        Curso* c = (Curso*) it2->getCurrent();
        nombresCursos.push_back(c->getNombreCurso());
        it2->next();
    }
    
    return nombresCursos;
}

void Controlador::EliminarCurso(string nombreCurso) {
    /* 1 C := find(nombreCurso) : CURSO */
    const char* nombreC = nombreCurso.c_str();
    OrderedKey* ik = new String(nombreC);
    Curso* c = (Curso*)this->CursosHabilitados->find(ik);
    
    if(c == NULL) { /* Si no lo encuentra */
        /* 2 C := find(nombreCurso) : CURSO */
        c = (Curso*)this->CursosNoHabilitados->find(ik);
    }
    
    c->EliminarProfesor(); /* 3 EliminarProfesor() */
    c->EliminarInscripciones(); /* 4 EliminarInscripciones() */
    delete(c); /* 5 destroy() */

/*Operaciones de Consulta Usuario*/
vector <string> Controlador::listarUsuarios(){
	vector<string> listaUsuarios;
	IIterator* it=this->Estudiantes->getIterator();
	while(it->hasCurrent()){
		Estudiante* estudiante= (Estudiante*) it->getCurrent();
		listaUsuarios.push_back(estudiante->getNickname());
		it->next();
	}
	
	
	IIterator* it2=this->Profesores->getIterator();
	while(it2->hasCurrent()){
		Profesor* profe=(Profesor*) it2->getCurrent();
		listaUsuarios.push_back(profe->getNickname());
		it2->next();
	}
	
	
	return listaUsuarios;
}

DTUsuario* Controlador::mostrarInfoUsuario(string nickname2){
	const char* nick=nickname2.c_str();
	IKey* key = new String(nick);
	
	ICollectible* ICestudiante = this->Estudiantes->find(key);
	
	if(ICestudiante!=NULL){
		Estudiante* estudiante=(Estudiante*) ICestudiante;
	
		return estudiante->getInfo();
	}else{
		ICollectible* ICprofesor = this->Profesores->find(key);
		
		Profesor* profe=(Profesor*) ICprofesor;
		if(ICprofesor!=NULL){
			
			return profe->getInfo();
		}
	}
	return NULL;
}

/*Operaciones de Alta Curso*/
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
	
	
	this->auxProfDeCurso = dynamic_cast<Profesor*>(this->Profesores->find(key));
	
	this->cursoACrear= new DTCurso(nombre, descripcion, dif);
}

void Controlador::buscarIdioma(string nombreIdioma){
	const char* idioma=nombreIdioma.c_str();
	IKey* key=new String(idioma);
	this->auxIdiomaDeCurso = dynamic_cast<Idioma*>(this->Idiomas->find(key));
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
	const char* cursoP = nombreCursoPrev.c_str();
	OrderedKey* key = new String(cursoP);
	
	ICollectible* auxCursoPrevio = (ICollectible*) this->CursosHabilitados->find(key);
	//Curso* auxCursoPrevio = dynamic_cast<Curso*>(this->CursosHabilitados->find(key));

	this->auxCursosPrev->add(key, auxCursoPrevio);
}

bool Controlador::AltaCurso(){
	bool retorno;
	string nombreC = this->cursoACrear->getNombreCurso();
	const char* curso=nombreC.c_str();
	string desc = this->cursoACrear->getDescCurso();
	Dificultad dif = this->cursoACrear->getDificultad();
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
			
			/* LECCIONES Y EJERCICIOS */
			/* [for all DATALECCION in set<DATALECCION>] */
			if (!this->DTLeccionesAux.empty()) {
				for(int i = 0; i < (int)this->DTLeccionesAux.size(); i++) {
					/* 9* agregateLeccion(DATALECCION) */
					cursoNuevo->agregateLeccion(this->DTLeccionesAux[i]);
				}
			}
			
			this->CursosNoHabilitados->add(ik, cursoNuevo);
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

/*Operaciones de Agregar Ejercicio*/

void Controlador::seleccionarLeccion(string leccion){
	Leccion* l = this->auxC->buscarLeccion(leccion);
	this->auxLeccion = l;
}
vector<string> Controlador::listarLecciones(string nomCurso){
	const char* curso = nomCurso.c_str();
	IKey* key = new String(curso);
	Curso* auxCurso = (Curso*)this->CursosNoHabilitados->find(key);
	this->auxC = auxCurso;
	vector<string> lecciones = auxCurso->obtenerLecciones();
	return lecciones;
}

void Controlador::IngresarEjercicioCF(string tipoEjercicio, string nombreEjercicio, string descripcion, string fraseACompletar, vector<string> palabrasSolucion) {
    DTCompletarFrase* aux = new DTCompletarFrase("CF", nombreEjercicio, descripcion, fraseACompletar, palabrasSolucion);
    
    const char* nombreC = aux->getNombreEjercicio().c_str();
    OrderedKey* ik = new String(nombreC);
    
    /* Agrego DTEjercicio a coleccion de DTEjercicios auxiliar */
    this->DTEjerciciosAux->add(ik, dynamic_cast<ICollectible*>( aux));
}

void Controlador::IngresarEjercicioT(string tipoEjercicio, string nombreEjercicio, string descripcion, string fraseATraducir, string fraseTraducida) {
    DTTraduccion* aux = new DTTraduccion("T", nombreEjercicio, descripcion, fraseATraducir, fraseTraducida);
    
    const char* nombreC = aux->getNombreEjercicio().c_str();
    OrderedKey* ik = new String(nombreC);
    
    /* Agrego DTEjercicio a coleccion de DTEjercicios auxiliar */
    this->DTEjerciciosAux->add(ik, dynamic_cast<ICollectible*> (aux));
}


/*Operaciones de Eliminar Curso*/


vector<string> Controlador::ListarCursos() {
    vector<string> nombresCursos;
    
    /* Recorro coleccion de cursos habilitados */
    IIterator* it1 = this->CursosHabilitados->getIterator();
    while(it1->hasCurrent()) {
        Curso* c = (Curso*) it1->getCurrent();
        nombresCursos.push_back(c->getNombreCurso());
        it1->next();
    }
    
    /* Recorro coleccion de cursos no habilitados */
    IIterator* it2 = this->CursosNoHabilitados->getIterator();
    while(it2->hasCurrent()) {
        Curso* c = (Curso*) it2->getCurrent();
        nombresCursos.push_back(c->getNombreCurso());
        it2->next();
    }
    
    return nombresCursos;
}

void Controlador::EliminarCurso(string nombreCurso) {
    /* 1 C := find(nombreCurso) : CURSO */
    const char* nombreC = nombreCurso.c_str();
    OrderedKey* ik = new String(nombreC);
    Curso* c = (Curso*)this->CursosHabilitados->find(ik);
    
    if(c == NULL) { /* Si no lo encuentra */
        /* 2 C := find(nombreCurso) : CURSO */
        c = (Curso*)this->CursosNoHabilitados->find(ik);
    }
    
    c->EliminarProfesor(); /* 3 EliminarProfesor() */
    c->EliminarInscripciones(); /* 4 EliminarInscripciones() */
    delete(c); /* 5 destroy() */
}


/*Operaciones De Consultar Estadisticas*/
vector <string> Controlador::listarEstudiantes(){
	vector<string> misEstudiantes;
	IIterator* it= this->Estudiantes->getIterator(); 
	while(it->hasCurrent()){ 
		Estudiante* aux=(Estudiante*)it->getCurrent(); //
		misEstudiantes.push_back(aux->getNickname());
		it->next();
	}
	
	return misEstudiantes;
}

vector <DTProgresoCurso*> Controlador::ListarEstadisticasEstudiante(string nickname){
	const char* nick=nickname.c_str();
	IKey* key = new String(nick);
	
	ICollectible* ICestudiante = this->Estudiantes->find(key);

		Estudiante* estudiante=(Estudiante*) ICestudiante;
		vector <DTProgresoCurso*> DTProgresos = estudiante->obtenerProgreso();
		return DTProgresos;
}

vector <DTProgresoCurso*> Controlador::ListarCursosPropuestosPor(string nickname){
	const char* nick=nickname.c_str();
	IKey* key = new String(nick);
	
	ICollectible* ICprofesor= this->Profesores->find(key);
	
	Profesor* profesor=(Profesor*) ICprofesor;
	vector <DTProgresoCurso*> DTProgresos = profesor->obtenerEstadisticasCursos();
	
	return DTProgresos;
}
	
DTProgresoCurso* Controlador::MostrarProgresoCurso(string nombreCurso){
	const char* cur=nombreCurso.c_str();
	IKey* key = new String(cur);
	
	ICollectible* ICcurso= this->CursosHabilitados->find(key);
	Curso* curso=(Curso*) ICcurso;
	
	DTProgresoCurso* DTProgresos = curso->obtenerEstadisticasCursos();
	
	return DTProgresos;
}

/*Operaaciones de Habilitar Curso*/
bool Controlador::cursoPerteneceNoHab(string nomCurso){
	const char* curso=nomCurso.c_str();
	IKey* key = new String(curso);
	return this->CursosNoHabilitados->member(key);
}
bool Controlador::habilitaCurso(string nomCurso){
	const char* curso=nomCurso.c_str();
	IKey* key = new String(curso);
	Curso* cursoHab = dynamic_cast<Curso*>(this->CursosNoHabilitados->find(key));
	bool seHabilita = cursoHab->tieneLecciones();
	if(seHabilita){
		this->CursosHabilitados->add(key,cursoHab);
		this->CursosNoHabilitados->remove(key);
	}
	return seHabilita;
}


/*Operaciones de Inscribirse a Curso*/
bool Controlador::estudiantePertenece(string estudiante){
	const char* est=estudiante.c_str();
	IKey* key = new String(est);
	return this->Estudiantes->member(key);
}

vector<DTCurso*> Controlador::listarCursosHabilitadoEtudiante(string estudiante){
	vector<DTCurso*> cursosPuedeCursar;
	string nombreCurso;
	vector<string> nombresCPrevios;
	bool estCurso, puedoCursar;
	const char* est=estudiante.c_str();
	IKey* key = new String(est);
	Estudiante* auxEstudiante= dynamic_cast<Estudiante*>(this->Estudiantes->find(key));
	this->auxEstInscripcion = auxEstudiante;
	IIterator* iter = this->CursosHabilitados->getIterator();
	while(iter->hasCurrent()) {
		nombreCurso=(dynamic_cast<Curso*>(iter->getCurrent())->getNombreCurso());
		estCurso = auxEstudiante->cursasteCurso(nombreCurso);
		if(estCurso){
			iter->next();
		}else{
			Curso* auxCurso = dynamic_cast<Curso*>(iter->getCurrent());
			nombresCPrevios = auxCurso->getPrevios();
			puedoCursar = auxEstudiante->puedoCursar(nombresCPrevios);
			if(!puedoCursar){
				iter->next();
			}
			else{
				cursosPuedeCursar.push_back(auxCurso->getDTCurso());
				iter->next();
			}
		}
		
	}
	return cursosPuedeCursar;
	
}

void Controlador::inscripcionCurso(string nomC){
	const char* curso=nomC.c_str();
	IKey* key = new String(curso);
	Curso* aux = (Curso*)this->CursosHabilitados->find(key);
	this->auxEstInscripcion->inscribirseACurso(aux);
	
}

/*Operaciones Realizar Ejercicio*/

vector<string> Controlador::listarCursosInscripto(string nomE){
	const char* estudiante=nomE.c_str();
	IKey* key = new String(estudiante);
	vector<string> nombresCursos;
	Estudiante* aux = dynamic_cast<Estudiante*>(this->Estudiantes->find(key));
	nombresCursos=aux->obtenerCursos();
	
}

vector<DTRealizaEjercicio*> Controlador::mostrarEjercicios(string curso){
	vector<DTRealizaEjercicio*> ejercicios;
	ejercicios= this->auxEstRealizarEj->obtenerDTREjercicios(curso);
	return ejercicios;
	
}

vector<string> Controlador::obtenerSolucionEjercicio(string ejARealizar,string curso){
	this->auxEjercicioRealizar = ejARealizar;
	vector<string> solucion = this->auxEstRealizarEj->obtenerSolucion(ejARealizar, curso);
	return solucion;
}

bool Controlador::apruebaEjercicio(string solucionUsuario,string solucionEjercicio, string nomCurso){
	bool aprobo = (solucionUsuario.compare(solucionEjercicio)==0);
	if(aprobo){
		this->auxEstRealizarEj->aprobasteEjercicio(this->auxEjercicioRealizar, nomCurso);
	}
	
	return aprobo;
}
