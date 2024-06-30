#ifndef DTINSCRIPCION_H
#define DTINSCRIPCION_H
#include "../Header/Date.h"
#include <string.h>
class DTInscripcion {
public:
	DTInscripcion();
	DTInscripcion(string nombreCurso, string nickname, Date* fechaInscripcion);
	DTInscripcion(string nombre, Date* fechaInscripcion);
	~DTInscripcion();
	string getNombreEstudiante();
	Date* getFechaInscripcion();
	
private:
	string nombreCurso;
	string nickname;
	string nombre;
	Date* fechaInscripcion;
};

#endif
