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
        Este sketch muestra un ejemplo de codigo para mover a varias posiciones
        los dos servomotores del AMBOT (brazo y pinza)

*/

// Se incluye la libreria AMBOT.h
#include <AMBOT.h>

// Se crea el objeto AMBot 
AMBOT AMBot;

void setup() {
  // Inicializamos el bus serial a una velocidad de 9600 baudios
  Serial.begin(9600);
  // Enviamos un mensaje por el monitor serial
  Serial.println("Test de Servomotor");
  // Inicializamos el AMBot
  AMBot.inicializarAMBot();
}

void loop() {
  // Movemos el servo 1 (pinza) a la posicion 0 (cerrada)
  AMBot.moverServo(AMBot.servo_motor_1, 0);
  // Movemos el servo 2 (brazo) a la posicion 0 (arriba)
  AMBot.moverServo(AMBot.servo_motor_2, 0);
  // Pequeño retardo de 2000 ms
  delay(2000);
  // Movemos el servo 1 (pinza) a la posicion 15 (semi-abierta)
  AMBot.moverServo(AMBot.servo_motor_1, 15);
  // Movemos el servo 2 (brazo) a la posicion 45 (semi-arriba)
  AMBot.moverServo(AMBot.servo_motor_2, 45);
  // Pequeño retardo de 2000 ms
  delay(2000);
  // Movemos el servo 1 (pinza) a la posicion 30 (abierta)
  AMBot.moverServo(AMBot.servo_motor_1, 30);
  // Movemos el servo 2 (brazo) a la posicion 90 (abajo)
  AMBot.moverServo(AMBot.servo_motor_2, 90);
  // Pequeño retardo de 2000 ms
  delay(2000);
}
