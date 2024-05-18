

#include <iostream>
#include <cstdlib>//libreria originacia de C, se va a usar para poder usar la funcion de numeros aleatorios
#include <string>
#include<ctime> //libreria originacia de C, se va a usar para poder usar la funcion de numeros aleatorios
#include "Jugador.h"
#include "Nodo.h"
#include "Pozo.h"
#include"Mesa.h"
/*Pendientes:
*Funciones para los siguientes casos: para dos 2 jugadores, 3 jugadores, 4 jugadores.
*Comentar cada funcion del codigo
*Ver despues que pasa si el pozo no hay fichas
* Buscar mas posibles casos a la hora de jugar
* solucionar el escenario en donde un juador tiene dos dominos dobles
*/

using namespace std;
int puntos_aganar = 0;
Pozo* pozo = new Pozo();
Mesa* mesa = new Mesa();
int numero_dominos = 28;
string* Dominos = new string[numero_dominos];

void DOS(int puntos_aganar)
{
	//Declaracion de los dominos
	Dominos[0] = "0|0";
	Dominos[1] = "1|0";
	Dominos[2] = "2|0";
	Dominos[3] = "3|0";
	Dominos[4] = "4|0";
	Dominos[5] = "5|0";
	Dominos[6] = "6|0";
	Dominos[7] = "1|1";
	Dominos[8] = "1|2";
	Dominos[9] = "1|3";
	Dominos[10] = "1|4";
	Dominos[11] = "1|5";
	Dominos[12] = "1|6";
	Dominos[13] = "2|2";
	Dominos[14] = "2|3";
	Dominos[15] = "2|4";
	Dominos[16] = "2|5";
	Dominos[17] = "2|6";
	Dominos[18] = "3|3";
	Dominos[19] = "3|4";
	Dominos[20] = "3|5";
	Dominos[21] = "3|6";
	Dominos[22] = "4|4";
	Dominos[23] = "4|5";
	Dominos[24] = "4|6";
	Dominos[25] = "5|5";
	Dominos[26] = "5|6";
	Dominos[27] = "6|6";
	//Declaracion de los jugadores
	Jugador Jugador1;
	Jugador Jugador2;
	//valores para poder escojer un domino de forma aleatoria.
	int D = 7;
	int arriba = 0;


	srand(time(NULL));

	int random;
	int j = 0, inferior = 0, contador = 0, superior = 20;
	bool domino1 = false, domino2 = false;
	int j2 = 0;
	//Asignacion de dominos de jugador 1
	while (!domino1)
	{
		random = inferior + rand() % (superior - inferior);//funcion para buscar dominos de forma aleatoria

		if (Dominos[random] != "X")//Si ya fue escojido anteriormente, se va ser representado con: "X", y no va a ser agragdo a la lista.
		{
			Jugador1.add(Dominos[random]);
			Dominos[random] = "X";
			contador++;
		}
		if (contador == 7)// Si alcanza la cantidad de dominos impuesta, se sale del ciclo.
		{
			domino1 = 1;
			contador = 0;
		}

	}
	Jugador1.imprimir();
	cout << "----------------------------\n";
	//Asignacion de dominos de jugador 2
	while (!domino2)
	{
		random = inferior + rand() % (superior - inferior);
		//cout << "random " << random << endl;
		if (Dominos[random] != "X")
		{
			Jugador2.add(Dominos[random]);
			Dominos[random] = "X";
			contador++;
		}
		if (contador == 7)
		{
			domino2 = 1;
		}
	}
	Jugador2.imprimir();
	cout << "----------------------\n";

	//Asignar las fichas restantes
	for (int i = 0; i < numero_dominos; i++)
	{

		if (Dominos[i] != "X") {
			pozo->Queque(Dominos[i]);//Busca todos los dominos restantes.

		}

	}
	cout << "EL doble del jugador 1 es: " << Jugador1.buscar_doble() << endl;
	cout << "EL doble del jugador 2 es: " << Jugador2.buscar_doble() << endl;

	//Valores que se van a usar para saber quien va primero.
	bool juego = false, juego2 = false;
	bool verfficar1 = false, verficar2 = 0;

	//Buscar quien tiene el doble mayor o que tenga la ficha de mayor valor ↓
	if (Jugador1.buscar_doble()[0] == Jugador1.buscar_doble()[2]) {
		juego = true;
	}
	if (Jugador2.buscar_doble()[0] == Jugador2.buscar_doble()[2])
	{
		juego2 = true;
	}
	//la fucnion de string: "substr", se usa pra tomar desde un letras o numero en una cadena de string en una
	// cadena de texto, el primer numero marca el incio y el segundo marca el final de la canridad de letras.

	//La fucnion de int: "stio", se usa para poder convertir letras o numero en una cadena de caracteres, numeros
	// se puede usar en dato de tipo int.
	if (juego && juego2)
	{
		string con = Jugador1.buscar_doble().substr(2, 2);
		int convert_1 = 0, convert_2 = 0;
		convert_1 = stoi(Jugador1.buscar_doble()) + stoi(con);
		con = Jugador2.buscar_doble().substr(2, 2);
		convert_2 = stoi(Jugador2.buscar_doble()) + stoi(con);
		if (convert_1 > convert_2) {
			cout << "EMpizar j1\n";
			int ficha = 0;
			cin >> ficha;
			cout << "domi j1\n " << Jugador1.buscar_en(ficha) << endl;

			mesa->Push(Jugador1.remover_en(ficha));
			verfficar1 = 1;
			//El resultado es si el jugador 1 tiene la ficha doble de mayor valor.
		}
		else
		{

			cout << "enpieza j2\n";
			int ficha = 0;
			cin >> ficha;

			cout << "domi j2 \n" << Jugador2.buscar_en(ficha) << endl;
			mesa->Push(Jugador2.remover_en(ficha));

			//El resultado es si el jugador 2 tiene la ficha doble de mayor valor.
			verficar2 = 1;
		}

	}
	else if (juego) {
		//En este caso es el jugador 1 tiene una ficha doble, pero no con el jugador 2.
		cout << "empiza j1\n";
		int ficha = 0;
		cin >> ficha;

		cout << "domi j1 " << Jugador1.buscar_en(ficha) << endl;

		mesa->Push(Jugador1.remover_en(ficha));
		verfficar1 = 1;
	}
	else if (juego2) {
		//En este caso es el jugador 2 tiene una ficha doble, pero no con el jugador 1.
		cout << "empieza j2\n";
		int ficha = 0;
		cin >> ficha;

		cout << "Su domino es: " << Jugador2.buscar_en(ficha) << endl;

		mesa->Push(Jugador2.remover_en(ficha));
		verficar2 = 0;
	}
	//Variables que se van a usar durante el juego
	bool empezar = false;
	int escojer = 0;
	//Inicio del juego ↓	
	do {

		while (!verfficar1)
		{

			string Respuesta1 = "si";
			while (Respuesta1 == "si" || Respuesta1 == "Si")
			{
				//Se empieza a buscar una ficha que diga el jugador.
				Jugador1.imprimir();
				cout << "Diga la posicion de una ficha jugaodr 1.\n";
				cin >> escojer;
				if (escojer == 0)
				{
					break;
				}
				else
				{
					cout << "Su domino es :" << Jugador1.buscar_en(escojer) << endl;
					cout << "Desa cambiar su ficha\n";
					cin >> Respuesta1;
					cout << "++++++++++++++++++++++++++++++++++\n";
				}
			}
			//si la ficha que se escogio es igual
			if (mesa->Peek()[0] == Jugador1.buscar_en(escojer)[0] || mesa->Peek()[2] == Jugador1.buscar_en(escojer)[2] || mesa->Peek()[2] == Jugador1.buscar_en(escojer)[0] || mesa->Peek()[0] == Jugador1.buscar_en(escojer)[2])
			{
				mesa->Push(Jugador1.remover_en(escojer));
				verfficar1 = 1;
				cout << "++++++++++++++++++++++++++++++++++\n";
				mesa->impirmir_M();
			}//si intentta hacer trampa que se escogio es igual
			else if ((mesa->Peek()[0] != Jugador1.buscar_en(escojer)[0] || mesa->Peek()[2] != Jugador1.buscar_en(escojer)[2] || mesa->Peek()[2] != Jugador1.buscar_en(escojer)[0] || mesa->Peek()[0] != Jugador1.buscar_en(escojer)[2]) && (escojer != 0)) {
				cout << "ficha incorrecta\n";
				cout << "Se ha buscado una ficha automaticamente\n";
				string Domino = Jugador1.buscar_igual(mesa->Peek());
				mesa->Push(Domino);
				cout << "+++++++++++++++++++++++++++++++++++++++++\n";
				mesa->impirmir_M();
				verfficar1 = 1;
			}
			else if (escojer == 0)// si no tiene un ficha que coincida en la mesa
			{
				//Primero pregunta si tiene fichas el pozo
				if (pozo->Peek() == "X") {
					cout << "el juego ha terminado, no hay mas fichas en el pozo\n";
					empezar = 1;
				}
				else
				{
					//Si  tiene, entonces se procede a buscar una ficha para el jugador.
					string respuesta = " ";
					cout << "Desea recoger el domino y usarla para continuar\n";
					cin >> respuesta;
					if ("si" || "Si")
					{

						respuesta = pozo->buscar(pozo, mesa->Peek());//********************
						Jugador1.add(respuesta);
						int nuevo = Jugador1.contar();
						Jugador1.remover_en(nuevo);
						verfficar1 = 1;
					}
					else //Si eljugador decide perder el turno

					{
						cout << "Usted a decidido a perder el turno\n";
						cout << "++++++++++++++++++++++++++++++++++++++\n";
						pozo->imprimir();
						verfficar1 = 1;
					}
				}
			}

		}
		verfficar1 = 0;
		verficar2 = 0;
		while (!verficar2)
		{
			string Respuesta2 = "si";
			while (Respuesta2 == "si" || Respuesta2 == "Si")
			{
				Jugador2.imprimir();
				cout << "Diga la posicion de la ficha jugador 2.\n";
				cin >> escojer;
				if (escojer == 0)
				{
					break;
				}
				else
				{
					cout << "Su domino es: " << Jugador2.buscar_en(escojer) << endl;
					cout << "Desa cambiar su ficha\n";
					cin >> Respuesta2;
					cout << "--------------------------\n";
				}
			}


			//si la ficha que se escogio es igual
			if (mesa->Peek()[0] == Jugador2.buscar_en(escojer)[0] || mesa->Peek()[2] == Jugador2.buscar_en(escojer)[2] || mesa->Peek()[2] == Jugador2.buscar_en(escojer)[0] || mesa->Peek()[0] == Jugador2.buscar_en(escojer)[2])
			{
				mesa->Push(Jugador2.remover_en(escojer));
				verficar2 = 1;
				cout << "--------------------------\n";
				mesa->impirmir_M();

			}//si intenta hacer trampa que se escogio es igual
			else if ((mesa->Peek()[0] != Jugador2.buscar_en(escojer)[0] || mesa->Peek()[2] != Jugador2.buscar_en(escojer)[2] || mesa->Peek()[2] != Jugador2.buscar_en(escojer)[0] || mesa->Peek()[0] != Jugador2.buscar_en(escojer)[2]) && (escojer != 0))
			{
				cout << "ficha incorrecta\n";
				cout << "Se ha buscado una ficha automaticamente\n";
				string Domino = Jugador2.buscar_igual(mesa->Peek());
				if (Domino == "X") {
					string respuesta = " ";
					cout << "Desea recoger el domino y usarla para continuar\n";
					cin >> respuesta;
					if ("si" || "Si")
					{

						respuesta = pozo->buscar(pozo, mesa->Peek());//*******************
						Jugador2.add(respuesta);
						int nuevo = Jugador2.contar();
						Jugador2.remover_en(nuevo);
						verficar2 = 1;
						cout << "---------------------------------\n";
						mesa->impirmir_M();
					}
					else
					{
						cout << "Usted a decidido a perder el turno\n";
						pozo->imprimir();
						verficar2 = 1;
					}
				}
				else
				{
					mesa->Push(Domino);
					cout << "-------------------------------\n";
					mesa->impirmir_M();
					verficar2 = 1;
				}
			}

			else if (escojer == 0)// si no tiene un ficha que coincida en la mesa
			{
				if (pozo->Peek() == "X") {
					cout << "El juego se ha terminado\n";
					empezar = 1;
				}
				else
				{
					if (pozo->Peek() == "X")
					{
						cout << "el juego ha terminado, no hay mas fichas en el pozo\n";
						empezar = 1;
					}
					else
					{
						string respuesta = " ";
						cout << "Desea recoger el domino y usarla para continuar\n";
						cin >> respuesta;
						if ("si" || "Si")
						{

							respuesta = pozo->buscar(pozo, mesa->Peek());//*******************
							Jugador2.add(respuesta);
							int nuevo = Jugador2.contar();
							Jugador2.remover_en(nuevo);
							verficar2 = 1;
							cout << "---------------------------------\n";
							mesa->impirmir_M();
						}
						else
						{
							cout << "Usted a decidido a perder el turno\n";
							pozo->imprimir();
							verficar2 = 1;
						}
					}
				}

			}
		}
		//Mostrar la cantidad de puntos de cada jugador.
		cout << "el total de puntos del jugador 1 es: " << Jugador1.sumar() << endl;
		cout << "el total de puntos del jugador 1 es: " << Jugador2.sumar() << endl;
		//Esta comparacion es para saber cual jugador que tiene mayor cantidad de puntos.

		//funcion para limpiar la pantalla.
		system("cls");
	} while (!empezar);

	if (Jugador1.sumar() > puntos_aganar || Jugador1.sumar() > Jugador2.sumar())
	{
		cout << "El jugador uno ha ganado el juego.\n";
	}
	else
	{
		cout << "El jugador dos ha ganado el juego.\n";
	}
}
void TRES_CUATRO(int jugador, int puntos_aganar) {
	Dominos[0] = "0|0";
	Dominos[1] = "1|0";
	Dominos[2] = "2|0";
	Dominos[3] = "3|0";
	Dominos[4] = "4|0";
	Dominos[5] = "5|0";
	Dominos[6] = "6|0";
	Dominos[7] = "1|1";
	Dominos[8] = "1|2";
	Dominos[9] = "1|3";
	Dominos[10] = "1|4";
	Dominos[11] = "1|5";
	Dominos[12] = "1|6";
	Dominos[13] = "2|2";
	Dominos[14] = "2|3";
	Dominos[15] = "2|4";
	Dominos[16] = "2|5";
	Dominos[17] = "2|6";
	Dominos[18] = "3|3";
	Dominos[19] = "3|4";
	Dominos[20] = "3|5";
	Dominos[21] = "3|6";
	Dominos[22] = "4|4";
	Dominos[23] = "4|5";
	Dominos[24] = "4|6";
	Dominos[25] = "5|5";
	Dominos[26] = "5|6";
	Dominos[27] = "6|6";
	//Declaracion de los jugadores
	Jugador Jugador1;
	Jugador Jugador2;
	Jugador Jugador3;
	Jugador Jugador4;

	//valores para poder escojer un domino de forma aleatoria.
	int D = 7;
	int arriba = 0;

	srand(time(NULL));

	int random;
	int j = 0, inferior = 0, contador = 0, superior = 27;
	bool domino1 = false, domino2 = false, domino3 = false, domino4 = 0;


	while (!domino1)
	{
		random = inferior + rand() % (superior - inferior);//funcion para buscar dominos de forma aleatoria

		if (Dominos[random] != "X")//Si ya fue escojido anteriormente, se va ser representado con: "X", y no va a ser agragdo a la lista.
		{
			Jugador1.add(Dominos[random]);
			Dominos[random] = "X";
			contador++;
		}
		if (contador == 5)// Si alcanza la cantidad de dominos impuesta, se sale del ciclo.
		{
			domino1 = 1;
			contador = 0;
		}

	}
	while (!domino2)
	{
		random = inferior + rand() % (superior - inferior);//funcion para buscar dominos de forma aleatoria

		if (Dominos[random] != "X")//Si ya fue escojido anteriormente, se va ser representado con: "X", y no va a ser agragdo a la lista.
		{
			Jugador2.add(Dominos[random]);
			Dominos[random] = "X";
			contador++;
		}
		if (contador == 5)// Si alcanza la cantidad de dominos impuesta, se sale del ciclo.
		{
			domino2 = 1;
			contador = 0;
		}
	}

	while (!domino3)
	{
		random = inferior + rand() % (superior - inferior);//funcion para buscar dominos de forma aleatoria

		if (Dominos[random] != "X")//Si ya fue escojido anteriormente, se va ser representado con: "X", y no va a ser agragdo a la lista.
		{
			Jugador3.add(Dominos[random]);
			Dominos[random] = "X";
			contador++;
		}
		if (contador == 5)// Si alcanza la cantidad de dominos impuesta, se sale del ciclo.
		{
			domino3 = 1;
			contador = 0;
		}
	}
	if (jugador == 4)
	{
		while (!domino4)
		{
			random = inferior + rand() % (superior - inferior);//funcion para buscar dominos de forma aleatoria

			if (Dominos[random] != "X")//Si ya fue escojido anteriormente, se va ser representado con: "X", y no va a ser agragdo a la lista.
			{
				Jugador4.add(Dominos[random]);
				Dominos[random] = "X";
				contador++;
			}
			if (contador == 5)// Si alcanza la cantidad de dominos impuesta, se sale del ciclo.
			{
				domino4 = 1;
				contador = 0;
			}
		}
	}
	//Asignar las fichas restantes
	for (int i = 0; i < numero_dominos; i++)
	{

		if (Dominos[i] != "X") {
			pozo->Queque(Dominos[i]);//Busca todos los dominos restantes.

		}

	}
	Jugador1.add(pozo->Dequeque());
	Jugador1.add(pozo->Dequeque());
	Jugador2.add(pozo->Dequeque());
	Jugador2.add(pozo->Dequeque());
	Jugador3.add(pozo->Dequeque());
	Jugador3.add(pozo->Dequeque());
	if (jugador == 4)
	{
		Jugador4.add(pozo->Dequeque());
		Jugador4.add(pozo->Dequeque());
	}
	Jugador1.imprimir();
	cout << endl;
	Jugador2.imprimir();
	cout << endl;
	Jugador3.imprimir();
	cout << endl;
	Jugador4.imprimir();
	cout << endl;
	pozo->imprimir();
	if (jugador == 4)
	{
		bool juego1 = Jugador1.ver_domino();
		bool juego2 = Jugador2.ver_domino();
		bool juego3 = Jugador3.ver_domino();
		bool juego4 = Jugador4.ver_domino();

	}
	else
	{
		bool verficar1 = false;
		bool verficar2 = false;
		bool verficar3 = false;
		bool juego1 = Jugador1.ver_domino();
		bool juego2 = Jugador2.ver_domino();
		bool juego3 = Jugador3.ver_domino();
		string con = " ";
		int convert_1 = 0, convert_3 = 0, convertir2 = 0;
		con = Jugador1.buscar_doble().substr(2, 2);
		convert_1 = stoi(Jugador1.buscar_doble()) + stoi(con);
		con = Jugador2.buscar_doble().substr(2, 2);
		convertir2 = stoi(Jugador2.buscar_doble()) + stoi(con);
		con = Jugador3.buscar_doble().substr(2, 2);
		if ((juego1 && juego2 && juego3) == true)
		{


			int ficha = 0;
			if (convert_1 > convertir2 && convert_1 > convert_3)
			{
				cout << "Empizar J1, diga su ficha\n";

				cin >> ficha;
				cout << "Su domino es: " << Jugador1.buscar_en(ficha) << endl;

				mesa->Push(Jugador1.remover_en(ficha));
				verficar1 = 1;
				if (convertir2 > convert_3)
				{
					verficar3 = 1;
				}


			}
			else if (convertir2 > convert_3 && convertir2 > convert_3) {
				cout << "Empieza J2, diga su ficha\n";
				cin >> ficha;
				cout << "Su ficha es: " << Jugador2.buscar_en(ficha) << endl;
				mesa->Push(Jugador1.remover_en(ficha));
				verficar2 = 1;
				if (convert_1 > convert_3)
				{
					verficar3 = 1;
				}
				else
				{
					verficar1 = 1;
				}

			}
			else
			{
				cout << "Empieza J3\n";

				cin >> ficha;

				cout << "Su domino es: " << Jugador3.buscar_en(ficha) << endl;
				mesa->Push(Jugador3.remover_en(ficha));

				//El resultado es si el jugador 2 tiene la ficha doble de mayor valor.
				verficar3 = 1;
				if (convert_1 < convertir2)
				{
					convert_1 = 1;
				}
			}
		}
		else if (juego1 == 0 && juego2 == 0 && juego3 == 0) {
			int ficha = 0;
			string con = " ";
			int convert_1 = 0, convert_3 = 0, convertir2 = 0;
			con = Jugador1.buscar_doble().substr(2, 2);
			convert_1 = stoi(Jugador1.buscar_doble()) + stoi(con);
			con = Jugador2.buscar_doble().substr(2, 2);
			convertir2 = stoi(Jugador2.buscar_doble()) + stoi(con);
			con = Jugador3.buscar_doble().substr(2, 2);
			if (convert_1 > convertir2 && convert_1 > convert_3)
			{
				cout << "Empizar J1, diga su ficha\n";

				cin >> ficha;
				cout << "Su domino es: " << Jugador1.buscar_en(ficha) << endl;

				mesa->Push(Jugador1.remover_en(ficha));
				verficar1 = 1;
				if (convert_3 > convertir2)
				{
					verficar2 = 1;
				}
			}
			else if (convertir2 > convert_1 && convertir2 > convert_3) {
				cout << "Empieza J2, diga su ficha\n";
				cin >> ficha;
				cout << "Su ficha es: " << Jugador2.buscar_en(ficha) << endl;
				mesa->Push(Jugador1.remover_en(ficha));
				verficar2 = 1;
				if (convert_1 > convert_3)
				{
					verficar3 = 1;
				}

			}
			else
			{
				cout << "Empieza J3\n";

				cin >> ficha;

				cout << "Su domino es: " << Jugador3.buscar_en(ficha) << endl;
				mesa->Push(Jugador3.remover_en(ficha));

				//El resultado es si el jugador 2 tiene la ficha doble de mayor valor.
				verficar3 = 1;
				if (convertir2 > convert_1)
				{
					verficar1 = 1;
				}
			}
		}
		else
		{
			string con = " ";
			int convert_1 = 0, convert_3 = 0, convertir2 = 0;
			int ficha = 0;

			if (juego1 && juego3)
			{
				con = Jugador1.buscar_doble().substr(2, 2);
				convert_1 = stoi(Jugador1.buscar_doble()) + stoi(con);
				con = Jugador3.buscar_doble().substr(2, 2);
				convert_3 = stoi(Jugador3.buscar_doble()) + stoi(con);
				if (convert_1 > convert_3) {
					cout << "Empizar J1, diga su ficha\n";

					cin >> ficha;
					cout << "Su domino es: " << Jugador1.buscar_en(ficha) << endl;

					mesa->Push(Jugador1.remover_en(ficha));
					verficar1 = 1;
					//El resultado es si el jugador 1 tiene la ficha doble de mayor valor.
					verficar2 = 1;
				}
				else
				{

					cout << "Empieza J3\n";

					cin >> ficha;

					cout << "Su domino es: " << Jugador3.buscar_en(ficha) << endl;
					mesa->Push(Jugador3.remover_en(ficha));

					//El resultado es si el jugador 2 tiene la ficha doble de mayor valor.
					verficar3 = 1;
				}
			}
			else if (juego2 && juego1) {
				con = Jugador2.buscar_doble().substr(2, 2);
				convertir2 = stoi(Jugador2.buscar_doble()) + stoi(con);
				con = Jugador1.buscar_doble().substr(2, 2);
				convert_1 = stoi(Jugador1.buscar_doble()) + stoi(con);
				if (convertir2 > convert_1)
				{
					cout << "Empieza J2, diga su ficha\n";
					cin >> ficha;
					cout << "Su ficha es: " << Jugador2.buscar_en(ficha) << endl;
					mesa->Push(Jugador1.remover_en(ficha));
					verficar2 = 1;
					verficar3 = 1;
				}
				else
				{
					cout << "Empieza J3\n";

					cin >> ficha;

					cout << "Su domino es: " << Jugador3.buscar_en(ficha) << endl;
					mesa->Push(Jugador3.remover_en(ficha));

					//El resultado es si el jugador 2 tiene la ficha doble de mayor valor.
					verficar3 = 1;
					verficar1 = 1;
				}
			}
			else if (juego3 && juego2) {
				con = Jugador3.buscar_doble().substr(2, 2);
				convert_3 = stoi(Jugador3.buscar_doble()) + stoi(con);
				con = Jugador2.buscar_doble().substr(2, 2);
				convertir2 = stoi(Jugador2.buscar_doble()) + stoi(con);
				if (convert_3 > convertir2)
				{
					cout << "Empieza J3\n";

					cin >> ficha;

					cout << "Su domino es: " << Jugador3.buscar_en(ficha) << endl;
					mesa->Push(Jugador3.remover_en(ficha));

					//El resultado es si el jugador 2 tiene la ficha doble de mayor valor.
					verficar3 = 1;
					verficar1 = 1;
				}
				else
				{
					cout << "Empieza J2, diga su ficha\n";
					cin >> ficha;
					cout << "Su ficha es: " << Jugador2.buscar_en(ficha) << endl;
					mesa->Push(Jugador1.remover_en(ficha));
					verficar2 = 1;
					verficar1 = 1;
				}
			}
			else if (juego1)
			{
				cout << "Empizar J1, diga su ficha\n";

				cin >> ficha;
				cout << "Su domino es: " << Jugador1.buscar_en(ficha) << endl;

				mesa->Push(Jugador1.remover_en(ficha));
				verficar1 = 1;
				//El resultado es si el jugador 1 tiene la ficha doble de mayor valor.
				if (convertir2 < convert_3)
				{
					verficar2 = 1;
				}
			}
			else if (juego2)
			{
				cout << "Empieza J2, diga su ficha\n";
				cin >> ficha;
				cout << "Su ficha es: " << Jugador2.buscar_en(ficha) << endl;
				mesa->Push(Jugador1.remover_en(ficha));
				verficar2 = 1;
				if (convert_1 < convert_3)
				{
					verficar1 = 1;
				}
			}
			else if (juego3)
			{
				cout << "Empieza J3\n";

				cin >> ficha;

				cout << "Su domino es: " << Jugador3.buscar_en(ficha) << endl;
				mesa->Push(Jugador3.remover_en(ficha));

				//El resultado es si el jugador 2 tiene la ficha doble de mayor valor.
				verficar3 = 1;
				if (convertir2 > convert_1)
				{
					verficar1 = 1;
				}
			}
		}
		bool empezar = false;
		int escojer = 0;
		do
		{

			while (!verficar1)
			{

				string Respuesta1 = "si";
				while (Respuesta1 == "si" || Respuesta1 == "Si")
				{
					//Se empieza a buscar una ficha que diga el jugador.
					Jugador1.imprimir();
					cout << "Diga la posicion de una ficha jugaodr 1.\n";
					cin >> escojer;
					if (escojer == 0)
					{
						break;
					}
					else
					{
						cout << "Su domino es :" << Jugador1.buscar_en(escojer) << endl;
						cout << "Desa cambiar su ficha\n";
						cin >> Respuesta1;
						cout << "++++++++++++++++++++++++++++++++++\n";
					}
				}
				//si la ficha que se escogio es igual
				if (mesa->Peek()[0] == Jugador1.buscar_en(escojer)[0] || mesa->Peek()[2] == Jugador1.buscar_en(escojer)[2] || mesa->Peek()[2] == Jugador1.buscar_en(escojer)[0] || mesa->Peek()[0] == Jugador1.buscar_en(escojer)[2])
				{
					mesa->Push(Jugador1.remover_en(escojer));
					verficar1 = 1;
					cout << "++++++++++++++++++++++++++++++++++\n";
					mesa->impirmir_M();
				}//si intentta hacer trampa que se escogio es igual
				else if ((mesa->Peek()[0] != Jugador1.buscar_en(escojer)[0] || mesa->Peek()[2] != Jugador1.buscar_en(escojer)[2] || mesa->Peek()[2] != Jugador1.buscar_en(escojer)[0] || mesa->Peek()[0] != Jugador1.buscar_en(escojer)[2]) && (escojer != 0)) {
					cout << "ficha incorrecta\n";
					cout << "Se ha buscado una ficha automaticamente\n";
					string Domino = Jugador1.buscar_igual(mesa->Peek());
					mesa->Push(Domino);
					cout << "+++++++++++++++++++++++++++++++++++++++++\n";
					mesa->impirmir_M();
					verficar1 = 1;
				}
				else if (escojer == 0)// si no tiene un ficha que coincida en la mesa
				{
					//Primero pregunta si tiene fichas el pozo
					if (pozo->Peek() == "X") {
						cout << "el juego ha terminado, no hay mas fichas en el pozo\n";
						empezar = 1;
					}
					else
					{
						//Si  tiene, entonces se procede a buscar una ficha para el jugador.
						string respuesta = " ";
						cout << "Desea recoger el domino y usarla para continuar\n";
						cin >> respuesta;
						if ("si" || "Si")
						{

							respuesta = pozo->buscar(pozo, mesa->Peek());//********************
							Jugador1.add(respuesta);
							int nuevo = Jugador1.contar();
							Jugador1.remover_en(nuevo);
							verficar1 = 1;
						}
						else //Si eljugador decide perder el turno

						{
							cout << "Usted a decidido a perder el turno\n";
							cout << "++++++++++++++++++++++++++++++++++++++\n";
							pozo->imprimir();
							verficar1 = 1;
						}
					}
				}

			}
			verficar1 = !verficar1;
			verficar2 = !verficar2;
			while (!verficar2)
			{
				string Respuesta2 = "si";
				while (Respuesta2 == "si" || Respuesta2 == "Si")
				{
					Jugador2.imprimir();
					cout << "Diga la posicion de la ficha jugador 2.\n";
					cin >> escojer;
					if (escojer == 0)
					{
						break;
					}
					else
					{
						cout << "Su domino es: " << Jugador2.buscar_en(escojer) << endl;
						cout << "Desa cambiar su ficha\n";
						cin >> Respuesta2;
						cout << "--------------------------\n";
					}
				}


				//si la ficha que se escogio es igual
				if (mesa->Peek()[0] == Jugador2.buscar_en(escojer)[0] || mesa->Peek()[2] == Jugador2.buscar_en(escojer)[2] || mesa->Peek()[2] == Jugador2.buscar_en(escojer)[0] || mesa->Peek()[0] == Jugador2.buscar_en(escojer)[2])
				{
					mesa->Push(Jugador2.remover_en(escojer));
					verficar2 = 1;
					cout << "--------------------------\n";
					mesa->impirmir_M();

				}//si intenta hacer trampa que se escogio es igual
				else if ((mesa->Peek()[0] != Jugador2.buscar_en(escojer)[0] || mesa->Peek()[2] != Jugador2.buscar_en(escojer)[2] || mesa->Peek()[2] != Jugador2.buscar_en(escojer)[0] || mesa->Peek()[0] != Jugador2.buscar_en(escojer)[2]) && (escojer != 0))
				{
					cout << "ficha incorrecta\n";
					cout << "Se ha buscado una ficha automaticamente\n";
					string Domino = Jugador2.buscar_igual(mesa->Peek());
					if (Domino == "X") {
						string respuesta = " ";
						cout << "Desea recoger el domino y usarla para continuar\n";
						cin >> respuesta;
						if ("si" || "Si")
						{

							respuesta = pozo->buscar(pozo, mesa->Peek());//*******************
							Jugador2.add(respuesta);
							int nuevo = Jugador2.contar();
							Jugador2.remover_en(nuevo);
							verficar2 = 1;
							cout << "---------------------------------\n";
							mesa->impirmir_M();
						}
						else
						{
							cout << "Usted a decidido a perder el turno\n";
							pozo->imprimir();
							verficar2 = 1;
						}
					}
					else
					{
						mesa->Push(Domino);
						cout << "-------------------------------\n";
						mesa->impirmir_M();
						verficar2 = 1;
					}
				}

				else if (escojer == 0)// si no tiene un ficha que coincida en la mesa
				{
					if (pozo->Peek() == "X") {
						cout << "El juego se ha terminado\n";
						empezar = 1;
					}
					else
					{
						string respuesta = " ";
						cout << "Desea recoger el domino y usarla para continuar\n";
						cin >> respuesta;
						if ("si" || "Si")
						{

							respuesta = pozo->buscar(pozo, mesa->Peek());//*******************
							Jugador1.add(respuesta);
							int nuevo = Jugador1.contar();
							Jugador1.remover_en(nuevo);
							verficar1 = 1;
							cout << "---------------------------------\n";
							mesa->impirmir_M();
						}
						else
						{
							cout << "Usted a decidido a perder el turno\n";
							pozo->imprimir();
							verficar1 = 1;
						}
					}

				}
			}
			while (!verificar3)
			{
				string respuesta3 = "";
				while (respuesta3 == "si" || respuesta3 == "Si")
				{
					jugador3.imprimir();
					cout << "Diga la posicion de la ficha jugaodr 3\n";
					cin >> escojer;
					if (escojer == 0)
					{
						break;
					}
					else
					{
						cout << "Su domino es: " << Jugador3.buscar_en(escojer) << endl;
						cout << "Desa cambiar su ficha\n";
						cin >> Respuesta3;
						cout << "--------------------------\n";
					}
				}
				if (mesa->Peek()[0] == Jugador3.buscar_en(escojer)[0] || mesa->Peek()[2] == Jugador3.buscar_en(escojer)[2] || mesa->Peek()[2] == Jugador3.buscar_en(escojer)[0] || mesa->Peek()[0] == Jugador3.buscar_en(escojer)[2])
				{
					mesa->Push(Jugador3.remover_en(escojer));
					verficar3 = 1;
					cout << "++++++++++++++++++++++++++++++++++\n";
					mesa->impirmir_M();
				}
				else if ((mesa->Peek()[0] != Jugador3.buscar_en(escojer)[0] || mesa->Peek()[2] != Jugador3.buscar_en(escojer)[2] || mesa->Peek()[2] != Jugador3.buscar_en(escojer)[0] || mesa->Peek()[0] != Jugador3.buscar_en(escojer)[2]) && (escojer != 0))
				{
					cout << "ficha incorrecta\n";
					cout << "Se ha buscado una ficha automaticamente\n";
					string Domino = Jugador3.buscar_igual(mesa->Peek());
					mesa->Push(Domino);
					cout << "+++++++++++++++++++++++++++++++++++++++++\n";
					mesa->impirmir_M();
					verficar3 = 1;
				}
				else if (escojer == 0)
				{
					if (pozo->Peek() == "X") {
						cout << "El juego se ha terminado\n";
						empezar = 1;
					}
					else
					{
						string respuesta = " ";
						cout << "Desea recoger el domino y usarla para continuar\n";
						cin >> respuesta;
						if ("si" || "Si")
						{

							respuesta = pozo->buscar(pozo, mesa->Peek());//*******************
							Jugador3.add(respuesta);
							int nuevo = Jugador3.contar();
							Jugador3.remover_en(nuevo);
							verficar3 = 1;
							cout << "---------------------------------\n";
							mesa->impirmir_M();
						}
						else
						{
							cout << "Usted a decidido a perder el turno\n";
							pozo->imprimir();
							verficar3 = 1;
						}
					}
				}
			}
			//Mostrar la cantidad de puntos de cada jugador.
			cout << "el total de puntos del jugador 1 es: " << Jugador1.sumar() << endl;
			cout << "el total de puntos del jugador 1 es: " << Jugador2.sumar() << endl;
			//Esta comparacion es para saber cual jugador que tiene mayor cantidad de puntos.

			//funcion para limpiar la pantalla.
			system("cls");




		} while (!empezar);

	}

	//Ver quien gano el juego.
	if (jugador == 4)
	{
		if (Jugador1.sumar() > puntos_aganar || (Jugador1.sumar() > Jugador2.sumar() && Jugador1.sumar() > Jugador3.sumar() && Jugador1.sumar() > Jugador4.sumar()))
		{
			cout << "El jugador uno ha gando el juego, con un total de: " << Jugador1.sumar() << endl;
			cout << "Jugador 2: " << Jugador2.sumar() << endl;
			cout << "Jugador 3: " << Jugador3.sumar() << endl;
			cout << "Jugador 4: " << Jugador4.sumar() << endl;
		}
		else if (Jugador2.sumar() > puntos_aganar || (Jugador2.sumar() > Jugador3.sumar() && Jugador2.sumar() > Jugador1.sumar() && Jugador2.sumar() > Jugador4.sumar()))
		{
			cout << "El jugador dos ha gando el juego, con un total de: " << Jugador2.sumar() << endl;
			cout << "Jugador 1: " << Jugador1.sumar() << endl;
			cout << "Jugador 3: " << Jugador3.sumar() << endl;
			cout << "Jugador 4: " << Jugador4.sumar() << endl;
		}
		else if (Jugador3.sumar() > puntos_aganar || (Jugador3.sumar() > Jugador1.sumar() && Jugador3.sumar() > Jugador2.sumar() && Jugador3.sumar() > Jugador4.sumar()))
		{
			cout << "El jugador tres ha gando el juego, con un total de: " << Jugador3.sumar() << endl;
			cout << "Jugador 1: " << Jugador1.sumar() << endl;
			cout << "Jugador 2: " << Jugador2.sumar() << endl;
			cout << "Jugador 4: " << Jugador4.sumar() << endl;
		}
		else if (Jugador4.sumar() > puntos_aganar || (Jugador4.sumar() > Jugador1.sumar() && Jugador4.sumar() > Jugador2.sumar() && Jugador4.sumar() > Jugador3.sumar()))
		{
			cout << "El jugador tres ha gando el juego, con un total de: " << Jugador4.sumar() << endl;
			cout << "Jugador 1: " << Jugador1.sumar() << endl;
			cout << "Jugador 2: " << Jugador2.sumar() << endl;
			cout << "Jugador 3: " << Jugador3.sumar() << endl;
		}
		else {
			cout << "Hubo un empate\n";
			cout << "Jugador 1: " << Jugador1.sumar() << endl;
			cout << "Jugador 2: " << Jugador2.sumar() << endl;
			cout << "Jugador 3: " << Jugador3.sumar() << endl;
			cout << "Jugador 4: " << Jugador4.sumar() << endl;
		}
	}
	else
	{
		if (Jugador1.sumar() > puntos_aganar || (Jugador1.sumar() > Jugador2.sumar() && Jugador1.sumar() > Jugador3.sumar()))
		{
			cout << "El jugador uno ha gando el juego, con un total de: " << Jugador1.sumar() << endl;
			cout << "Jugador 2: " << Jugador2.sumar() << endl;
			cout << "Jugador 3: " << Jugador3.sumar() << endl;
		}
		else if (Jugador2.sumar() > puntos_aganar || (Jugador2.sumar() > Jugador3.sumar() && Jugador2.sumar() > Jugador1.sumar()))
		{
			cout << "El jugador dos ha gando el juego, con un total de: " << Jugador2.sumar() << endl;
			cout << "Jugador 1: " << Jugador1.sumar() << endl;
			cout << "Jugador 3: " << Jugador3.sumar() << endl;
		}
		else if (Jugador3.sumar() > puntos_aganar || (Jugador3.sumar() > Jugador1.sumar() && Jugador3.sumar() > Jugador2.sumar()))
		{
			cout << "El jugador tres ha gando el juego, con un total de: " << Jugador3.sumar() << endl;
			cout << "Jugador 1: " << Jugador1.sumar() << endl;
			cout << "Jugador 2: " << Jugador2.sumar() << endl;
		}
		else {
			cout << "Hubo un empate\n";
			cout << "Jugador 1: " << Jugador1.sumar() << endl;
			cout << "Jugador 2: " << Jugador2.sumar() << endl;
			cout << "Jugador 3: " << Jugador3.sumar() << endl;
		}
	}

}
int main()
{
	int jugador = 0;
	cout << "\tJuego de Domino\n";
	cout << "Diga la cantidad de jugadores\n";
	cin >> jugador;
	do {
		switch (jugador)
		{
		case 2: {//Caso para dos jugadores
			cout << "La cantidad de puntos para ganar\n";
			cin >> puntos_aganar;
			if (puntos_aganar > 25 && puntos_aganar < 100)
			{
				DOS(puntos_aganar);
			}
			else
			{
				cout << "La cantidad de puntos es demasiado baja o muy alta para un juego\n";
			}

		}break;
		case 3:
		{//Caso para tres jugadores
			cout << "La cantidad de puntos para ganar\n";
			cin >> puntos_aganar;
			if (puntos_aganar > 25 && puntos_aganar < 100)
			{
				TRES_CUATRO(jugador, puntos_aganar);
			}
			else
			{
				cout << "La cantidad de puntos es demasiado baja o muy alta para un juego\n";
			}

		}break;
		case 4:
		{//Caso para cuatro jugadores
			cout << "La cantidad de puntos para ganar\n";
			cin >> puntos_aganar;
			if (puntos_aganar > 25 && puntos_aganar < 100)
			{
				TRES_CUATRO(jugador, puntos_aganar);
			}
			else
			{
				cout << "La cantidad de puntos es demasiado baja o muy alta para un juego\n";
			}


		};
		break;
		default: {

			cout << "Cantidad de jugadores invalidad\n";
		}
			   break;
		}
	} while (jugador < 5 && jugador>1);


	return 0;
}
