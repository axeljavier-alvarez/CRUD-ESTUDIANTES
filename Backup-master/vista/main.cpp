#include <mysql.h>
#include <string>

#include <iostream>
#include "TiposSangre.h"
#include "Estudiante.h"

using namespace std;

// ESTUDIANTE: AXEL ALVAREZ
// UNIVERSIDAD MARIANO GALVEZ
// nuevo codigo para crear
// int q_estado;

int main() {
	void menuTiposSangre();
	void menuEstudiantes();

	int opcion;
	bool repetir = true;

	do {
		cout << "\n\n\t\t\tMenu de Opciones" << endl;
		cout << "\t\t\t----------------" << endl;
		cout << "\n\t1. CRUD TIPOS DE SANGRE" << endl;
		cout << "\n\t2. CRUD ESTUDIANTES " << endl;
		cout << "\n\t0. SALIR" << endl;

		cout << "\n\tIngrese una opcion: ";
		cin >> opcion;


		switch (opcion) {
		case 1:
			menuTiposSangre();
			break;
		case 2:
			menuEstudiantes();
			break;

		case 0:
			repetir = false;
			break;
		}

	} while (repetir);

	return 0;
}

/*  PRIMER MENU DE TIPOS DE SANGRE */
void menuTiposSangre() {

	void leerDatosSangre();
	void crearDatosSangre();
	void actualizarDatosSangre();
	void eliminarDatosSangre();

	int opcion;
	bool repetir = true;

	do {
		cout << "\n\n\t\t\tMENU DEL CLIENTE" << endl;
		cout << "\t\t\t----------------" << endl;
		cout << "\n\t1. LEER DATOS" << endl;
		cout << "\n\t2. CREAR DATOS" << endl;
		cout << "\n\t3. ACTUALIZAR DATOS" << endl;
		cout << "\n\t4. ELIMINAR DATOS" << endl;

		cout << "\n\t0. SALIR" << endl;

		cout << "\n\tIngrese una opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			leerDatosSangre();
			break;
			break;
		case 2:
			crearDatosSangre();
			break;
		case 3:
			actualizarDatosSangre();
			break;
		case 4:
			eliminarDatosSangre();
			break;

		case 0:
			repetir = false;
			break;
		}

	} while (repetir);
}

void leerDatosSangre() {
	TiposSangre t = TiposSangre();
	t.leer();
}


void crearDatosSangre() {
	string tipoSangre;
	int id = 0;
	cin.ignore();
	cout << "Ingrese el tipo de sangre: ";
	getline(cin, tipoSangre);


	TiposSangre c = TiposSangre(tipoSangre, id);

	c.crear();
	c.leer();
}

void actualizarDatosSangre() {



	TiposSangre t = TiposSangre();
	t.leer();

	string tipoSangre;
	int id = 0;

	cout << "Ingrese ID: ";
	cin >> id;
	cin.ignore();
	cout << "Ingrese el tipo de sangre: ";
	getline(cin, tipoSangre);


	// preguntar sobre este orden, se determina en el constructor de clientes?
	t = TiposSangre(tipoSangre, id);


	t.actualizar();

	// OPCION PARA LEER PALABRAS, CASE 2
	t.leer();

}

void eliminarDatosSangre() {

	TiposSangre t = TiposSangre();
	t.leer();

	string tipoSangre;
	int id = 0;




	// PARTE PARA ELIMINAR
	cout << "Ingrese ID: ";
	cin >> id;
	t.setId(id);
	t.eliminar();

	t.leer();
}

/* MENU ESTUDIANTES */

void menuEstudiantes() {

	void leerDatosEstudiantes();
	void crearDatosEstudiantes();
	void actualizarDatosEstudiantes();
	void eliminarDatosEstudiantes();

	int opcion;
	bool repetir = true;

	do {
		cout << "\n\n\t\t\tMENU DEL CLIENTE" << endl;
		cout << "\t\t\t----------------" << endl;
		cout << "\n\t1. LEER DATOS CLIENTE" << endl;
		cout << "\n\t2. CREAR DATOS" << endl;
		cout << "\n\t3. ACTUALIZAR DATOS" << endl;
		cout << "\n\t4. ELIMINAR DATOS" << endl;

		cout << "\n\t0. SALIR" << endl;

		cout << "\n\tIngrese una opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			leerDatosEstudiantes();
			break;
			break;
		case 2:
			crearDatosEstudiantes();
			break;
		case 3:
		    actualizarDatosEstudiantes();
			break;
		case 4:
			eliminarDatosEstudiantes();
			break;

		case 0:
			repetir = false;
			break;
		}

	} while (repetir);
}

void leerDatosEstudiantes() {
	Estudiante e = Estudiante();
	e.leer();
}

void crearDatosEstudiantes() {
	string codigo, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono = 0, id_tipo_sangre = 0, id = 0;

	cin.ignore();
	cout << "Ingrese el codigo del estudiante: ";
	getline(cin, codigo);

	cout << "Ingrese los nombres del estudiante: ";
	getline(cin, nombres);

	cout << "Ingrese los apellidos del estudiante: ";
	getline(cin, apellidos);

	cout << "Ingrese la direccion del estudiante: ";
	getline(cin, direccion);

	cout << "Ingresa el telefono del estudiante: ";
	cin >> telefono;


	cin.ignore();

	cout << "Ingrese la fecha de nacimiento del estudiante: ";
	getline(cin, fecha_nacimiento);

	

	cout << "Ingresa el id_tipo_sangre del estudiante: ";
	cin >> id_tipo_sangre;

	Estudiante e = Estudiante(codigo, nombres, apellidos, direccion, telefono, fecha_nacimiento, id_tipo_sangre, id);
	e.crear();
	e.leer();
}

void actualizarDatosEstudiantes() {
	Estudiante e = Estudiante();
	e.leer();

	string codigo, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono = 0, id_tipo_sangre = 0, id = 0;

	cout << "Ingrese ID: ";
	cin >> id;
	cin.ignore();
	cout << "Ingrese el codigo del estudiante: ";
	getline(cin, codigo);

	cout << "Ingrese los nombres del estudiante: ";
	getline(cin, nombres);

	cout << "Ingrese los apellidos del estudiante: ";
	getline(cin, apellidos);

	cout << "Ingrese la direccion del estudiante: ";
	getline(cin, direccion);

	cout << "Ingresa el telefono del estudiante: ";
	cin >> telefono;


	cin.ignore();

	cout << "Ingrese la fecha de nacimiento del estudiante: ";
	getline(cin, fecha_nacimiento);



	cout << "Ingresa el id_tipo_sangre del estudiante: ";
	cin >> id_tipo_sangre;

	e = Estudiante(codigo, nombres, apellidos, direccion, telefono, fecha_nacimiento, id_tipo_sangre, id);
	e.actualizar();
	e.leer();
}

void eliminarDatosEstudiantes() {
	Estudiante e = Estudiante();
	e.leer();

	string codigo, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono, idSangre, id = 0;




	// PARTE PARA ELIMINAR
	cout << "Ingrese ID: ";
	cin >> id;
	e.setId(id);
	e.eliminar();

	e.leer();
}