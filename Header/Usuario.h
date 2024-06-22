/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Usuario.h
 * Author: matia
 *
 * Created on 22 de mayo de 2024, 5:35 p.m.
 */

#ifndef USUARIO_H
#define USUARIO_H


#include <string>
#include <vector>
#include "../ICollection/interfaces/ICollectible.h"


using namespace std;

class Usuario: public ICollectible {
protected:
	string nickname;
	string password;
	string nombreUsuario;
	string descripcionUsuario;
public:
	Usuario();
	~Usuario();
	Usuario(string nickname, string password, string nombreUsuario, string descripcionUsuario);
	string getNickname();
	string getNombreU();
	string getDescripcionU();
	virtual string toString() = 0;
};

#endif /* USUARIO_H */

