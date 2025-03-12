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
        Este sketch muestra un ejemplo de codigo para que el zumbador presente en la 
        placa del AMBOT emita pitidos en diferentes frecuencias (con tonos diferentes)

*/

// Se incluye la libreria AMBOT.h
#include <AMBOT.h>

// Se crea el objeto AMBot 
AMBOT AMBot;

void setup() {
  // Inicializamos el bus serial a una velocidad de 9600 baudios
  Serial.begin(9600);
  // Enviamos un mensaje por el monitor serial
  Serial.println("Test de Zumbador");
  // Inicializamos el AMBot
  AMBot.inicializarAMBot();
}

void loop() {
  // Se emite un tono de 1000 Hz durante 500 ms
  AMBot.sonarTono(1000,500);
  // Se espera 500 ms
  delay(500);
  // Se emite un tono de 1500 Hz durante 500 ms
  AMBot.sonarTono(1500,500);
  // Se espera 500 ms
  delay(500);
  // Se emite un tono de 2000 Hz durante 500 ms
  AMBot.sonarTono(2000,500);
  // Se espera 500 ms
  delay(500);
  // Se emite un tono de 2500 Hz durante 500 ms
  AMBot.sonarTono(2500,500);
  // Se espera 500 ms
  delay(500);
  // Se emite un tono de 3000 Hz durante 500 ms
  AMBot.sonarTono(3000,500);
  // Se espera 500 ms
  delay(500);
  // Se emite un tono de 3500 Hz durante 500 ms
  AMBot.sonarTono(3500,500);
  // Se espera 500 ms
  delay(500);
}