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
#include "../ICo.h"
using namespace std;

class IControlador {

private:
    
    
    
public:
    IControlador();
	~IControlador();

    virtual IDictionary* getCursosNoHabilitados() = 0;
    virtual IDictionary* getCursosHabilitados() = 0;
    virtual IDictionary* getEstudiantes() = 0;
    virtual IDictionary* getProfesores() = 0;
    virtual IDictionary* getIdiomas() = 0;
    virtual IDictionary* getIdiomasAuxiliares() = 0;
    
    /*Operaciones Alta Usuario*/
    virtual void ingresarDatosEstudiante(string nickname, string contrasena, string nombre, string descripcion, string paisRes, Date* fecNac)=0;
	virtual void ingresarDatosProfesor(string nickname, string contrasena, string nombre, string descripcion, string instituto)=0;
    virtual vector <string>listarIdiomasDisponibles()=0;
    virtual void ingresarIdiomaEspecializado(string nombreIdioma)=0;
    virtual bool altaUsuario()=0;
    virtual bool ingresarIdioma(string idioma)=0;

    /*Operaciones de Consultar Usuario*/
    virtual vector <string> listarUsuarios()=0;
    virtual DTUsuario* mostrarInfoUsuario(string nickname)=0;
    

    /*Operaciones de Alta Curso*/
    virtual vector <string> listarIdiomasEspecializados()=0;
    virtual vector <string> listarProfesores()=0;
    virtual void ingresarDatosCurso(string nicknameP, string nombre, string descripcion, Dificultad dif)=0;
    virtual void buscarIdioma(string nombreIdioma)=0;
    virtual vector <string> listarCursosHabilitados()=0;
    virtual void buscarCursoPrevio(string nombreCursoPrev)=0;
    virtual void IngresarLeccion(string tema, string objAprendizaje)=0;
    virtual bool AltaCurso()=0;

    
    /* Operaciones de Agregar Leccion */
    virtual vector<string> listarCursosNoHabilitados() = 0;
    virtual void SeleccionarCurso(string nombreCurso) = 0;
    virtual void IngresarDatosLeccion(string tema, string objAprendizaje) = 0;
    virtual void AltaLeccion() = 0;
    
    /* Operaciones de Agregar Ejercicio */
    virtual void seleccionarLeccion(string leccion) = 0;
    virtual vector<string> listarLecciones(string nomCurso) = 0;
    virtual void IngresarEjercicioCF(string tipoEjercicio, string nombreEjercicio, string descripcion, string fraseACompletar, vector<string> palabrasSolucion) = 0;
    virtual void IngresarEjercicioT(string tipoEjercicio, string nombreEjercicio, string descripcion, string fraseATraducir, string fraseTraducida) = 0;

    /* Operaciones de Eliminar Curso */
    virtual vector<string> ListarCursos() = 0;
    virtual void EliminarCurso(string nombreCurso) = 0;


    /*Operaciones de Consultar estadisticas*/
    virtual vector <string> listarEstudiantes() = 0;
	virtual vector <DTProgresoCurso*> ListarEstadisticasEstudiante(string nickname) = 0;
	virtual vector <DTProgresoCurso*> ListarCursosPropuestosPor(string nickname) = 0;
	virtual DTProgresoCurso* MostrarProgresoCurso(string nombreCurso) = 0;


    /*Operaciones de consultar curso*/
    virtual  vector <string> listarCursos() = 0;
    virtual DTInfoCurso* mostrarInfoCurso(string nombreCurso) = 0;


    /*Operaciones de Habilitar curso*/
    virtual bool cursoPerteneceNoHab(string nomCurso)=0;
    virtual bool habilitaCurso(string nomCurso)=0;

    /*Operaciones de Inscribirse a curso*/
    virtual vector <string> listarEstudiantes()=0;
    virtual bool estudiantePertenece(string estudiante)=0;
    virtual vector<DTCurso*> listarCursosHabilitadoEtudiante(string estudiante)=0;
    virtual void inscripcionCurso(string nomC)=0;

    /*Operaciones de Realizar Ejercicio*/
    virtual vector <string> listarCursosInscripto(string nomE)=0;
    virtual vector<DTRealizaEjercicio*> mostrarEjercicios(string curso)=0;
    virtual vector<string> obtenerSolucionEjercicio(string ejARealizar,string curso)=0;
    virtual bool apruebaEjercicio(string solucionUsuario,string solucionEjercicio, string nomCurso)=0;




};

#endif /* ICONTROLADOR_H */

