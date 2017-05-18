/*
 * Banco.h
 *
 *  Created on: 15 de may. de 2017
 *      Author: Eneko
 */

#ifndef BANCO_H_
#define BANCO_H_
#include "Cuenta.h"

class Banco {
//
private:

	char *nombre;
	char* direccion;

public:

	Banco(char* nom, char* dir);
	Banco();
	virtual ~Banco();
	void anadirCuenta(Cuenta * CuentasB, float liq, int cli);
	void transaccion(Cuenta * CuentasB, int cliA, int cliB, int cant);
	void eliminarCuenta1(Cuenta * CuentasB, int cli);
	void buscarCuenta(Cuenta * CuentasB, int cli);
	int existeCuenta(Cuenta * CuentasB, int cli);
	Cuenta buscarCuenta1(Cuenta * CuentasB, int cli);
	void actualizarCuenta(Cuenta * CuentasB, int cli, Cuenta c);
	void LeerFichero();
};

#endif /* BANCO_H_ */
