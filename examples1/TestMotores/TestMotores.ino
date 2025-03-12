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
        Este sketch muestra un ejemplo de codigo utilizar los motores DC
        del propio robot. En la PCB hay dos conectores especificos para conectar
        los motores

*/

// Se incluye la libreria AMBOT.h
#include <AMBOT.h>

// Se crea el objeto AMBot 
AMBOT AMBot;

void setup() {
  // Inicializamos el bus serial a una velocidad de 9600 baudios
  Serial.begin(9600);
  // Se envia mensaje por el monitor serial
  Serial.println("Test de Motores");
  // Inicializamos el AMBot
  AMBot.inicializarAMBot();
}

void loop() {
  // Mover el robot hacia adelante 20 cm
  AMBot.moverRobot(AMBot.motores_alante, 20);
  // Pequeño retardo de 1000 ms
  delay(1000);
  // Girar el robot en sentido horario 90 grados
  AMBot.girarRobot(AMBot.sentido_horario, 90);
  // Pequeño retardo de 1000 ms
  delay(1000);
  // Mover el robot hacia atras 20 cm
  AMBot.moverRobot(AMBot.motores_atras, 20);
  // Pequeño retardo de 1000 ms
  delay(1000);
  // Girar el robot en sentido antihorario 90 grados
  AMBot.girarRobot(AMBot.sentido_antihorario, 90);
  // Pequeño retardo de 1000 ms
  delay(1000);
}
