/*


         █████╗  ██████╗ █████╗ ██████╗ ███████╗███╗   ███╗██╗ █████╗ 
        ██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔════╝████╗ ████║██║██╔══██╗
        ███████║██║     ███████║██║  ██║█████╗  ██╔████╔██║██║███████║
        ██╔══██║██║     ██╔══██║██║  ██║██╔══╝  ██║╚██╔╝██║██║██╔══██║
        ██║  ██║╚██████╗██║  ██║██████╔╝███████╗██║ ╚═╝ ██║██║██║  ██║
        ╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚═════╝ ╚══════╝╚═╝     ╚═╝╚═╝╚═╝  ╚═╝
                                                              
                ███╗   ███╗ █████╗ ██╗  ██╗███████╗██████╗                
                ████╗ ████║██╔══██╗██║ ██╔╝██╔════╝██╔══██╗               
                ██╔████╔██║███████║█████╔╝ █████╗  ██████╔╝               
                ██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝  ██╔══██╗               
                ██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗██║  ██║               
                ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝               
                                                              

    Autor: Academia Maker
    Version: 1.0.0
    Fecha de creación: Noviembre de 2024
    Fecha de version: Noviembre de 2024
    Descripcion:
        Este sketch programa el AMBOT para que pueda ser utilizado para
        jugar al tres en ralla, haciendo uso de la pantalla OLED y de la matriz 
        de pulsadores.

        Cada vez que se pulse un boton, se va a marcar esa casilla y se va a hacer
        un cambio de jugador de forma automatica. Para reiniciar el juego se deben 
        marcar todas las casillas. 

        Nota: Este codigo no interpreta si hay un ganador, solo geenera una interfaz
        minima para poder jugar

*/

// Se incluye la libreria AMBOT.h
#include <AMBOT.h>

// Se crea el objeto AMBot 
AMBOT AMBot;

// Se crean las variables necesarias
uint8_t total = 0;      // Numero de veces pulsado
bool jugador = 0;       // Jugador 
// Variable para saber si la casilla esta vacia
bool casilla_1 = 1;
bool casilla_2 = 1;
bool casilla_3 = 1;
bool casilla_4 = 1;
bool casilla_5 = 1;
bool casilla_6 = 1;
bool casilla_7 = 1;
bool casilla_8 = 1;
bool casilla_9 = 1;

void setup() {
  // Inicializamos el bus serial a una velocidad de 9600 baudios
  Serial.begin(9600);

  // Enviamos un mensaje por el monitor serial
  Serial.println("Juego de tres en ralla");

  // Inicializamos el AMBot
  AMBot.inicializarAMBot();

  // Limpiamos la pantalla OLED
  AMBot.limpiarOled();

  // Dibujar una recta horizontal
  AMBot.dibujarRectaX(0,22,128);

  // Dibujar otra recta horizontal
  AMBot.dibujarRectaX(0,44,128);

  // Dibujar una recta vertical
  AMBot.dibujarRectaY(41,0,64);

  // Dibujar otra recta vertical
  AMBot.dibujarRectaY(83,0,64);

  // Ajustar todo el tamaño del texto
  AMBot.cambiarSizeTexto(2);
}

