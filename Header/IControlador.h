/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   IControlador.h
 * Author: matia
 *
 * Created on 22 de mayo de 2024, 7:44 p.m.
 */

#ifndef ICONTROLADOR_H
#define ICONTROLADOR_H

#include <string>
#include <vector>
#include "Curso.h"
#include "Usuario.h"
#include "Profesor.h"
#include "Date.h"
using namespace std;

class IControlador: ICollectible {
private:
    
    
    
public:
    IControlador();
	~IControlador();
    
    virtual vector<string> listarCursosNoHabilitados() = 0;
    virtual void SeleccionarCurso(string nombreCurso) = 0;
    virtual void IngresarDatosLeccion(string tema, string objAprendizaje) = 0;
    virtual vector <string> listarIdiomasEspecializados()=0;
	virtual vector <string> listarProfesores()=0;
	virtual void ingresarDatosCurso(string nicknameP, string nombre, string descripcion, Dificultad dif)=0;
	virtual void buscarIdioma(string nombreIdioma)=0;
	virtual vector <string> listarCursosHabilitados()=0;
	virtual void buscarCursoPrevio(string nombreCursoPrev)=0;
	virtual bool AltaCurso()=0;
    virtual vector <string> listarUsuarios()=0;
    virtual DTUsuario* mostrarInfoUsuario(string nickname)=0;

    /* Operaciones de Agregar Leccion */
    virtual vector<string> listarCursosNoHabilitados() = 0;
    virtual void SeleccionarCurso(string nombreCurso) = 0;
    virtual void IngresarDatosLeccion(string tema, string objAprendizaje) = 0;
    virtual void IngresarLeccion(string tema, string objAprendizaje) = 0;
    virtual void agregateLeccion(DTLeccion* DTLec) = 0;
    virtual void AltaLeccion() = 0;
    
    /* Operaciones de Agregar Ejercicio */
    virtual void IngresarEjercicioCF(string tipoEjercicio, string nombreEjercicio, string descripcion, string fraseACompletar, vector<string> palabrasSolucion) = 0;
    virtual void IngresarEjercicioT(string tipoEjercicio, string nombreEjercicio, string descripcion, string fraseATraducir, string fraseTraducida) = 0;

    /* Operaciones de Eliminar Curso */
    virtual vector<string> ListarCursos() = 0;
    virtual void EliminarCurso(string nombreCurso) = 0;
    virtual vector <string> listarEstudiantes()=0;
	virtual vector <DTProgresoCurso*> ListarEstadisticasEstudiante(string nickname)=0;
	virtual vector <DTProgresoCurso*> ListarCursosPropuestosPor(string nickname)=0;
	virtual DTProgresoCurso* MostrarProgresoCurso(string nombreCurso)=0;
};

#endif /* ICONTROLADOR_H */

