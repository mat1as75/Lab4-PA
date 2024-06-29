/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Controlador.h
 * Author: matia
 *
 * Created on 22 de mayo de 2024, 7:28 p.m.
 */

#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <string>
#include <vector>
#include "../ICollection/interfaces/IDictionary.h"
#include "IControlador.h"
#include "Curso.h" /* Dependencia en Diagrama de Clases */
#include "Usuario.h" /* Dependencia en Diagrama de Clases */
#include "Idioma.h" /* Dependencia en Diagrama de Clases */
#include "Date.h"
#include "DataTypes/DTLeccion.h"
#include "DataTypes/DTCurso.h"
#include "DataTypes/DTProgresoCurso.h"
using namespace std;

class Controlador: public IControlador {
protected:
    Controlador(); // 1 de Singleton
    static Controlador* miInstancia; // 2 de Singleton
    IDictionary* CursosNoHabilitados;
    IDictionary* CursosHabilitados;
    IDictionary* Estudiantes;
    IDictionary* Profesores;
    IDictionary* Idiomas;
    IDictionary* auxCursosPrev;//la coleccion de cursos previos para cuando quiero crear un curso
    Profesor* auxProfDeCurso;//auxiliar con el profesor del curso que quiero probar
	Idioma* auxIdiomaDeCurso;//auxiliar con el idioma del curso por crear
    Curso* auxCurso; // Puntero auxiliar al curso para la oper SelecionarCurso()
    DTLeccion* auxDTLeccion; // Datatype Leccion auxiliar
    DTCurso* cursoACrear; //auxiliar con los datos del curso a crear   
    ICollection* auxDTEjercicios; // Coleccion Datatype Ejecicio auxiliar
    string nickname,contrasena,nombre,descripcion,paisRes,instituto; //auxiliares para alta usuario
    Date* fecNac;
    IDictionary* misIdiomasAuxiliares;// coleccion auxiliar de idiomas para crear profesor
public:
    static Controlador* getInstance(); // 3 de Singleton
    virtual ~Controlador();

    /* Getters de IDictionarys */
    IDictionary* getCursosNoHabilitados();
    IDictionary* getCursosHabilitados();
    IDictionary* getEstudiantes();
    IDictionary* getProfesores();
    IDictionary* getIdiomas();

    
    //Usuario* ingresarEstudiante(string nicknameEstudiante, string passEstudiante, string nombreEstudiante, string descEstudiante, string paisResEstudiante, Date* fecNacEstudiante) override;
    //Usuario* ingresarProfesor(string nicknameProfesor, string passProfesor, string nombreProfesor, string descProfesor, string institutoProfesor) override;
    
    /* Recibe sets de Usuarios y hacer el alta 
        de dicho usuario en el sistema
            (haciendo los links)*/
    

    /* Alta Usuario*/

    void ingresarDatosEstudiante(string nickname, string contrasena, string nombre, string descripcion, string paisRes, Date* fecNac);
	void ingresarDatosProfesor(string nickname, string contrasena, string nombre, string descripcion, string instituto);
    vector <string>listarIdiomasDisponibles();
    void ingresarIdiomaEspecializado(string nombreIdioma);
    bool altaUsuario();

    bool ingresarIdioma(string idioma);
    /* Agregar Leccion */
    vector<string> listarCursosNoHabilitados();
    void SeleccionarCurso(string nombreCurso);
    void IngresarDatosLeccion(string tema, string objAprendizaje);
   // void AltaLeccion();

    /*Consulta Usuario*/

    vector <string> listarUsuarios();
    DTUsuario* mostrarInfoUsuario(string nickname);
    
    /*Alta Curso*/
    vector <string> listarIdiomasEspecializados();
	vector <string> listarProfesores();
	void ingresarDatosCurso(string nicknameP, string nombre, string descripcion, Dificultad dif);
	void buscarIdioma(string nombreIdioma);
	vector <string> listarCursosHabilitados();
	void buscarCursoPrevio(string nombreCursoPrev);
	bool AltaCurso();

    /*Consultar Estadisticas*/
    vector <string> listarEstudiantes();
	vector <DTProgresoCurso*> ListarEstadisticasEstudiante(string nickname);
	vector <DTProgresoCurso*> ListarCursosPropuestosPor(string nickname);
	DTProgresoCurso* MostrarProgresoCurso(string nombreCurso);
};

#endif /* CONTROLADOR_H */