void loop() {
  // Evaluamos los 9 pulsadores
  for(int i = 1; i < 10 ; i++){
    // Se lee cada pulsador
    if(AMBot.leerPulsador(i)){
      switch (i) {
        case 1:     // Se ha pulsado el boton 1
          // Si no hay nada en la casilla
          if(casilla_1){
            // Seleccionar ubicacion
            AMBot.seleccionarCursor(14, 5);
            // Seleccionar a que jugador le toca
            if(jugador){
              AMBot.escribirOled("X");
              // Cambiar de jugador
              jugador = !jugador;
            }
            else{
              // Imprimir una O 
              AMBot.escribirOled("O");
              // Cambiar de jugador
              jugador = !jugador;
            }
            // Casilla llena
            casilla_1 = 0;
            // Sumar una
            total++;
          }
          break;
        case 2:     // Se ha pulsado el boton 2
          // Si no hay nada en la casilla
          if(casilla_2){
            // Seleccionar ubicacion
            AMBot.seleccionarCursor(57, 5);
            // Seleccionar a que jugador le toca
            if(jugador){
              // Imprimir una X 
              AMBot.escribirOled("X");
              // Cambiar de jugador
              jugador = !jugador;
            }
            else{
              // Imprimir una O 
              AMBot.escribirOled("O");
              // Cambiar de jugador
              jugador = !jugador;
            }
            // Casilla llena
            casilla_2 = 0;
            // Sumar una
            total++;
            }
            break;
            
        case 3:     // Se ha pulsado el boton 3
          // Si no hay nada en la casilla
          if(casilla_3){
            // Seleccionar ubicacion
            AMBot.seleccionarCursor(102, 5);
            // Seleccionar a que jugador le toca
            if(jugador){
              // Imprimir una X 
              AMBot.escribirOled("X");
              // Cambiar de jugador
              jugador = !jugador;
            }
            else{
              // Imprimir una O 
              AMBot.escribirOled("O");
              // Cambiar de jugador
              jugador = !jugador;
            }
            // Casilla llena
            casilla_3 = 0;
            // Sumar una
            total++;
          }
          break;
        case 4:     // Se ha pulsado el boton 4
          // Si no hay nada en la casilla
          if(casilla_4){
            // Seleccionar ubicacion
            AMBot.seleccionarCursor(14, 26);
            // Seleccionar a que jugador le toca
            if(jugador){
              // Imprimir una X 
              AMBot.escribirOled("X");
              // Cambiar de jugador
              jugador = !jugador;
            }
            else{
              // Imprimir una O 
              AMBot.escribirOled("O");
              // Cambiar de jugador
              jugador = !jugador;
            }
            // Casilla llena
            casilla_4 = 0;
            // Sumar una
            total++;
          }
          break;
        case 5:     // Se ha pulsado el boton 5
          // Si no hay nada en la casilla
          if(casilla_5){
            // Seleccionar ubicacion
            AMBot.seleccionarCursor(57, 26);
            // Seleccionar a que jugador le toca
            if(jugador){
              // Imprimir una X 
              AMBot.escribirOled("X");
              // Cambiar de jugador
              jugador = !jugador;
            }
            else{
              // Imprimir una O 
              AMBot.escribirOled("O");
              // Cambiar de jugador
              jugador = !jugador;
            }
            // Casilla llena
            casilla_5 = 0;
            // Sumar una
            total++;
          }
          break;
        case 6:     // Se ha pulsado el boton 6
          // Si no hay nada en la casilla
          if(casilla_6){
            // Seleccionar ubicacion
            AMBot.seleccionarCursor(102, 26);
            // Seleccionar a que jugador le toca
            if(jugador){
              // Imprimir una X 
              AMBot.escribirOled("X");
              // Cambiar de jugador
              jugador = !jugador;
            }
            else{
              // Imprimir una O 
              AMBot.escribirOled("O");
              // Cambiar de jugador
              jugador = !jugador;
            }
            // Casilla llena
            casilla_6 = 0;
            // Sumar una
            total++;
          }
          break;
        case 7:     // Se ha pulsado el boton 7
          // Si no hay nada en la casilla
          if(casilla_7){
            // Seleccionar ubicacion
            AMBot.seleccionarCursor(14, 48);
            // Seleccionar a que jugador le toca
            if(jugador){
              // Imprimir una X 
              AMBot.escribirOled("X");
              // Cambiar de jugador
              jugador = !jugador;
            }
            else{
              // Imprimir una O 
              AMBot.escribirOled("O");
              // Cambiar de jugador
              jugador = !jugador;
            }
            // Casilla llena
            casilla_7 = 0;
            // Sumar una
            total++;
          }
          break;
        case 8:     // Se ha pulsado el boton 8
          // Si no hay nada en la casilla
          if(casilla_8){
            // Seleccionar ubicacion
            AMBot.seleccionarCursor(57, 48);
            // Seleccionar a que jugador le toca
            if(jugador){
              // Imprimir una X 
              AMBot.escribirOled("X");
              // Cambiar de jugador
              jugador = !jugador;
            }
            else{
              // Imprimir una O 
              AMBot.escribirOled("O");
              // Cambiar de jugador
              jugador = !jugador;
            }
            // Casilla llena
            casilla_8 = 0;
            // Sumar una
            total++;
          }
          break;
        case 9:     // Se ha pulsado el boton 9
          // Si no hay nada en la casilla
          if(casilla_9){
            // Seleccionar ubicacion
            AMBot.seleccionarCursor(102, 48);
            // Seleccionar a que jugador le toca
            if(jugador){
              // Imprimir una X 
              AMBot.escribirOled("X");
              // Cambiar de jugador
              jugador = !jugador;
            }
            else{
              // Imprimir una O 
              AMBot.escribirOled("O");
              // Cambiar de jugador
              jugador = !jugador;
            }
            // Casilla llena
            casilla_9 = 0;
            // Sumar una
            total++;
          }
          break;
      }
    }
  }
  // Se han pulsado los nueve pulsadores
  if(total >=9){
    // Emitir unos sonidos
    AMBot.sonarTono(1000, 200);
    delay(200);
    AMBot.sonarTono(2500, 300);
    delay(300);
    AMBot.sonarTono(1000, 200);
    delay(200);
    delay(2000);
    // Limpiar pantalla OLED
    AMBot.limpiarOled();
    // Dibujar una recta horizontal
    AMBot.dibujarRectaX(0,22,128);
    // Dibujar otra recta horizontal
    AMBot.dibujarRectaX(0,44,128);
    // Dibujar una recta vertical
    AMBot.dibujarRectaY(41,0,64);
    // Dibujar otra recta vertical
    AMBot.dibujarRectaY(83,0,64);
    // Reiniciar las variables
    total = 0;
    jugador = 0;
    casilla_1 = 1;
    casilla_2 = 1;
    casilla_3 = 1;
    casilla_4 = 1;
    casilla_5 = 1;
    casilla_6 = 1;
    casilla_7 = 1;
    casilla_8 = 1;
    casilla_9 = 1;
  }
}