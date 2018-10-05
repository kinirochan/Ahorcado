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

/* pre: recibe un char* palabra y un numero de intentos */
/*post: ¿?*/
int validar_datos(char * palabra, int intentos);

/* pre: recibe un char* valido y cargado correctamente*/
/*post: devuelve la cantidad de caracteres del char* */
int largo_string(char* palabra);


int main() {
  string dato_ingresado;
  int cantidad_intentos;

  dato_ingresado = pedir_palabra();
  cantidad_intentos = pedir_intentos();
  Ahorcado partida(dato_ingresado, cantidad_intentos);
  system ("clear");

  while (partida.comprobar_partida()) {
    dibujar_persona(partida.obtener_errores_cometidos(), partida.obtener_intentos());
    dibujar_letras(partida.obtener_palabra(), partida.obtener_letras_acertadas(), partida.contar_letras());
    std::cout << "Ingrese una letra o intente adivinar la palabra:" << '\n';
    cin >> dato_ingresado;
    system ("clear");

    if(dato_ingresado.length() == 1){
      if(partida.chequear_letra(dato_ingresado[0]) == 0)
        partida.aumentar_errores();
    }else{
      partida.comparar_palabra(dato_ingresado);

    }
  }

  dibujar_persona(partida.obtener_errores_cometidos(), partida.obtener_intentos());
  dibujar_letras(partida.obtener_palabra(), partida.contar_letras());

  if(partida.gano()){
    cout << "Ha ganado la partida!" << endl;
  }else{
    cout << "Ha perdido la partida" << endl;
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

int  pedir_intentos(){
  int intentos;
  cout << "Ingrese el numero de intentos deseado" << endl;
  cin >> intentos;
  return intentos;
}
