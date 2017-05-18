/*
 * Banco.cpp
 *
 *  Created on: 15 de may. de 2017
 *      Author: Eneko
 */

#include "Banco.h"
#include "Cuenta.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Banco::Banco(char* nom, char* dir) {
	// TODO Auto-generated constructor stub
	this->nombre = nom;
	this->direccion = dir;
}

Banco::Banco() {
	// TODO Auto-generated destructor stub
}

Banco::~Banco() {
	// TODO Auto-generated destructor stub
}


void Banco::anadirCuenta(Cuenta * CuentasB, float liq, int cli) {

	Cuenta c;//(555, "Pedro Aguado", (c.numCuentas+1), cli);
	c.setLiquidacion(liq);
	c.setNombre("Halo");
	CuentasB[CuentasB->getNumeroCuentas()] = c;
	cout << "Exito\n";
}

void Banco::buscarCuenta(Cuenta * CuentasB, int cli) {

	int i = 0, enc = 0;
	while (enc == 0 && i < CuentasB->getNumeroCuentas()) {
		if (CuentasB[CuentasB->getNumeroCuentas()].getNumeroId() == cli) {
			enc = 1; // en C no existen boolean, por lo tanto cuando queramos usar lo que en java correspondería a un boolean usaremos un int, la similitud sería 1 = true y 0 = false.
		} else {
			i++;
		}
	}
	if (enc == 1) {
		//printf("El cliente %i tiene un total de %i€ en su cuenta\n\n",
		//		CuentasB[i].nombre, CuentasB[i].liq);
		cout << "El cliente %i tiene un total de %i€ en su cuenta\n\n"
				<< CuentasB[i].getNombre() << CuentasB[i].getLiquidacion();

	} else {
		//printf("El cliente %i no existe\n\n", cli);
		cout << "El cliente %i no existe\n\n" << cli;
	}
}

Cuenta Banco::buscarCuenta1(Cuenta * CuentasB, int cli) {

	int i = 0, enc = 0;
	while (enc == 0 && i < CuentasB->getNumeroCuentas()) {
		if (CuentasB[i].getNumeroId() == cli) {
			enc = 1;
		} else {
			i++;
		}
	}
	return CuentasB[i];
}

void Banco::actualizarCuenta(Cuenta * CuentasB, int cli, Cuenta c) {

	int i = 0, enc = 0;
	while (enc == 0 && i < CuentasB->getNumeroCuentas()) {
		if (CuentasB[i].getNumeroId() == cli) {
			enc = 1;
			CuentasB[i] = c;
		}
	}
}

int Banco::existeCuenta(Cuenta * CuentasB, int cli) {

	int i = 0, enc = 0;
	while (enc == 0 && i < CuentasB->getNumeroCuentas()) {
		if (CuentasB[i].getNumeroId() == cli) {
			enc = 1;
		} else {
			i++;
		}
	}
	return enc;
}

void Banco::eliminarCuenta1(Cuenta * CuentasB, int cli) { //funciona
	int i = 0, enc = 0;
	while (enc == 0 && i < CuentasB->getNumeroCuentas()) {
		if (CuentasB[i].getNumeroId() == cli) {
			enc = 1; // en C no existen boolean, por lo tanto cuando queramos usar lo que en java correspondería a un boolean usaremos un int, la similitud sería 1 = true y 0 = false.
		} else {
			i++;
		}
	}
	if (enc == 1) {
		while (i < CuentasB->getNumeroCuentas()) {
			CuentasB[i] = CuentasB[i + 1];
			i++;
		}
		//printf("eliminado\n\n");
		cout << "Eliminado\n";
		CuentasB->setNumeroCuentas(CuentasB->getNumeroCuentas() - 1);
	} else {
		//printf("no encontrado\n\n");
		cout << "No encontrado\n";

	}

}
void Banco::transaccion(Cuenta * CuentasB, int cliA, int cliB, int cant) {

	int i = 0, j = 0;
	int t = 0, t1 = 0;
	while (i < CuentasB->getNumeroCuentas() && t == 0) {
		if (CuentasB[i].getNumeroId() == cliA) {
			t = 1;
		} else {
			i++;
		}
	}

	while (j < CuentasB->getNumeroCuentas() && t1 == 0) {
		if (CuentasB[i].getNumeroId() == cliB) {
			t1 = 1;
		} else {
			j++;
		}
	}
	if (t == 0 || t1 == 0) {
		//printf("No se han encontrado los clientes %i o %i\n", cliA, cliB);
		cout << "No se han encontrado los clientes %i o %i\n" << cliA << cliB;
	} else {
		CuentasB[j].setLiquidacion(CuentasB[j].getLiquidacion() + cant);
		CuentasB[i].setLiquidacion(CuentasB[i].getLiquidacion() - cant);
		//printf("Exito\n\n");
		cout << "Exito\n";
	}
}

void Banco::LeerFichero() {
	cout << "Escriba el nombre del archivo a leer: " << endl;
	string filename;
//	char *str;
//	int i;
	cin >> filename;
	ifstream file(filename.c_str());
	if (!file) {
		cout << "Error no se puede abrir el archivo: " << filename << endl;
	}
	string linea, archivo;

//    for(i=0; str[i]!=' ' && str[i] == '_';i++){
//		archivo += linea + "\n";
//    }

	while (getline(file, linea))		archivo += linea + "\n";
	cout << archivo;


}
