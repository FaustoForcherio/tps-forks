/*
 * funciones_aritmeticas.c
 *
 *  Created on: 5 sept 2021
 *      Author: Raffi
 */

#include <stdio.h>

#include "funcionesGenerales.h"

/// @brief Se realiza la suma de 2 n�meros recibidos por par�metro.
/// 	El orden de los par�metros es matem�ticamente indistinto.
///
/// @param Primer n�mero a operar.
/// @param Segundo n�mero a operar.
/// @return Se retorna el resultado de la suma.
float SumarDosNumeros(float numeroUno, float numeroDos) {

	float suma;

	suma = numeroUno + numeroDos;

	return suma;
}

/// @brief Se realiza la resta de 2 n�meros recibidos por par�metro.
/// 	El primer par�metro resta al segundo.
///
/// @param Primer n�mero a operar.
/// @param Segundo n�mero a operar.
/// @return Se retorna el resultado de la resta.
float RestarDosNumeros(float numeroUno, float numeroDos) {

	float resta;

	resta = numeroUno - numeroDos;

	return resta;
}

/// @brief Se realiza la divisi�n de 2 n�meros recibidos por par�metro. El primer par�metro es divido sobre el segundo.
///
/// @param Primer n�mero a operar.
/// @param Segundo n�mero a operar.
/// @return Se retorna el resultado de la divisi�n.
/// 	Si alg�n par�metro ingresado es un 0, se retorna un 0.
/// Si ese 0 fuese el segundo par�metro, se deber�a controlar esa excepci�n matem�tica en otra parte del programa.
float DividirDosNumeros(float numeroUno, float numeroDos) {

	float division;

	division = 0;

	if(numeroUno != 0 && numeroDos !=0) {
		division = numeroUno / numeroDos;
	}

	return division;
}

/// @brief Se realiza la multiplicaci�n de 2 n�meros recibidos por par�metro.
/// 	El orden de los par�metros es matem�ticamente indistinto.
///
/// @param Primer n�mero a operar.
/// @param Segundo n�mero a operar.
/// @return Se retorna el resultado de la multiplicaci�n.
float MultiplicarDosNumeros(float numeroUno, float numeroDos) {

	float multiplicacion;

	multiplicacion = 0;

	if (numeroUno != 0 && numeroDos != 0) {
		multiplicacion = numeroUno * numeroDos;
	}

	return multiplicacion;
}

/// @brief Se realiza el factorial de un n�mero positivo, sin decimales.
/// En caso de no serlo, no se realiza la operaci�n.
///
/// @param N�mero a operar. Se verifica que cumpla las condiciones para realizar la operaci�n.
/// @return Se retorna el resultado del factorial. En caso de no haberse realizado,
/// 	 se retorna 0; un valor matem�ticamente "incoherente" como resultado de un factorial.
int FactorialUnNumero (float numeroIngresado) {

	int factorial; //acumuladorMultiplicaciones
	int i;

	factorial = 1;

	if (!TieneDecimales(numeroIngresado) && numeroIngresado > 1) {
		for (i = 1; i <= numeroIngresado; i++) {
			factorial = factorial * i;
		}
	} else {
		factorial = 0;
	}

	return factorial;
}

