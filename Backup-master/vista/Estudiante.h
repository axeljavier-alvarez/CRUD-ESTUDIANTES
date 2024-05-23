#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"

using namespace std;

class Estudiante : Persona {
private: int id = 0;
public:
	Estudiante() {}

	Estudiante(string codigo, string nom, string ape, string dir, int tel, string fn, int ts, int i) : 
		Persona(codigo, nom, ape, dir, tel, fn, ts) {
		id = i;

	}
	//SET
	void setId(int i) { id = i; }
	void setCodigo(string codigo) { codigo = codigo; }
	void setNombres(string nom) { nom = nom; }
	void setApellidos(string ape) { ape = ape; }
	void setDireccion(string dir) { dir = dir; }
	void setTelefono(int tel) { tel = tel; }
	void setFecha_Nacimiento(string fn) { fn = fn; }
	void setTipo_sangre(int ts) { ts = ts; }
	//GET
	int getId() { return id; }
	string getCodigo() { return codigo; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getFecha_Nacimiento() { return fecha_nacimiento; }
	int getTipo_sangre() { return tipo_sangre; }

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			cout << "---------------------------- Datos estudiantes ----------------------------" << endl;
			string consulta = "select * from estudiantes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado)
			{
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado))
				{
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << endl;
				}
			}
			else
			{
				cout << "Error al consultar..." << endl;
			}
		}
		else
		{
			cout << "Error en la conexion..." << endl;
		}
		cn.cerrar_conexion();
	}

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string t = to_string(telefono);
		string ts = to_string(tipo_sangre);
		if (cn.getConectar())
		{
			string insertar = "insert into estudiantes(codigo, nombres, apellidos, direccion, telefono, fecha_nacimiento,id_tipo_sangre) values('" + codigo + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + "'," + ts + ")";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado)
			{
				cout << "Ingreso exitoso..." << endl;
			}
			else
			{
				cout << "Error al ingresar..." << endl;
			}
		}
		else
		{
			cout << "Error en la conexion..." << endl;
		}
		cn.cerrar_conexion();
	}

	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string t = to_string(telefono);
		string ts = to_string(tipo_sangre);
		string ii = to_string(id);
		if (cn.getConectar()) {
			string actualizar = "update estudiantes set codigo='" + codigo + "', nombres='" + nombres + "', apellidos='" + apellidos + "',direccion='" + direccion + "',telefono=" + t + ",fecha_nacimiento='" + fecha_nacimiento + "',tipo_sangre=" + ts + " where id_estudiante =" + ii + "";
			const char* i = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado)
			{
				cout << "Actualizacion exitosa..." << endl;
			}
			else
			{
				cout << "Error al actualizar..." << endl;
			}
		}
		else {
			cout << "Error en la conexion..." << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string ii = to_string(id);
		if (cn.getConectar())
		{
			string borrar = "delete from estudiantes where id_estudiante = " + ii + "";
			const char* i = borrar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado)
			{
				cout << "Registro eliminado..." << endl;
			}
			else
			{
				cout << "Error al eliminar..." << endl;
			}
		}
		else
		{
			cout << "Error en la conexion..." << endl;
		}
		cn.cerrar_conexion();
	}
	
	

};

