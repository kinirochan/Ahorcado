#include <iostream>
#include <string>
#include "disenio.h"
#include "ahorcado.h"

using namespace std;

// void inicializar_adivinadas(bool adivinadas[], int largo);

// int main() {
// 	// Ejemplo para mostrar todos los errores.
// 	for (int i = 0; i <= ERRORES_MAX; i++) {
// 		cout << endl;
// 		dibujar_persona(i);
// 		cout << endl;
// 	}

// 	// dibujar_persona(2);

// 	// string palabra = "AHORCADO";
// 	// bool adivinadas[palabra.length()];
// 	// inicializar_adivinadas(adivinadas, palabra.length());

// 	// dibujar_letras(palabra, adivinadas);
// }

// void inicializar_adivinadas(bool adivinadas[], int largo) {
// 	for (int i = 0; i < largo; i++) {
// 		adivinadas[i] = false;
// 	}
// }

int validar_datos(char * palabra, int intentos);
int largo_string(char* palabra);
char pedir_letra();
string pedir_palabra ();

int main() {
	string palabra;

	palabra = pedir_palabra();


	Ahorcado partida(palabra, 8);

	while (partida.comprobar_partida()) {
		//mostrar por pantalla
		std::cout << "Ingrese una letra o intente adibinar la palabra:" << '\n';
		cin >> palabra;

		if(){
			
		}
	}

	return 0;
}

int validar_datos(char* palabra, int intentos){

	return 0;
}

int largo_string(char* palabra){
	int largo = 0;

	while (palabra[largo] != '\0') {
		largo++;
	}

	return largo;
}

char pedir_letra(){
	char letra;

	cout << "Ingrese una letra.\n";
	cin >> letra;

	return letra;
}

string pedir_palabra (){
	string palabra;
	char elegir_palabra;
	cout << "¿Desea ingresar una palabra? [s/n]" << endl;
	cin >> elegir_palabra;

	if(elegir_palabra == 's'){
		cout << "Ingrese una palabra con mas de tres letras" << endl;
		cin >> palabra;
	}else if(elegir_palabra == 'n'){

	}
	return palabra;
}


	