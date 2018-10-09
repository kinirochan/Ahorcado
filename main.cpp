#include "ahorcado.h"
#include "disenio.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <cctype>

const string SI = "s";
const string NO = "n";
const int MIN_INTENTOS = 3;
const int MIN_LETRAS = 3;

/*pre: - */
/*post: Solicita al usuario que ingrese una palabra para jugar o se toma una
aleatoria de un archivo y se devuelve.*/
string pedir_palabra ();

/*pre: - */
/*post: devuelve una palabra aleatoria obtenida de un archivo*/
string buscar_palabra_aleatoria();

/* pre: - */
/*post: devuelve el numero de intentos solicitado por el usuario */
int pedir_intentos();

/* pre: recibe un char* palabra  */
/*post: devuelve true si los datos ingresados son correctos y false en caso contrario*/
bool validar_palabra(string palabra);

/* pre: recibe un numero de intentos */
/*post: devuelve true si los datos ingresados son correctos y false en caso contrario*/
bool validar_intentos(int intentos);

/* pre: recibe un char* valido y cargado correctamente*/
/*post: devuelve la cantidad de caracteres del char* */
int largo_string(char* palabra);

/* pre: recibe la partida finalizada*/
/*post: muestra por pantalla si el jugador gano o perdio */
void mostrar_resultado(bool gano);

int main() {
	/*___Variables___*/
	string dato_ingresado;
	string palabra_ingresada;
	int cantidad_intentos, intentos_restantes;
	char * palabra_arriesgada = NULL;


	palabra_ingresada = pedir_palabra();
	cantidad_intentos = pedir_intentos();

	system ("clear");

	Ahorcado partida(palabra_ingresada, cantidad_intentos);

	while (partida.comprobar_partida()) {

		dibujar_persona(partida.obtener_errores_cometidos(), partida.obtener_intentos());
		dibujar_letras(partida.obtener_palabra(), partida.obtener_letras_acertadas(), partida.contar_letras());

		intentos_restantes = (partida.obtener_intentos() - partida.obtener_errores_cometidos());
		cout << "Tiene " << intentos_restantes << " intentos restantes" << endl;
		cout << "Ingrese una letra o intente adivinar la palabra:" << endl;
		cin >> dato_ingresado;

		if (dato_ingresado.length() == 1){
			char letra = dato_ingresado[0];
			letra=tolower(letra);

			if ((partida.chequear_letra(letra) == 0) && !partida.letra_es_repetida(letra)) {

				partida.aumentar_errores();
				partida.ingresar_letra(letra);

			}

		} else {

			palabra_arriesgada = new char [dato_ingresado.length()+1];
			partida.convertir_string_a_char(dato_ingresado, palabra_arriesgada);
			partida.pasar_a_minusculas(palabra_arriesgada,dato_ingresado.length());
			partida.comparar_palabra(palabra_arriesgada, dato_ingresado.length());

		}

		system ("clear");
	}

	dibujar_persona(partida.obtener_errores_cometidos(), partida.obtener_intentos());
	dibujar_letras(partida.obtener_palabra(), partida.contar_letras());

	mostrar_resultado(partida.gano());

	if(palabra_arriesgada!=NULL){
		delete[] palabra_arriesgada;
	}

	return EXIT_SUCCESS;
}

string pedir_palabra() {
	string palabra;
	string elegir_palabra;

	do{

		cout << "¿Desea ingresar una palabra? [s/n]" << endl;
		cin >> elegir_palabra;

		if (elegir_palabra == SI) {

			do{
				cout << "Ingrese una palabra con mas de tres letras" << endl;
				cin >> palabra;
			} while (!validar_palabra(palabra));

		} else if (elegir_palabra == NO) {

			palabra = buscar_palabra_aleatoria();
			cout << "Se ha elegido una palabra al azar." << '\n';

		}

	}while (elegir_palabra != SI && elegir_palabra != NO);

	return palabra;
}

bool validar_palabra(string palabra) {
		bool es_valido = true;

		if(palabra.length() < MIN_LETRAS){
			es_valido = false;
		}

	return es_valido;
}

bool validar_intentos(int intentos) {
		bool es_valido = true;
		if(intentos < MIN_INTENTOS){
			es_valido = false;
		}
	return es_valido;
}

int largo_string(char* palabra) {
	int largo = 0;

	while (palabra[largo] != '\0') {
		largo++;
	}

	return largo;
}

string buscar_palabra_aleatoria() {
	srand (time(NULL));
	string palabra;
	int numero_aleatorio = rand() % 50 + 1;

	ifstream archivo;
	archivo.open("palabras.txt");

	for(int i = 0; i < numero_aleatorio; i++){
		getline(archivo, palabra);
	}

	archivo.close();
	return palabra;
}

int pedir_intentos() {
	int intentos;

	do{
		cout << "Ingrese el numero de intentos deseado, como minimo deben ser tres." << endl;
		cin >> intentos;
	}while (!validar_intentos(intentos));

	return intentos;
}

void mostrar_resultado(bool gano) {

	if (gano) {
		cout << "Ha ganado la partida!" << endl;
	} else {
		cout << "Ha perdido la partida" << endl;
	}
}
