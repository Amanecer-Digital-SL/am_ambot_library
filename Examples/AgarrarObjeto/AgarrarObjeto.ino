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
        Este sketch muestra un ejemplo de codigo en el cual el AMBOT abre la pinza
        y baja el brazo, para luego coger un objeto. Tras esto el robot seguirá en linea
        recta hasta encontrar un obstaculo. Cuando encuentre dicho obstaculo, soltara el 
        objeto y empezara a evitar los objetos frontales girando en sentido horario
        cuando se encuentre con uno.
*/

// Se incluye la libreria AMBOT.h
#include <AMBOT.h>

// Se crea el objeto AMBot 
AMBOT AMBot;

// AMBOT lleva un objeto
bool objeto = true;

// Variable en la cual se almacena el valor de la distancia
uint8_t dist = 0;

void setup() {
  // Inicializamos el bus serial a una velocidad de 9600 baudios
  Serial.begin(9600);
  // Se envia un mensaje por el monitor serial
  Serial.println("Test de agarrar un objeto");
  // Inicializamos el AMBot
  AMBot.inicializarAMBot();
  // Pequeño retardo antes de empezar con el resto de instrucciones
  delay(500);
  // Se abre la pinza
  AMBot.moverServo(AMBot.servo_motor_1, 30);
  // Se añade un pequeño retardo
  delay(2000);
  // Se baja el brazo lentamente
  for(int i = 0; i<90; i++){
    AMBot.moverServo(AMBot.servo_motor_2, i);
    // Se añade un pequeño retardo
    delay(50);
  }
  // Se cierra la pinza
  AMBot.moverServo(AMBot.servo_motor_1, 0);
  // Se añade un pequeño retardo
  delay(1000);
  // Se sube el brazo lentamente
  for(int i = 90; i>0; i--){
    AMBot.moverServo(AMBot.servo_motor_2, i);
    // Se añade un pequeño retardo
    delay(25);
  }
}

void loop() {
  // Se almacena el valor leido de distancia del sensor de ultrasonidos
  dist = AMBot.obtenerDistancia();
  // Se imprime por monitor serial el valor obtenido
  Serial.println(dist);
  Serial.println("");
  // Si hay un objeto a mas de 10 cm o no detecta nada
  if((dist>10)||(dist==0)){
    // Mover el robot cm hacia delante
    AMBot.moverRobot(AMBot.motores_alante, 5);
  }
  // En caso contrario
  else{
    // Si aun se lleva el objeto, se debe soltar
    if(objeto==true){
      // Se abre la pinza
      AMBot.moverServo(AMBot.servo_motor_1, 30);
      // Pequeño retardo 
      delay(500);
      // Se baja el brazo para que termine de caer el objeto
      AMBot.moverServo(AMBot.servo_motor_2, 50);
      // Pequeño retardo
      delay(500);
      // Se sube el brazo
      AMBot.moverServo(AMBot.servo_motor_2, 0);
      // Pequeño retardo
      delay(500);
      // Se cierra la pinza
      AMBot.moverServo(AMBot.servo_motor_1, 0);
      // Pequeño retardo
      delay(3000);
      // Se ha soltado el objeto
      objeto = false;
    }
    // Girar el robot 90 grados
    AMBot.girarRobot(AMBot.sentido_horario,90);
    // Hacer un pitido
    AMBot.sonarTono(2000, 100);
    // Pequeño retardo
    delay(100);
  }
}
