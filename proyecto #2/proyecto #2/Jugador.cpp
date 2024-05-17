#include "Jugador.h"
#include <iostream>
#include <string>
using namespace std;
void Jugador::add(string domino) {
	Nodo* auxiliar = new Nodo();
	auxiliar->domino = domino;
	if (Head == NULL) {//Caso en el que no hay elementos en la lista

		auxiliar->next = NULL;
	}
	else//caso 2, cuando hay un dato en la lista
	{
		
		auxiliar->next = Head;
		
	}
	Head= auxiliar;
}
void Jugador::remove(string domino) {
	if (Head == NULL) {
		cout << "No tiene mas dominios dispobibles\n";
	}
	Nodo* aux1 = new Nodo;
	aux1 = Head;
	Nodo* aux2 = new Nodo;
	while (aux1->domino != domino && aux1->next != NULL)
	{
		aux2 = aux1;
		aux1 = aux1->next;
		//avanza para encontrar el domino
	}
	if (aux1->domino == domino) {//si es la cabeza
		Nodo* temporal = aux1;
		if (Head == aux1) {
			Head = Head->next;
		}
		else// si otro nodo
		{
			aux2->next = aux1->next;
		}
		cout << "Se ha eliminado: " << temporal->domino << endl;
		delete temporal;
	}

}
void Jugador::imprimir() {
	Nodo* Actual = Head;
	//Funcion para imprimir los dominos del jugador.
	if (Actual == NULL)
	{
		cout << "\n";
	}
	else
	{
		cout << "Sus dominos son: \n";
		while (Actual != NULL)
		{
			cout << Actual->domino<<" -> ";
			Actual = Actual->next;
		}
		cout << "||\n";
	}
}
string Jugador::buscar_doble() {
	Nodo* buscar = Head;
	//Esta funcion consinte en buscar si un domino es un doble cuando el primer numero es igual al segundo numero
	while (buscar!= nullptr)
	{
		if (buscar->domino[0]==buscar->domino[2])
		{
			return buscar->domino;
		}
		buscar = buscar->next;
	}
	return buscar_mayor();
}
string Jugador::buscar_mayor() {
	//Esat funcion esta vinculada con la funcion de "buscar doble".
	//Consiste en buscar el domino de mayor si se da el caso en donde el jugador
	// no tiene una ficha doble.
	// Nodos. 
	Nodo* buscar = Head;
	Nodo* buscar2 = Head->next;
	//Valores de las fichas.
	int buscador = 0;
	int buscador2 = 0;
	//Variables para convertir
	string convertir = "";
	string convetir2 = "";
	while (buscar2 != nullptr)
	{
		//Funcion .subsrt, sirve para buscar una parte en especifico de la cadena
		//La fucnion stoi, sierve para convertir un numero de una cadena de caracteres en un numero usable
		convertir = buscar->domino.substr(2, 2);
		buscador = stoi(buscar->domino) + stoi(convertir);
		
		convetir2 = buscar2->domino.substr(2, 2);
		
		buscador2 = stoi(buscar2->domino)+stoi(convetir2);
		//si siguiente domino es mayor que el anterior.
		if (buscador < buscador2) {
			buscar = buscar2;
			buscar2 = buscar2->next;
		}
		//si no es mayor al siguiente.
		else
		{
			buscar2 = buscar2->next;
		}

		
	}
	//Devuelve el domino de mayor valor
	return buscar->domino;
}
int Jugador::contar() {
	//Funcion para poder contar la cantidad de dominos que posee el jugador.
	int cantidad = 0;
	Nodo* contador = new Nodo;
	contador = Head;
	if (contador == NULL) {

		return cantidad;
	}
	else
	{

		while (contador != NULL)
		{
			cantidad++;
			contador = contador->next;
		}
		return cantidad;
	}
}
string Jugador::buscar_en(int posicion) {
	if (Head == NULL) {
		return "X";
	}
	else if (posicion < 1) {

		return Head->domino;
	}
	else if (contar() < posicion) {

		return NULL;
	}
	else
	{
		int  lugar =1;
		Nodo* auxilizar = new Nodo;
		auxilizar = Head;
		while (auxilizar != NULL)
		{
			if (lugar == posicion) {
				return auxilizar->domino;
			}
			auxilizar = auxilizar->next;
			lugar++;


		}

	}
}
string Jugador::remover_en(int posicion) {
	//Funcion para borrar un nodo en una posicion en especifico
	if (Head == NULL) {
		//Caso en donde no hay dominos.
		cout << "No hay dominos\n";
		return "X";
	}
	if (contar() < posicion || posicion < 0) {//si esta fuera de la cantidad de elementos
		cout << "Numero invalido para la lista\n";
		return Head->domino;
	}
	else if (posicion == 1)
		//si es el head
	{
		Nodo* borrar = Head;
		Head = Head->next;
		delete borrar;
		return Head->domino;
	}
	else
	{
		//Caso para los demas nodos
		Nodo* aux1 = new Nodo;
		aux1 = Head;
		Nodo* aux2 = new Nodo;

		int contar = 1;
		//Consiste en empezar desde el siguiente, osea que no sea el "Head".
		while (contar != posicion && aux1->next != NULL)
		{

			aux2 = aux1;
			aux1 = aux1->next;
			contar++;
		}
		Nodo* guardar = aux1;
		if (contar == posicion)
		{
			//Caso en donde es el ultimo nodo/domino.
			aux2->next = aux1->next;

		}
		//Devuelve el domino/nodo que sea borrado.
		return guardar->domino;


	}
}
string Jugador::buscar_igual(string domnio) {
	//Funcion para buscar un domino que sea compatible en la mesa.
	Nodo* buscar = Head;
	int contar = 0;
	while (buscar!= NULL)
	{
		if (buscar->domino[0] == domino[0]||buscar->domino[2]==domino[2])
		{
			return remover_en(contar);
		}
		contar++;
		buscar = buscar->next;
	}
	return "X";
}
int Jugador::sumar() {
	//Funcion para poder sumar el valor de cada domino del jugador
	if (Head==NULL)
	{
		return 0;
	}
	else
	{
		Nodo* sum1 = Head;

		int numero1 = 0, total = 0;
		string convertir1 = "";
		while (sum1 != nullptr)
		{
			convertir1 = sum1->domino.substr(2, 2);
			numero1 = stoi(sum1->domino) + stoi(convertir1);
			total = numero1 + total;
			sum1 = sum1->next;
		}
		return total;
	}
	
}
bool Jugador::ver_domino() {
	string ver = buscar_doble();
	if (ver[0] == ver[2])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}