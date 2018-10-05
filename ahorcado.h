#ifndef AHORCADO_H
#define AHORCADO_H

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Ahorcado{
	private:
		char * palabra;
		unsigned intentos;
		unsigned errores_cometidos;
		bool * letras_acertadas;
		unsigned cantidad_letras_ingresadas;
		char letras_ingresadas[26];
	public:
		Ahorcado(string palabra, unsigned int intentos);
		unsigned int obtener_intentos();
		unsigned obtener_errores_cometidos();
		char* obtener_palabra();
		bool* obtener_letras_acertadas();
		void comparar_palabra(string palabra_arriesgada);
		int chequear_letra(char letra);
		void aumentar_errores();
		int contar_letras();
		bool gano();
		bool letra_es_repetida(char letra);
		bool comprobar_partida();
		~Ahorcado();
};

#endif // AHORCADO_H