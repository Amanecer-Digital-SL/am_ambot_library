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
    Repositorio: 

    Descripcion:
        Esta libreria esta diseñada especificamente para ser utilizada con el AMBOT. Sirve
        para utilizar los siguientes componentes incorporados en el propio robot:
            - Pulsadores
            - Zumbador
            - Siguelineas
            - LDR
            - Motores
            - Servomotores
            - Pantalla OLED
            - Sensor de ultrasonidos
    Metodos principales:
        AMBOT -> Constructor
        leerPulsador -> devuelve el estado de un pulsador
        sonarTono -> emite un sonido en el zumbador
        leerLDR -> obtiene el valor analogico de la LDR
        _init_RGB -> inicializa leds RGB
        cambiarColorLeds -> cambia el color de los leds RBG
        cambiarBrillo -> ajusta el brillo de los leds RGB
        actualizarLeds -> actualiza todos los cambios en los leds RGB
        inicializarAMBot -> inicializador del AMBOT
        moverServo -> mueve el servo a la posicion indicada
        moverRobot -> mueve el robot en linea recta en el sentido indicado
        girarRobot -> gira el robot en el sentido indicado
        obtenerDistancia -> obtiene la distancia a la que esta un obstaculo frontal
        leerSiguelineas -> lee el sensor siguelineas
        _init_OLED -> inicializa la pantalla OLED
        leerEncoders -> obtiene el valor logico de uno de los encoders
        escribirOled -> escribe texto en la pantalla OLED
        seleccionarCursor -> cambia la posicion para escribir texto en la pantalla OLED
        cambiarSizeTexto -> cambia el tamaño del texto a escribir en la OLED
        dibujarRectaX -> dibuja una recta horizontal en la OLED
        dibujarRectaY -> dibuja una recta vertical en la OLED
        limpiarOled -> limpia la pantalla OLED
    Atributos:
        servo_motor_1 -> selecciona el servo 1
        servo_motor_2 -> selecciona el servo 2
        motores_alante -> indica el sentido de avance del robot
        motores_atras -> indica el sentido de avance del robot
        sentido_horario -> indica el sentido de giro del robot
        sentido_antihorario -> indica el sentido de giro del robot
        siguelineas_izquierdo -> selecciona el sensor izquierdo del siguelineas
        siguelineas_derecho -> selecciona el sensor derecho del siguelineas
*/
#ifndef AMBOT_h
#define AMBOT_h

// Dependencias de librerias externas
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h> 
#include <HCSR04.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/***********************************     Clase AMBOT     *****************************************/
class AMBOT{

    public:

        /*********  Metodos  *********/
        // Constructor
        AMBOT();
        // Inicializador
        void inicializarAMBot();
        // Pulsadores
        bool leerPulsador(uint8_t pulsador);
        // Zumbador
        void sonarTono(uint16_t frecuencia, uint16_t tiempo);
        // LDR
        uint16_t leerLDR();
        // Leds RGB
        void cambiarColorLeds(uint8_t LED, uint8_t Red, uint8_t Green, uint8_t Blue);
        void cambiarBrillo(uint8_t Brillo);
        void actualizarLeds();
        // Servomotores
        void moverServo(uint8_t servo, int posicion);
        // Motores DC
        void encenderMotores(uint8_t modo);
        void apagarMotores();
        void moverRobot(uint8_t sentido, uint8_t cantidad);
        void girarRobot(uint8_t sentido, uint8_t cantidad);
        // Sensor ultrasonidos
        uint8_t obtenerDistancia();
        // Sensor siguelineas
        bool leerSiguelineas(uint8_t siguelineas);
        // Pantalla OLED
        void escribirOled(String texto);
        void seleccionarCursor(uint8_t posicion_x, uint8_t posicion_y);
        void cambiarSizeTexto(uint8_t text_size);
        void dibujarRectaX(uint8_t x_inicial, uint8_t y_inicial, uint8_t distancia);
        void dibujarRectaY(uint8_t x_inicial, uint8_t y_inicial, uint8_t distancia);
        void limpiarOled();

        /*********  Atributos  *********/
        const uint8_t servo_motor_1 = 1;
        const uint8_t servo_motor_2 = 2;
        const uint8_t motores_alante = 1;
        const uint8_t motores_atras = 0;
        const uint8_t sentido_horario = 2;
        const uint8_t sentido_antihorario = 3;
        const uint8_t siguelineas_izquierdo = 1;
        const uint8_t siguelineas_derecho = 0;

    private:

        /*********  Metodos  *********/
        // Inicializador
        void _init_RGB();
        void _init_OLED();
        // Encoders
        bool leerEncoders(uint8_t encoder);
        /*********  Atributos  *********/
        // Encoders
        
        const uint8_t encoder_izquierdo = 0;
        const uint8_t encoder_derecho = 1;
        // Pulsadores
        const uint16_t _AMBOT_BOT_1 = 310;
        const uint16_t _AMBOT_BOT_2 = 623;
        const uint16_t _AMBOT_BOT_3 = 941;
        const uint16_t _AMBOT_BOT_4 = 205;
        const uint16_t _AMBOT_BOT_5 = 517;
        const uint16_t _AMBOT_BOT_6 = 834;
        const uint16_t _AMBOT_BOT_7 = 93;
        const uint16_t _AMBOT_BOT_8 = 415;
        const uint16_t _AMBOT_BOT_9 = 726;
        uint8_t _AMBOT_BOT_DIF = 50;
        // Pines de conexion
        const uint8_t _PIN_BOTONERA = A7;
        const uint8_t _PIN_LDR = A6;
        const uint8_t _PIN_TRIG_ULTRA = A3;
        const uint8_t _PIN_ECHO_ULTRA = A2;
        const uint8_t _PIN_MICROFONO = A1;
        const uint8_t _PIN_SIGUELINEAS_DERECHO = A0;
        const uint8_t _PIN_LED_RGB = 13;
        const uint8_t _PIN_SIGUELINEAS_IZQUIERDO = 12;
        const uint8_t _PIN_RECEPTOR_IR = 11;
        const uint8_t _PIN_RF_RECEIVER = 8;
        const uint8_t _PIN_ZUMBADOR = 9;
        const uint8_t _PIN_MOTOR_ENABLE = 10;
        const uint8_t _PIN_MOTOR_IZQUIERDO = 7;
        const uint8_t _PIN_SERVO_1 = 6;
        const uint8_t _PIN_SERVO_2 = 5;
        const uint8_t _PIN_MOTOR_DERECHO = 4;
        const uint8_t _PIN_ENCODER_IZQUIERDO = 3;
        const uint8_t _PIN_ENCODER_DERECHO = 2;

        // Clases externas
        Adafruit_NeoPixel _LEDS_RGB;
        Servo _SERVO_1;
        Servo _SERVO_2;
        HCSR04 _HC_SR;
        Adafruit_SSD1306 _OLED;

};


#endif