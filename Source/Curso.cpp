/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "../Header/Curso.h"
#include "../ICo.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "../DataTypes/DTLeccion.h"

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

void Curso::AgregateEjercicio(IDictionary* DTEjercicios) {
    /* [for all DATAEJERCICIO in set<DATAEJERCICIO>] */
    /* 2* AgregateEjercicio(DATAEJERCICIO) */
    
    IIterator* iter = DTEjercicios->getIterator();
    
    while(iter->hasCurrent()) {
        DTEjercicio* ej = (DTEjercicio*) iter->getCurrent();
        
        if(ej->getTipoEjercicio().compare("T") == 0)  /* Es DTTraduccion */
            ej = (DTTraduccion*) iter->getCurrent();
        else
            ej = (DTCompletarFrase*) iter->getCurrent();
		
        ((Leccion*)this->misLecciones)->AgregateEjercicio(ej);
        iter->next();
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

void Curso::agregateCursoPrevio(IKey* nombreCPrev, Curso* cPrev){
	
	this->cursosPrevios->add(nombreCPrev ,cPrev);

}

void Curso::agregateIdioma(Idioma* idiomaDeCurso){
	this->idiomaCurso = idiomaDeCurso;
}

void Curso::agregateProfesor(Profesor* profDeCurso){
	this->profeCurso = profDeCurso;
	
}

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