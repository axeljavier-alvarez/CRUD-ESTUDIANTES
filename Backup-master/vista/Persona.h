#pragma once
#include <iostream>
using namespace std;

class Persona
{
protected: string codigo, nombres, apellidos, direccion, fecha_nacimiento;
		 int telefono = 0, tipo_sangre = 0;

protected:
	Persona() {
	}
	Persona(string codigo, string nom, string ape, string dir, int tel, string fn, int ts) {
		codigo = codigo;
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		fecha_nacimiento = fn;
		tipo_sangre = ts;
	}
};