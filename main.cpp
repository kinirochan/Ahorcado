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
/*post: */
string buscar_palabra_aleatoria();

int validar_datos(char * palabra, int intentos);

int largo_string(char* palabra);

char pedir_letra();

int main() {
  string dato_ingresado;

  dato_ingresado = pedir_palabra();

  Ahorcado partida(dato_ingresado, 8);

  while (partida.comprobar_partida()) {
    dibujar_persona(partida.obtener_errores_cometidos(), partida.obtener_intentos());
    dibujar_letras(partida.obtener_palabra(), partida.obtener_letras_acertadas(), partida.contar_letras());
    std::cout << "Ingrese una letra o intente adibinar la palabra:" << '\n';
    cin >> dato_ingresado;

    if(dato_ingresado.length() == 1){
      if(partida.chequear_letra(dato_ingresado[0]) == 0)
        partida.aumentar_errores();
    }else{
      partida.comparar_palabra(dato_ingresado);
    }
  }

  dibujar_persona(partida.obtener_errores_cometidos(), partida.obtener_intentos());
  dibujar_letras(partida.obtener_palabra(), partida.contar_letras());

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
    palabra = buscar_palabra_aleatoria();
  }
  return palabra;
}

string buscar_palabra_aleatoria(){
  srand (time(NULL));
  string palabra;
  int numero_aleatorio = rand() % 20 + 1;

  ifstream archivo;
  archivo.open("palabras.txt");

  for(int i = 0; i < numero_aleatorio; i++){
    getline(archivo, palabra);
  }

  archivo.close();
  return palabra;
}
