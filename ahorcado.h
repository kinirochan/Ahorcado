#ifndef AHORCADO_H
#define AHORCADO_H

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MAX_LETRAS = 27;

class Ahorcado{

	private:
		//Atributos
		char * palabra;
		char letras_ingresadas[MAX_LETRAS];
		bool * letras_acertadas;
		unsigned intentos;
		unsigned errores_cometidos;
		unsigned cantidad_letras_ingresadas;

		//Métodos
		//pre: requiere el largo del vector letras_acertadas a inicializar
		//post: todas las posiciones del vector son marcadas como falsas
		void inicializar_letras_acertadas(int largo);

	// Métodos
	public:

		//Constructor
		/* pre: recibe un string palabra y la cantidad de intentos que tiene el jugador*/
		/*post:  carga los datos de la palabra y los intentos*/
		Ahorcado(string palabra, unsigned int intentos);

		/*pre: recibe un string valido y un char * vacio */
		/*post: convierte un string en char* */
		void convertir_string_a_char(string palabra_string, char* palabra_char);

		/* pre: - */
		/*post: devuelve los intentos que tiene el jugador */
		unsigned int obtener_intentos();

		/* pre: -*/
		/*post: devuelve cuantos errores lleva el jugador hasta el momento*/
		unsigned obtener_errores_cometidos();

		/* pre: -*/
		/*post: devuelve la palabra a ser adivinada */
		char* obtener_palabra();

		/* pre: -*/
		/*post: devuelve un vector de bool que tiene true en la posicion de la letra si fue
		adivinada y false en caso contrario*/
		bool* obtener_letras_acertadas();

		/* pre: -*/
		/*post: compara si la palabra a adivinar y la arriesgada coinciden viendo asi si el
		jugador gano o perdio */
		void comparar_palabra(char* palabra_arriesgada, int largo);

		/* pre: recibe la letra ingresada por el usuario */
		/*post: verifica si la letra ingresada esta en la palabra a adivinar y devuelve cuantas
		veces esta en la misma */
		int chequear_letra(char letra);

		/* pre: -*/
		/*post: aumenta los errores cometidos por el jugador */
		void aumentar_errores();

		/* pre: -*/
		/*post: devuelve la cantidad de letras que tiene la palabra a adivinar */
		int contar_letras();

		/* pre: -*/
		/*post: verifica si el jugador gano o no el juego devolviendo true y false
		respectivamente */
		bool gano();

		/* pre: recibe la letra ingresada por el usuario */
		/*post: agrega la letra en el vector de letras_ingresadas */
		void ingresar_letra(char letra);

		/* pre: recibe una letra ingresada por el usuario */
		/*post: devuelve true si la letra ingresada ya habia sido ingresada anteriormente  */
		bool letra_es_repetida(char letra);

		/* pre: -*/
		/*post: comprueba si la partida finalizo o no, devuelve true o false respectivamente*/
		bool comprobar_partida();

		/*pre: recibe una palabra char* y su tamaño*/
		/*post: convierte todos los elementos en palabra a minuscula*/
		void pasar_a_minusculas (char * palabra, int tamanio_vector);

		//Destructor
		/* pre: -*/
		/*post: libera la memoria que fue pedida a lo largo del programa */
		~Ahorcado();
};

#endif // AHORCADO_H
