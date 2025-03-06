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
        Este sketch muestra un ejemplo de codigo para encender y configurar 
        los cuatro leds RGB presentes en la pcb del AMBOT

*/

// Se incluye la libreria AMBOT.h
#include <AMBOT.h>

// Se crea el objeto AMBot 
AMBOT AMBot;

void setup() {
  // Inicializamos el bus serial a una velocidad de 9600 baudios
  Serial.begin(9600);
  // Enviamos un mensaje por el monitor
  Serial.println("Test de Leds RGB");
  // Inicializamos el AMBot
  AMBot.inicializarAMBot();
}

void loop() {
  // Cambiamos el brillo de los leds
  AMBot.cambiarBrillo(20);
  // Cambiamos el color de los leds
  AMBot.cambiarColorLeds(0,100,100,0);
  AMBot.cambiarColorLeds(1,0,100,100);
  AMBot.cambiarColorLeds(2,100,0,100);
  AMBot.cambiarColorLeds(3,150,50,100);
  // Actualizamos los leds
  AMBot.actualizarLeds();
  // Pequeño retardo para observar el estado de los leds
  delay(500);
  // Cambiamos el brillo de los leds
  AMBot.cambiarBrillo(40);
  // Cambiamos el color de los leds
  AMBot.cambiarColorLeds(0,0,100,100);
  AMBot.cambiarColorLeds(1,100,0,100);
  AMBot.cambiarColorLeds(2,100,100,0);
  AMBot.cambiarColorLeds(3,200,100,50);
  // Actualizamos los leds
  AMBot.actualizarLeds();
  // Pequeño retardo para observar el estado de los leds
  delay(500);
  // Cambiamos el brillo de los leds
  AMBot.cambiarBrillo(60);
  // Cambiamos el color de los leds
  AMBot.cambiarColorLeds(0,100,0,100);
  AMBot.cambiarColorLeds(1,100,100,0);
  AMBot.cambiarColorLeds(2,0,100,100);
  AMBot.cambiarColorLeds(3,100,0,200);
  // Actualizamos los leds
  AMBot.actualizarLeds();
  // Pequeño retardo para observar el estado de los leds
  delay(500);
  
}
