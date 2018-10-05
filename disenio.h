#ifndef DISENIO_H
#define DISENIO_H

#include <iostream>

using namespace std;

void dibujar_persona(int errores, int intentos_max);
void dibujar_letras(char* palabra, bool adivinadas[], int cantidad_letras);
void dibujar_letras(char* palabra, int cantidad_letras);

#endif