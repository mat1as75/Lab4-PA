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
	DTInfoCurso(string nombreCurso,string descrpicionCurso,Dificultad dificultad,string idiomaCurso,string nombreProfesor,vector<DTLeccion*>listaLecciones,vector<DTInscripcion*> listaInscripciones);
	~DTInfoCurso();
	vector<DTLeccion*> getDTLecciones();
	vector<DTInscripcion*> getDTInscripciones();
	string getNombreCurso();
	string getDescripcion();
	string getDificultad();
	string getNombreIdioma();
	string getNombreProfesor();
	string getHabilitado();
	
private:
	
string nombreCurso;
string descripcion;
Dificultad dificultad;
string nombreIdioma;
string nombreProfesor;
bool habilitado;
vector<DTLeccion*> lecciones;
vector<DTInscripcion*> inscripciones;

};

#endif
