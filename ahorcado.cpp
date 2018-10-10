#include "ahorcado.h"

//constructor
Ahorcado::Ahorcado(string palabra, unsigned int intentos) {
	std::cout << "Constructor:" << endl;

	this->errores_cometidos = 0;
	this->cantidad_letras_ingresadas = 0;
	this->intentos = intentos;

	this->letras_acertadas = new bool[palabra.length()];
	this->inicializar_letras_acertadas((int)palabra.length());
	std::cout << "Direccion de memoria de letras_acertadas: " << &this->letras_acertadas  << endl;

	this->palabra = new char[palabra.length() + 1];
	convertir_string_a_char(palabra, this->palabra);
	this->pasar_a_minusculas(this->palabra, palabra.length() + 1);
	std::cout << "Direccion de memoria de palabra: " << &this->palabra  << endl << endl;
}

void Ahorcado::convertir_string_a_char(string palabra_string, char* palabra_char){

	for(unsigned i = 0; i < palabra_string.length(); i++){
		palabra_char[i] = palabra_string[i];
	}
	palabra_char[palabra_string.length()] = '\0';
}

unsigned int Ahorcado::obtener_intentos() {
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

void Ahorcado::aumentar_errores() {
	this->errores_cometidos++;
}

void Ahorcado::comparar_palabra(char* palabra_arriesgada, int largo) {

	if (largo != contar_letras()) {
		this->errores_cometidos = this->intentos;
	} else {
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

		} else {
			this->errores_cometidos = this->intentos;
		}
	}
}

int Ahorcado::contar_letras() {
	int contador = 0;

	while (palabra[contador] != '\0') {
		contador++;
	}

	return contador;
}

bool Ahorcado::gano() {
	bool gano = true;
	int contador = 0;

	while ((contador < contar_letras()) && (gano)) {

		if (this->letras_acertadas[contador] == false) {
			gano = false;
		}

		contador++;
	}

	return gano;
}

void Ahorcado::ingresar_letra(char letra) {

	if (!letra_es_repetida(letra)) {
		this->letras_ingresadas[this->cantidad_letras_ingresadas] = letra;
		this->cantidad_letras_ingresadas++;
	}

}

int Ahorcado::chequear_letra(char letra) {
	int longitud_vector = this->contar_letras();
	int cantidad_letras = 0;

	for (int i = 0; i < longitud_vector; i++) {

		if (this->palabra[i] == letra) {
			cantidad_letras++;
			this->letras_acertadas[i] = true;
		}

	}

	return cantidad_letras;
}

bool Ahorcado::letra_es_repetida(char letra) {
	unsigned contador = 0;
	bool repetida = false;

	while ((contador < this->cantidad_letras_ingresadas) && !repetida) {

		if (this->letras_ingresadas[contador] == letra) {
			repetida = true;
		}

		contador++;
	}

	return repetida;
}

bool Ahorcado::comprobar_partida() {
	bool sigue_partida = true;

	if (this->gano() || this->errores_cometidos >= this->intentos) {
		sigue_partida = false;
	}

	return sigue_partida;
}

void Ahorcado::pasar_a_minusculas (char * palabra, int tamanio_vector){

	for(int i = 0; i < tamanio_vector; i++){
	 	palabra[i] = tolower(palabra[i]);
	}

}

void Ahorcado::inicializar_letras_acertadas(int largo){

	for (int i = 0; i < largo; i++) {
		this->letras_acertadas[i] = false;
	}

}

//destructor
Ahorcado::~Ahorcado() {

	std::cout << "Destructor:" << endl;
	std::cout << "Direccion de memoria de letras_acertadas: " << &this->letras_acertadas  << endl;
	delete[] this-> letras_acertadas;

	std::cout << "Direccion de memoria de palabra: " << &this->palabra  << endl;
	delete[] this->palabra;

}
