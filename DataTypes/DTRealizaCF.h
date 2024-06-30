#ifndef DTREALIZACF_H
#define DTREALIZACF_H
#include <string>
#include "DTRealizaEjercicio.h"
using namespace std;

class DTRealizaCF : public DTRealizaEjercicio {
protected:
	string FraseIncompleta;
public:
	DTRealizaCF();
	DTRealizaCF(const DTRealizaCF& orig);
	DTRealizaCF(string nombreEjercicio,string descEjercicio,string FraseIncompleta);
	
	virtual ~DTRealizaCF();
};
#endif
