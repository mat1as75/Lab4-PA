#ifndef DTProgresoCurso_H
#define DTProgresoCurso_H
#include <string>
using namespace std;

class DTProgresoCurso {
public:
	DTProgresoCurso(string nombreCurso, float progresoCurso);
	DTProgresoCurso();
	~DTProgresoCurso();
private:	
	string nombreCurso;
	float progresoCurso;
};

#endif

