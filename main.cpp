#include "ahorcado.h"
#include "disenio.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

/*pre: - */
/*post: Solicita al usuario que ingrese una palabra para jugar o se toma una
aleatoria de un archivo y se devuelve.*/
string pedir_palabra ();

/*pre: -*/
/*post: devuelve una palabra aleatoria obtenida de un archivo*/
string buscar_palabra_aleatoria();

/* pre: */
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
void mostrar_resultado(Ahorcado partida);

int main() {
	string dato_ingresado;
	int cantidad_intentos;
	int intentos_restantes;

	dato_ingresado = pedir_palabra();
	while (!validar_palabra(dato_ingresado)){
		dato_ingresado = pedir_palabra();
	}
	cantidad_intentos = pedir_intentos();
	while(!validar_intentos(cantidad_intentos)){
		cantidad_intentos = pedir_intentos();
	}

	system ("clear");

	Ahorcado partida(dato_ingresado, cantidad_intentos);

	while (partida.comprobar_partida()) {
		dibujar_persona(partida.obtener_errores_cometidos(), partida.obtener_intentos());
		dibujar_letras(partida.obtener_palabra(), partida.obtener_letras_acertadas(), partida.contar_letras());
		intentos_restantes = (partida.obtener_intentos() - partida.obtener_errores_cometidos());
		cout << "Tiene " << intentos_restantes << " intentos restantes" << endl;
		cout << "Ingrese una letra o intente adivinar la palabra:" << endl;
		cin >> dato_ingresado;
		system ("clear");

		if (dato_ingresado.length() == 1){
			char letra = dato_ingresado[0];
			if ((partida.chequear_letra(letra) == 0) && !partida.letra_es_repetida(letra)) {
				partida.aumentar_errores();
				partida.ingresar_letra(letra);
			}
		} else {
			partida.comparar_palabra(dato_ingresado);
		}
	}

	dibujar_persona(partida.obtener_errores_cometidos(), partida.obtener_intentos());
	dibujar_letras(partida.obtener_palabra(), partida.contar_letras());

	mostrar_resultado(partida);

	return 0;
}

bool validar_palabra(string palabra) {
		bool es_valido = true;

		if(palabra.length() < 3){
			es_valido = false;
		}
	return es_valido;
}

bool validar_intentos(int intentos) {
		bool es_valido = true;
		if(intentos < 3){
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

string pedir_palabra() {
	string palabra;
	char elegir_palabra;
	cout << "¿Desea ingresar una palabra? [s/n]" << endl;
	cin >> elegir_palabra;

	if (elegir_palabra == 's') {
		cout << "Ingrese una palabra con mas de tres letras" << endl;
		cin >> palabra;
	} else if (elegir_palabra == 'n') {
		palabra = buscar_palabra_aleatoria();
	}
	return palabra;
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
	cout << "Ingrese el numero de intentos deseado como minimo deben ser tres" << endl;
	cin >> intentos;
	return intentos;
}

void mostrar_resultado(Ahorcado partida){

	if (partida.gano()) {
		cout << "Ha ganado la partida!" << endl;
	} else {
		cout << "Ha perdido la partida" << endl;
	}
}
