#ifndef DISENIO_H
#define DISENIO_H

#include <iostream>

using namespace std;

/* pre: recibe los intentos maximos y los errores cometidos ambos datos deben ser validos */
/*post:  imprime por pantalla una persona con tantas partes del cuerpo como errores haya cometido el jugador*/
void dibujar_persona(int errores, int intentos_max);

/* pre: recibe la palabra a adivinar un vector bool con cuantas letras fueron adivinadas y la cantidad de letras, todos datos validos*/
/*post:  dibuja las letras que fueron adivinadas por pantalla*/
void dibujar_letras(char* palabra, bool adivinadas[], int cantidad_letras);

/* pre: recibe la palabra a adivinar y la cantidad de letras de la misma */
/*post: imprime por pantalla tantos guiones como letras queden por adivinar*/
void dibujar_letras(char* palabra, int cantidad_letras);

#endif
