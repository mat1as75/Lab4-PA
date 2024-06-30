#ifndef DTINFOCURSO_H
#define DTINFOCURSO_H
#include <string>
#include <vector>
#include "DTLeccion.h"
#include "DTInscripcion.h"
using namespace std;
enum Dificultad {
	Principiante,
	Medio,
	Avanzado
};

class DTInfoCurso {
public:
	DTInfoCurso();
	~DTInfoCurso();
private:
	
string nombreCurso;
string descripcion;
Dificultad dificultad;
string nombreIdioma;
string nombreProfesor;
bool habilitado;
vector<DTLeccion> lecciones;
vector<DTInscripcion> inscripciones;

};

#endif