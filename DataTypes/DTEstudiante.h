#ifndef DTESTUDIANTE_H
#define DTESTUDIANTE_H
#include "DTUsuario.h"
#include <string>
using namespace std;
class DTEstudiante : public DTUsuario {
public:
	DTEstudiante();
	DTEstudiante(string nombre,string descripcion,string paisRes);
	string toString();
	~DTEstudiante();
private:
	string paisRes;
	
};

#endif
