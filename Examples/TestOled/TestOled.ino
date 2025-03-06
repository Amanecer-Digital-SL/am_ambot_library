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
        Este sketch muestra un ejemplo de codigo para programar y utilizar
        las funciones más elementales de una pantalla OLED. LA pantalla OLED 
        debe ir pinchada en el zocalo preparado especificamente para este fin

*/

// Se incluye la libreria AMBOT.h
#include <AMBOT.h>

// Se crea el objeto AMBot 
AMBOT AMBot;

void setup() {
  // Inicializamos el bus serial a una velocidad de 9600 baudios
  Serial.begin(9600);
  // Enviamos un mensaje por el monitor serial
  Serial.println("Test de Pantalla Oled");
  // Inicializamos el AMBot
  AMBot.inicializarAMBot();
}

void loop() {
  // Limpiamos la pantalla OLED
  AMBot.limpiarOled();
  // Cambiamos el tamaño del texto en la pantalla
  AMBot.cambiarSizeTexto(2);
  // Movemos el cursor de la pantalla
  AMBot.seleccionarCursor(20,10);
  // Escribimos "test" en la pantalla
  AMBot.escribirOled("test");
  // Movemos el cursor de la pantalla
  AMBot.seleccionarCursor(20,40);
  // Escribimos "OLED" en la pantalla
  AMBot.escribirOled("OLED");
  // Pequeño retardo de 2000 ms
  delay(2000);
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
  // Pequeño retardo de 2000 ms
  delay(2000);
}