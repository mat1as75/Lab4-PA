#ifndef DTProgresoCurso_H
#define DTProgresoCurso_H
#include <string>
using namespace std;

class DATA_PROGRESO_CURSO {
public:
	DATA_PROGRESO_CURSO(string nombreCurso, float progresoCurso);
	DATA_PROGRESO_CURSO();
	~DATA_PROGRESO_CURSO();
private:	
	string nombreCurso;
	float progresoCurso;
};

#endif

