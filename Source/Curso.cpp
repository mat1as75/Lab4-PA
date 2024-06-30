/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "../Header/Curso.h"
//#include "../ICollection/interfaces/ICollectible.h"
#include "../DataTypes/DTLeccion.h"
#include <vector>

Curso::Curso() {
}

Curso::~Curso() {
}

Curso::Curso(string nombreCurso, string descrpicionCurso, Dificultad dificultad) {
	this->nombreCurso = nombreCurso;
	this->descrpicionCurso = descrpicionCurso;
	this->dificultad = dificultad;
}

string Curso::getNombreCurso() {
	return this->nombreCurso;
}

string Curso::getDificultad() {
	string Dificultad;
	
	if (this->dificultad == Principiante)
		Dificultad = "Principiante";
	else
		if (this->dificultad == Medio)
			Dificultad = "Medio";
		else
			if (this->dificultad == Avanzado)
				Dificultad = "Avanzado";
	
	return Dificultad;
}

void Curso::AgregateLeccion(DTLeccion* DTLec) {
    /* 1.1 L := create() : Leccion */
    ICollectible* Lec = new Leccion(DTLec->getTema(), DTLec->getObjAprendizaje());
    
    const char* temaLeccion = DTLec->getTema().c_str();
    OrderedKey* ik = new String(temaLeccion);
    
    /* 1.2 add(L) */
    this->misLecciones->add(ik, Lec);
}

void Curso::AgregateLeccion(DTLeccion* DTLec) {
    /* 9*.1 L := create(DATALECCION) */
    Leccion* l = new Leccion(DTLec->getTema(), DTLec->getObjAprendizaje());

    const char* temaLeccion = l->getTema().c_str();
    OrderedKey* ik = new String(temaLeccion);   

    /* 9*.2 add(L) */
    this->misLecciones->add(ik, (ICollectible*)l);

    /* [for all DATAEJERCICIO in set<DATAEJERCICIO>] */
    /* 9*.3 agregateEjercicio(DATAEJERCICIO) */
    
    for(int i = 0; i < (int)DTLec->getMisEjercicios().size(); i++) {
        l->AgregateEjercicio(DTLec->getMisEjercicios()[i]);
    }

}

void Curso::AgregateEjercicio(vector<DTEjercicio*> DTEjercicios) {
    /* [for all DATAEJERCICIO in set<DATAEJERCICIO>] */
    /* 2* AgregateEjercicio(DATAEJERCICIO) */

    for(int i = 0; i < (int)DTEjercicios.size(); i++) {
        if(DTEjercicios[i]->getTipoEjercicio().compare("T") == 0) { /* Es DTTraduccion */
            DTEjercicios[i] = dynamic_cast<DTTraduccion*>(DTEjercicios[i]);
        }else{
            DTEjercicios[i] = dynamic_cast<DTCompletarFrase*>(DTEjercicios[i]);
        }
        ((Leccion*)this->misLecciones)->AgregateEjercicio(DTEjercicios[i]);
    }
}



void Curso::EliminarProfesor() {
    /* 3.1 EliminarCurso(c) */
    this->profeCurso->EliminarCurso(this);
}

void Curso::EliminarInscripciones() {
    
    /* 4.1* [for each] I := next() */
    /* REecorro coleccion de Inscripciones */
    IIterator* it1 = this->misInscripciones->getIterator();
    while(it1->hasCurrent()) {
        Inscripcion* i = (Inscripcion*) it1->getCurrent();
        i->EliminarCurso(this); /* 4.2* EliminarCurso(c) */
        delete(i); /* 4.3* destroy(i) */
        it1->next();
    }
    
    /* 4.4* [for each] L := next() */
    /* Recorro coleccion de Lecciones */
    IIterator* it2 = this->misLecciones->getIterator();
    while(it2->hasCurrent()) {
        Leccion* l = (Leccion*) it2->getCurrent();
        l->EliminarEjercicios(); /* 4.5* eliminarEjercicios() */
        delete(l); /* 4.6 destroy(L) */
        it2->next();
    }
    
    /* 4.7* [for each] PTEV := next() */
    /* Recorro coleccion de soyPrevioDe */
    IIterator* it3 = this->soyPrevioDe->getIterator();
    while(it3->hasCurrent()) {
        Curso* prev = (Curso*) it3->getCurrent();
        prev->EliminarCursoPrevio(this); /* 4.8* eliminarCursoPrecio(C) */
        it3->next();
    }
}

