#pragma once
#include <mysql.h>
#include <iostream>

using namespace std;

// AXEL JAVIER ALVAREZ
// TRABAJO CRUD
class ConexionBD
{

private: MYSQL* conectar;
public:
	// abrimos
	void abrir_conexion() {
		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "root", "admin1234", "db_estudiantes", 3306, NULL, 0);
	}
	// conectamos
	MYSQL* getConectar() {
		return conectar;
	}

	// cerramos
	void cerrar_conexion() {
		mysql_close(conectar);
	}
};

