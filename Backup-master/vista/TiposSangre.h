#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
// AXEL ALVAREZ

using namespace std;


class TiposSangre
{

private: string tipoSangre;

	   int id = 0;

public:
	TiposSangre() {

	}

	TiposSangre(string tsangre, int i) {
		tipoSangre = tsangre;
		id = i;
	}

	// METODOS SET
	void setId(int i) { id = i; }

	void setTipoSangre(string tsangre) { tipoSangre = tsangre; }

	// METODOS GET
	int getId() { return id; }
	string getTipoSangre() { return tipoSangre; }


	// METODO LEER
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "------------ Datos de Clientes ------------" << endl;
			string consulta = "select * from tipos_sangre";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();


		cn.abrir_conexion();

		if (cn.getConectar()) {
			string  insertar = "INSERT INTO tipos_sangre(tipo_sangre) VALUES ('" + tipoSangre + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string i = to_string(id);

		if (cn.getConectar()) {
			string  actualizar = "UPDATE tipos_sangre SET tipo_sangre = '" + tipoSangre + "'WHERE id_tipo_sangre = " + i + "";
			const char* i = actualizar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Actualizacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string i = to_string(id);

		if (cn.getConectar()) {
			string  eliminar = "DELETE from tipos_sangre WHERE id_tipo_sangre = " + i + "";
			const char* i = eliminar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Se elimino Exitosamente ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
};

