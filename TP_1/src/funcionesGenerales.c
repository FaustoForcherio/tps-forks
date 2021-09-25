/*
 * funcionesEntradaSalida.c
 *
 *  Created on: 5 sept 2021
 *      Author: Raffi
 */

#include "funcionesGenerales.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


/// @brief Se muestra un men� predeterminado de una calculadora, el cual consta de 4 variantes, que
/// 	se mostrar�n dependiendo de los par�metros ingresados.
///
/// @param Dato de tipo entero, representa un "flag" correspondiente a la primer opci�n del men�.
/// 	Cuando su estado es 0, el "primer operando" dentro del menu se muestra como "A=x".
/// 	Si su estado es 1, la "x" tomar� el valor num�rico que el usuario haya ingresado.
///
/// @param Dato de tipo entero, representa un "flag" flag correspondiente a la segunda opci�n del men�.
/// 	Cuando su estado es 0, el "segundo operando" dentro del menu se muestra como "B=y".
/// 	Si su estado es 1, la "y" tomar� el valor num�rico que el usuario haya ingresado.
///
/// @param Dato de tipo flotante que se usar� para mostrar el valor del primer operando "A".
/// @param Dato de tipo flotante que se usar� para mostrar el valor del segundo operando "B".
void MenuPrincipal(int banderaUno, int banderaDos, float numeroUno, float numeroDos) {

	if (banderaUno == 0 && banderaDos == 0) {

		printf ("1. Ingresar 1er operando (A=x)\n"
				"2. Ingresar 2do operando (B=y)\n"
				"3. Calcular todas las operaciones\n"
				"a) Calcular la suma (A+B)\n"
				"b) Calcular la resta (A-B)\n"
				"c) Calcular la division (A/B)\n"
				"d) Calcular la multiplicacion(A*B) \n"
				"e) Calcular el factorial (A!)\n"
				"4. Informar resultados\n"
				"5. Salir\n");

	} else if (banderaUno == 1 && banderaDos == 0) {

		printf ("1. Ingresar 1er operando (A=%.2f)\n"
					"2. Ingresar 2do operando (B=y)\n"
					"3. Calcular todas las operaciones\n"
					"a) Calcular la suma (A+B)\n"
					"b) Calcular la resta (A-B)\n"
					"c) Calcular la division (A/B)\n"
					"d) Calcular la multiplicacion (A*B)\n"
					"e) Calcular el factorial (A!)\n"
					"4. Informar resultados\n"
					"5. Salir\n", numeroUno);

	} else if (banderaUno == 0 && banderaDos == 1) {

		printf ("1. Ingresar 1er operando (A=x)\n"
				"2. Ingresar 2do operando (B=%.2f)\n"
				"3. Calcular todas las operaciones\n"
				"a) Calcular la suma (A+B)\n"
				"b) Calcular la resta (A-B)\n"
				"c) Calcular la division (A/B)\n"
				"d) Calcular la multiplicacion (A*B)\n"
				"e) Calcular el factorial (A!)\n"
				"4. Informar resultados\n"
				"5. Salir\n", numeroDos);
	} else {

		printf ("1. Ingresar 1er operando (A=%.2f)\n"
				"2. Ingresar 2do operando (B=%.2"
				"f)\n"
				"3. Calcular todas las operaciones\n"
				"a) Calcular la suma (A+B)\n"
				"b) Calcular la resta (A-B)\n"
				"c) Calcular la division (A/B)\n"
				"d) Calcular la multiplicacion (A*B)\n"
				"e) Calcular el factorial (A!)\n"
				"4. Informar resultados\n"
				"5. Salir\n", numeroUno, numeroDos);
	}
}

/// @brief Se verifica que un n�mero flotante tenga decimales o es un n�mero "redondo".
///
/// @param numeroIngresado El n�mero a evaluar.
/// @return Se retorna 1 si tiene decimales o 0 si es un n�mero "redondo".
int TieneDecimales(float numeroIngresado) {

	int numeroSinDecimales;
	int tieneDecimales;

	numeroSinDecimales = numeroIngresado;
	tieneDecimales = 1;

	numeroIngresado = numeroIngresado - numeroSinDecimales;

	if (numeroIngresado == 0) {
		tieneDecimales = 0;
	}

	return tieneDecimales;
}

