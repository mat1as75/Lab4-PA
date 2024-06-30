#ifndef DTREALIZAT_H
#define DTREALIZAT_H
#include <string>
#include"DTRealizaEjercicio.h"
using namespace std;

class DTRealizaT: public DTRealizaEjercicio {
protected:
	string FraseATraducir;
public:
	DTRealizaT();
	DTRealizaT(const DTRealizaT& orig);
	DTRealizaT(string nombreT,string descEjercicio,string FraseATraducir );
	
	virtual ~DTRealizaT();
};
#endif
