#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"

using namespace std;

// AXEL ALVAREZ
// UNIVERSIDAD MARIANO GALVEZ

class Estudiante
{
private:
	string codigo, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono, idSangre, id = 0 ;

public:
	Estudiante() {

	}

	Estudiante(string cod, string nom, string ape, string dir, int tel, string fn, int i, int idSan) {
		codigo = cod;
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		fecha_nacimiento = fn;
		id = i;
		idSangre = idSan;
	}

	// metodos set
	void setId(int i) { id = i; }
	void setCodigo(string cod) { codigo = cod; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setFechaNacimiento(string fn) { fecha_nacimiento = fn; }
	void setIdSangre(int idSan) { idSangre = idSan; }

	// metodos get
	int getId() { return id; }
	string getCodigo() { return codigo;  }
	string getNombres() { return nombres;  }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getFechaNacimiento() { return fecha_nacimiento; }
	int getIdSangre() { return idSangre;  }

	// METODO LEER
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "------------ Datos de Clientes ------------" << endl;
			string consulta = "select * from estudiantes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << endl;
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

	// metodo para crear
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string tel = to_string(telefono);
			string idSan = to_string(idSangre);

			string insertar = "INSERT INTO estudiantes (codigo, nombres, apellidos, direccion, telefono, fecha_nacimiento, id_tipo_sangre) VALUES ('" + codigo + "', '" + nombres + "'," + apellidos + ",'" + direccion + "','" + tel + "'," + fecha_nacimiento + "," + idSan + "";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "--------- Ingreso exitoso ----------" << endl;
			}
			else {
				cout << "--------- Error al ingresar la informacion ----------" << endl;
			}
		}
		else {
			cout << "----------- Error de la conexion ----------" << endl;
		}
		cn.cerrar_conexion();
	}

	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string i = to_string(id);
		string tel = to_string(telefono);
		string idSan = to_string(idSangre);

		if (cn.getConectar()) {
			string  actualizar = "UPDATE estudiantes SET codigo = '" + codigo + "', nombres = '" + nombres + "', apellidos = '" + apellidos + "', direccion = '" + direccion + "', telefono = '" + tel + "', fecha_nacimiento = '" + fecha_nacimiento + "', id_tipo_sangre = '" + idSan + " WHERE id_estudiante = " + i + "";
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
			string  eliminar = "DELETE from estudiantes WHERE id_estudiante = " + i + "";
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

