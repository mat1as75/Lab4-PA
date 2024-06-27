#ifndef DTPROFESOR_H
#define DTPROFESOR_H
#include "DTUsuario.h"
#include <string>
#include "IDictionary.h"
using namespace std;

class DTProfesor : public DTUsuario {
public:
	DTProfesor();
	DTProfesor(string nombre,string descripcion,string instituto,IDictionary* idiomasEspecializado);
	string toString() override;
	~DTProfesor();
private:
	string instituto;
	IDictionary* idiomasEspecializado;
};

#endif