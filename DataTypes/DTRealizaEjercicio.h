#ifndef DTREALIZAEJERCICIO_H
#define DTREALIZAEJERCICIO_H
#include <string>
using namespace std;

class DTRealizaEjercicio {
protected:
	string nombreEjercicio;
	string descEjercicio;
public:
	DTRealizaEjercicio();
	DTRealizaEjercicio(const DTRealizaEjercicio& orig);
	DTRealizaEjercicio(string nombreEjercicio,string descEjercicio);
	string getNombre();
	virtual ~DTRealizaEjercicio();
};

#endif
