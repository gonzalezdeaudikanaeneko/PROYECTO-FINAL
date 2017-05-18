/*
 * Cuenta.h
 *
 *  Created on: 15 de may. de 2017
 *      Author: Unai Jauregibeitia
 */

#ifndef CUENTA_H_
#define CUENTA_H_

class Cuenta {
private:

	int nIdent;
	char *nombre;
	int ID_Cuenta;
	float liq;
	char *contrasena;

public:

	Cuenta(const int nIdent, const char *nombre, int ID_Cuenta,char* cont);
	Cuenta(const Cuenta &c);
	Cuenta();
	virtual ~Cuenta();
	int getNumeroId();
	float getLiquidacion();
	char* getNombre();
	char* getContrasena();

	void setNumeroId(int a);
	void setLiquidacion(float a);
	void setNombre(char* a);
	void setContrasena(char* a);

};

#endif /* CUENTA_H_ */
