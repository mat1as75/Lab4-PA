#ifndef DTUSUARIO_H
#define DTUSUARIO_H
#include <string>
using namespace std;

class DTUsuario {
public:
	DTUsuario(string nombre,string descripcion);
	virtual string toString()= 0;
	DTUsuario();
	~DTUsuario();
protected:
	string nombre;
	string descripcion;
};

#endif