void Curso::EliminarCursoPrevio(Curso* c) {
    /* Creo Key con el nombreCurso de C */
    const char* nombreCurso = c->getNombreCurso().c_str();
    OrderedKey* ik = new String(nombreCurso);
    
    this->cursosPrevios->remove(ik); /* 4.8*.1 remove(C) */
}



/*Operaciones alta curso*/



void Curso::agregateCursoPrevio(IKey* nombreCPrev, Curso* cPrev){
	
	this->cursosPrevios->add(nombreCPrev ,cPrev);

}

void Curso::agregateIdioma(Idioma* idiomaDeCurso){
	this->idiomaCurso = idiomaDeCurso;
}

void Curso::agregateProfesor(Profesor* profDeCurso){
	this->profeCurso = profDeCurso;
	
}


/*Operaciones de consultar estadisticas*/

DTProgresoCurso* Curso::obtenerEstadisticasCursos(){
    float Progreso = 0;
    IIterator* it= this->misInscripciones->getIterator(); 
    while(it->hasCurrent()){ 
        Inscripcion* aux=(Inscripcion*)it->getCurrent(); 
        Progreso = Progreso + (aux->obtenerProgreso());
        it->next();
    }
    Progreso = Progreso / (this->misInscripciones->getSize());
    DTProgresoCurso* Prog = new DTProgresoCurso(this->nombreCurso,Progreso);

    return Prog;
}



/*Operaciones de habilitar curso*/

bool Curso:: tieneLecciones(){
	return !(this->misLecciones->isEmpty());
}


/*Operaciones de Inscribirse a curso*/
vector<string> Curso::getPrevios(){
	vector<string> nombresPrevios;
	IIterator* iter = this->cursosPrevios->getIterator();
	while(iter->hasCurrent()){
		nombresPrevios.push_back((dynamic_cast<Curso*>(iter->getCurrent())->getNombreCurso()));
		iter->next();
	}
	return nombresPrevios;
}


DTCurso* Curso::getDTCurso(){
	int cantEjercicios=0;
	int cantLecciones = this->misLecciones->getSize();
	IIterator* iter = this->misLecciones->getIterator();
	while(iter->hasCurrent()){
		Leccion* aux = (Leccion*)iter->getCurrent();
		cantEjercicios = cantEjercicios + (aux->obtenerCantEjercicios());
		iter->next();
	}
	DTCurso* curso = new DTCurso(this->nombreCurso, this->profeCurso->getNickname(), this->descrpicionCurso,this->idiomaCurso->getNombreIdioma(),this->dificultad, cantLecciones,cantEjercicios);
	return curso;
}

void Curso::agregateInscripcion(Inscripcion* ins){
	this->misInscripciones->add(ins);
}

Leccion* Curso::getUltimaLeccionACursar(){
	Leccion* lec;
	IIterator* iter = this->misLecciones->getIterator();
	while(iter->hasCurrent()){
		lec = (Leccion*)iter->getCurrent();
		break;
	}
	return lec;
}

vector<string> Curso::obtenerLecciones(){
	vector<string> lecciones;
	IIterator* iter = this->misLecciones->getIterator();
	while(iter->hasCurrent()){
		lecciones.push_back(((Leccion*)iter->getCurrent())->getTema());
		iter->next();
	}
	return lecciones;
}

Leccion* Curso::buscarLeccion(string leccion){
	const char* lec = leccion.c_str();
	IKey* key = new String(lec);
	Leccion* l = dynamic_cast<Leccion*>(this->misLecciones->find(key));
	return l;
}

