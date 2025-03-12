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
        Este sketch muestra un ejemplo de codigo para que el robot siga una linea
        indefinidamente. El robot caminara hacia delante si detecta el color negro en los 
        dos sensores lineas disponibles. Si detecta negro solo en un lado, debe girar
        levemente para permanecer dentro de la linea. Si detecta negro en el otro lado
        debe girar pero en el otro sentido. Por ultimo, si el robot se pierde, debe 
        retroceder para tratar de volver al camino. si se pierde durante 3 segundos 
        el robot debe detenerse.
*/

// Se incluye la libreria AMBOT.h
#include <AMBOT.h>

// Se crea el objeto AMBot 
AMBOT AMBot;

// Se crea una variable para almacenar el tiempo
uint32_t time_to_off = 0;

void setup() {
  // Inicializamos el bus serial a una velocidad de 9600 baudios
  Serial.begin(9600);
  // Enviamos un mensaje por el monitor serial
  Serial.println("Test de Robot Siguelineas");
  // Inicializamos el AMBot
  AMBot.inicializarAMBot();
}

void loop() {
  // Si ambos sensores detectan negro
  if((AMBot.leerSiguelineas(AMBot.siguelineas_izquierdo)==HIGH)&&(AMBot.leerSiguelineas(AMBot.siguelineas_derecho)==HIGH)){
    // El robot debe ir hacia adelante
    AMBot.encenderMotores(AMBot.motores_alante);
    // Tomamos el tiempo
    time_to_off = millis();
  }
  // Si el sensor de la izquierda detecta negro
  else if((AMBot.leerSiguelineas(AMBot.siguelineas_izquierdo)==HIGH)){
    // Girar hacia la izquierda
    AMBot.encenderMotores(AMBot.sentido_antihorario);
    // Tomamos el tiempo
    time_to_off = millis();
  }
  // Si el sensor de la derecha detecta negro
  else if((AMBot.leerSiguelineas(AMBot.siguelineas_derecho)==HIGH)){
    // Girar hacia la derecha
    AMBot.encenderMotores(AMBot.sentido_horario);
    // Tomamos el tiempo
    time_to_off = millis();
  }
  // En caso contrario
  else{
    // Si no se encuentra la linea en 3 segundos
    if((millis()-time_to_off)>3000){
        // Apagar los motores
        AMBot.apagarMotores();
    }
    else{
        // Retroceder
        AMBot.encenderMotores(AMBot.motores_atras);
    }
  }
}