#include "disenio.h"

const int CANT_PERSONAJES = 8;

const string BARRA_SUPERIOR = "\u250C\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2510";
const string BARRA_CABEZA = "\u2537";
const string BARRA_VERTICAL = "\u2502";
const string SOPORTE_PISO = "\u2500\u2534\u2500";

const string CUERPO = " 👕 ";
const string MANO_IZQUIERDA = "  👈";
const string MANO_DERECHA = "👉    " + BARRA_VERTICAL + "\n";
const string PIERNAS = "     👖       " + BARRA_VERTICAL + "\n";
const string PIE_IZQUIERDO = "    👟";
const string PIE_DERECHO = " 👟     " + BARRA_VERTICAL;
const string RAYA_MUERTE = "\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500";

const string CORAZONES[] = {"♥", "♡"};
const string CABEZAS[] = {"😳", "😬", "😐", "😣", "😞", "😨", "😰", "💀"};
const string PERSONA[] = {"", MANO_IZQUIERDA, CUERPO, MANO_DERECHA, PIERNAS, PIE_IZQUIERDO, PIE_DERECHO};

void dibujar_persona(int errores, int intentos_max) {
	cout << "      " << BARRA_SUPERIOR << "  Vidas extra:" << endl;
	cout << "      " << BARRA_CABEZA << "       " << BARRA_VERTICAL << "  ";

	int cantidad_corazones = intentos_max - CANT_PERSONAJES;

	for (int i = cantidad_corazones - 1; i >= 0; i--) { // Uso este formato para que se "borren" desde la derecha
			cout << CORAZONES[i < errores] << "  ";
	}
	cout << endl;

	errores -= cantidad_corazones;

	for (int i = 0; i < errores; i++) {
		if (i == 0) {
			cout << "     " << CABEZAS[errores - 1] << "       " << BARRA_VERTICAL << endl;
			if (errores == CANT_PERSONAJES) {
				cout << "  " << RAYA_MUERTE << "   " << BARRA_VERTICAL << endl;
			}
		}

		// Si hay 2 errores se dibujan solo la cabeza y el cuerpo,
		// Se agrega el espacio para centrar con el cuerpo y se hace i++ para que dibuje el cuerpo y no la mano
		if (i == 1 && errores == 2) {
			cout << "    ";
			i++;
		}

		cout << PERSONA[i];

		// Solucion de la barra vertical para cuando falta el brazo o pie derecho
		if (errores <= 3 && i > 1)
			cout << "      " << BARRA_VERTICAL;
		if (errores == 6 && i == 5)
			cout << "        " << BARRA_VERTICAL;

	}

	// Solucion de la barra vertical cuando no hay cabeza, cuerpo, piernas o pies
	if (errores <= 1 || errores == 4 || errores == 5) {
		cout << "              " << BARRA_VERTICAL;
	}

	cout << endl << "              " << BARRA_VERTICAL << endl << "             " << SOPORTE_PISO << endl;
}

void dibujar_letras(char* palabra, bool adivinadas[], int cantidad_letras) {
	cout << endl << "   ";
	for (int i = 0; i < cantidad_letras; i++) {
		char letra = (adivinadas[i]) ? palabra[i] : '_';
		cout << letra << " ";
	}
	cout << endl << endl;
}

void dibujar_letras(char* palabra, int cantidad_letras) {
	cout << endl << "   ";
	for (int i = 0; i < cantidad_letras; i++) {
		char letra = palabra[i];
		cout << letra << " ";
	}
	cout << endl << endl;
}