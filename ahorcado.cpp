#include "ahorcado.h"

//constructor
Ahorcado::Ahorcado(string palabra, unsigned int intentos){
	unsigned int contador = 0;

	errores_cometidos = 0;

	this->intentos = intentos;
	this->letras_acertadas = new bool[palabra.length()];
	while (contador < palabra.length()) {
		letras_acertadas[contador] = false;
		contador++;
	}
	this->palabra = new char[palabra.length()+1];
	strcpy(this->palabra, palabra.c_str());
}

unsigned int Ahorcado::obtener_intentos(){
	return (this->intentos);
}

unsigned Ahorcado::obtener_errores_cometidos() {
	return this->errores_cometidos;
}

char* Ahorcado::obtener_palabra() {
	return this->palabra;
}

bool* Ahorcado::obtener_letras_acertadas() {
	return this->letras_acertadas;
}

void Ahorcado::aumentar_errores(){
	this->errores_cometidos++;
}

void Ahorcado::comparar_palabra(string palabra_arriesgada) {
	if (palabra_arriesgada.length() != contar_letras()) return;

	bool coinciden = true;
	int i = 0;
	while (i < contar_letras() && coinciden) {
		if (this->palabra[i] != palabra_arriesgada[i]) {
			coinciden = false;
		}
		i++;
	}

	if (coinciden) {
		for (i = 0; i < contar_letras(); i++) {
			letras_acertadas[i] = true;
		}
	}
}

int Ahorcado::contar_letras(){
	int contador = 0;

	while (palabra[contador] != '\0') {
		contador++;
	}

	return contador;
}

bool Ahorcado::gano(){
	bool gano = true;
	int contador = 0;
	while((contador < contar_letras()) && (gano)){
		if(this->letras_acertadas[contador] != true){
			gano=false;
		}
		contador++;
	}

	return gano;
}

int Ahorcado::chequear_letra(char letra){
	int longitud_vector = (this->contar_letras());
	int cantidad_letras = 0;

	for(int i = 0; i < longitud_vector; i++){
		if(this->palabra[i] == letra){
			cantidad_letras++;
			this->letras_acertadas[i] = true;
		}
	}

	return cantidad_letras;
}

bool Ahorcado::letra_es_repetida(char letra){
	unsigned contador = 0;
	bool no_repetido = true;

	while((contador < this->cantidad_letras_ingresadas) && no_repetido){
		if(this->letras_ingresadas[contador] == letra){
			no_repetido = false;
		}
		contador++;
	}

	return no_repetido;
}

bool Ahorcado::comprobar_partida(){
	bool sigue_partida = true;
	if(this->gano() || this->intentos <= 0){
		sigue_partida = false;
	}

	return sigue_partida;
}

Ahorcado::~Ahorcado() {
	delete[] this->palabra;
	delete[] this-> letras_acertadas;
}
