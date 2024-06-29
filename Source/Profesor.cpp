/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Profesor.h"
#include "DataTypes/DTProgresoCurso.h"

Profesor::Profesor(){
}

Profesor::~Profesor() {
}

Profesor::Profesor(string nickname, string password, string nombreUsuario, string descripcionUsuario, string instituto) {
	this->nickname = nickname;
	this->password = password;
	this->nombreUsuario = nombreUsuario;
	this->descripcionUsuario = descripcionUsuario;
	this->instituto = instituto;
	this->idiomasEspecializado = new OrderedDictionary();
}

string Profesor::getInstituto() {
	return this->instituto;
}

string Profesor::toString() {
	return "Profesor: " + this->nickname + ", " + this->nombreUsuario  + ", " + this->instituto;
}

void Profesor::EliminarCurso(Curso* c) {
    /* remove(c) */
    this->misCursos->remove((ICollectible*) c);
}

IDictionary* Profesor::getIdiomasEspecializado(){
	return this->idiomasEspecializado;
}

DTUsuario* Profesor::getInfo(){
	DTUsuario* dataP= new DTProfesor(this->getNombreU(),this->getDescripcionU(),this->getInstituto(),this->getIdiomasEspecializado());
	return dataP;
}
void Profesor::setIdiomasEspecializado(IKey* key, ICollectible* collect){
	
	this->idiomasEspecializado->add(key,collect);
	cout<<"ldssd"<<endl;
}
void Profesor::setIdiomasEspecializado(IDictionary* idiomas){
	this->idiomasEspecializado=idiomas;
}

vector<DTProgresoCurso*> Profesor::obtenerEstadisticasCursos(){
	vector<DTProgresoCurso*> DTProgresos;
	IIterator* it= this->misCursos->getIterator(); 
	while(it->hasCurrent()){ 
		DTProgresoCurso* DTProg;
		Curso* aux=(Curso*)it->getCurrent(); 
		DTProg = aux->obtenerEstadisticasCursos();
		DTProgresos.push_back(DTProg);
		it->next();
	}
	return DTProgresos;
}
