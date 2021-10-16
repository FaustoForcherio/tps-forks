/*
 * Employee.h
 *
 *  Created on: 4 oct 2021
 *      Author: Raffi
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include "Input.h"

#define TRUE 1
#define FALSE 0

struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
} typedef Employee;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee list[], int len);

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
**/
int addEmployee(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector);

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
**/
int findEmployeeById(Employee list[], int len, int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee list[], int len, int order);

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int len);

/// @brief Muestra el men� principal del programa. Gestiona las opciones que elige el usuario dentro de �l.
///
/// @param list
/// @param len
/// @param contadorDeID
/// @return Retorna (-1) si hay error [Tama�o inv�lido o puntero a NULL] - (0) si est� bien
int MostrarMenuPrincipal(Employee list[], int len, int *contadorDeID);

/// @brief Pregunta al usuario qu� empleado de la lista quiere modificar y lo lleva al men� de edici�n correspondiente.
///
/// @param list
/// @param len
/// @return Retorna (-1) si hay error [Tama�o inv�lido o puntero a NULL] - (0) si est� bien
int EditEmployee(Employee list[], int len);

/// @brief Pregunta los datos del nuevo empleado a a�adir y luego lo a�ade. Se encarga del incremento del contador de ID.
///
/// @param list
/// @param len
/// @param idPrincipal
/// @return Retorna (-1) si hay error [Tama�o inv�lido o puntero a NULL] - (0) si est� bien
int AltaEmployee(Employee list[], int len, int *idPrincipal);

/// @brief Pregunta el ID del empleado a remover y luego lo remueve.
///
/// @param list
/// @param len
/// @return Retorna (-1) si hay error [Tama�o inv�lido o puntero a NULL] - (0) si est� bien
int BajaEmployee(Employee list[], int len);

/// @brief Informa al usuario la suma total de todos los salarios, el promedio de los mismos y cu�ntos empleados superan ese promedio.
///
/// @param list
/// @param len
/// @return Retorna (-1) si hay error [Tama�o inv�lido o puntero a NULL] - (0) si est� bien
int InformarSalarios(Employee list[], int len);

/// @brief Realiza el c�lculo de la suma total de los salarios de cada empleado y tambi�n los promedia.
///
/// @param list
/// @param len
/// @param totalSalarios
/// @param promedioSalarios
/// @return Retorna (-1) si hay error [Tama�o inv�lido o puntero a NULL] - (0) si est� bien
int PromediarSalarios(Employee list[], int len, float *totalSalarios, float *promedioSalarios);

/// @brief Muestra un sub men� de la secci�n de informes, solamente si hay empleados cargados para realizar las acciones correspondientes.
///
/// @param list
/// @param len
/// @return Retorna (-1) si hay error [Tama�o inv�lido o puntero a NULL] - (0) si est� bien
int MostrarSubMenuInformes (Employee list[], int len);

/// @brief Muestra un sub men� donde se lleva a cabo la modificaci�n del empleado.
///
/// @param list
/// @param len
/// @param posicionAEditar
/// @return Retorna (-1) si hay error [Tama�o inv�lido o puntero a NULL] - (0) si est� bien
int MostrarSubMenuEdit (Employee list[], int len, int posicionAEditar);

/// @brief Busca una posici�n libre en el array de la lista de empleados.
///
/// @param list
/// @param len
/// @return Retorna (-1) si no hay un lugar libre o si hay error [Tama�o inv�lido o puntero a NULL] - (posici�n libre) si hay lugar
int BuscarEspacioLibre(Employee list[], int len);

/// @brief Busca y verifica que exista una posici�n cargada en el array de la lista de empleados.
///
/// @param list
/// @param len
/// @return Retorna (0) si no hay empleados cargados - (1) si existen.
int VerificarArrayCargado(Employee list[], int len);

/// @brief Imprime un empleado con sus datos de ID, Nombre, Apellido, Salario y Sector.
///
/// @param employee
void PrintEmployeeIndividual(Employee employee);

/// @brief Funci�n para testing. A�ade autom�ticamente empleados a la lista sin la necesidad de usar funciones intermedias.
///
/// @param lista
/// @param tam
void HardcodearEmpleados (Employee lista[], int tam);



#endif /* ARRAYEMPLOYEES_H_ */