/// @brief Se pide un n�mero de tipo entero acompa�ado de un mensaje,
/// 	verificando que no se ingresen otros caracteres.
///
/// @param mensaje El mensaje a mostrar al usuario.
/// @return Se retorna el n�mero que el usuario ingres�.
int PedirEntero (char mensaje[]) {
	char numeroAVerificar[15]; // el m�ximo de INT son 14 caracteres
	int numeroIngresado;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", numeroAVerificar);

	while (!VerificarInt(numeroAVerificar)) {
		printf("ERROR! No se ingres� un n�mero v�lido.\n%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", numeroAVerificar);
	}

	numeroIngresado = atoi(numeroAVerificar);

	return numeroIngresado;
}

/// @brief Se pide un n�mero de tipo flotante acompa�ado de un mensaje,
/// 	verificando que no se ingresen otros caracteres.
///
/// @param mensaje El mensaje a mostrar al usuario.
/// @return Se retorna el n�mero que el usuario ingres�.
float PedirFlotante (char mensaje[]) {
	char numeroAVerificar[100];
	float numeroIngresado;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", numeroAVerificar);

	while (!VerificarFloat(numeroAVerificar)) {
		printf("ERROR! No se ingres� un n�mero v�lido.\n%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", numeroAVerificar);
	}

	numeroIngresado = atof(numeroAVerificar);

	return numeroIngresado;

}

/// @brief Se verifica que la cadena de caracteres ingresada contenga
/// 	 caracteres que correspondan a un n�mero entero.
///
/// @param numeroAVerificar El n�mero a verificar.
/// @return Se retorna 1 si la cadena contiene caracteres que cumplen
/// 	con la condici�n, o se retorna 0 en el caso contrario.
int VerificarInt(char numeroAVerificar[]) {
	int esInt;
	int longitud;

	esInt = 1;
	longitud = strlen(numeroAVerificar);


	if (isdigit(numeroAVerificar[0]) || (numeroAVerificar[0] == '-' && longitud > 1)) {
		for(int i = 1; i < longitud; i++) {
				if (!isdigit(numeroAVerificar[i])) {
					esInt = 0;
					break;
				}
		}
	} else {
		esInt = 0;
	}

	return esInt;
}

/// @brief Se verifica que la cadena de caracteres ingresada contenga
/// 	caracteres que correspondan a un n�mero flotante.
///
/// @param numeroAVerificar El n�mero a verificar.
/// @return Se retorna 1 si la cadena contiene caracteres que cumplen con
/// 	la condici�n, o se retorna 0 en el caso contrario.
int VerificarFloat(char numeroAVerificar[]) {
	int esFloat;
	int contadorPuntos;
	int longitud;

	esFloat = 1;
	contadorPuntos = 0;
	longitud = strlen(numeroAVerificar);

	/*verificar que cadena empiece con n�mero o s�mbolo negativo. que el s�mbolo negativo tenga "algo" despu�s.
	si ese "algo" es un punto, que ese punto tenga "algo" despu�s tambi�n*/
	if (isdigit(numeroAVerificar[0]) || (numeroAVerificar[0] == '-' && ((numeroAVerificar[1] != '.' && longitud > 1) || (numeroAVerificar[1] == '.' && longitud > 2)))) {
			for (int i = 1; i < longitud; i++) {
				if (!isdigit(numeroAVerificar[i])) { // no es un n�mero
					if (numeroAVerificar[i] == '.') { // es un punto
						contadorPuntos++;
						if (contadorPuntos > 1) {
							esFloat = 0; // m�s de un punto = no es un float
							break;
						}
					} else {
						esFloat = 0; // no es n�mero ni punto = no es un float
						break;
					}
				}
			} // fin bucle for
		} else {
			esFloat = 0; // si no empieza como un n�mero o un negativo ni siquiera cicla
		}

	return esFloat;
}
