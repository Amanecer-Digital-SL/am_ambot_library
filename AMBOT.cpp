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

#include "AMBOT.h"

/*******************  Constructor  *******************/
/*
    Constructor para el uso y programacion de la libreria AMBOT. No recibe 
    ningun parametro de entrada.
*/
AMBOT::AMBOT()
    :_LEDS_RGB(4, _PIN_LED_RGB, NEO_GRB + NEO_KHZ800),
    _SERVO_1(),
    _SERVO_2(),
    _HC_SR(_PIN_TRIG_ULTRA, _PIN_ECHO_ULTRA),
    _OLED(128, 64, &Wire, -1)
    {
    _init_RGB();
    pinMode(_PIN_MOTOR_ENABLE, OUTPUT);
}
/*****************  Inicializadores  *****************/
/*
    Funcion que se utiliza para inicializar la pantalla OLED. Esta pantalla OLED se debe
    colocar en el zocalo especificamente preparado para ella. En caso de usar otra pantalla 
    que no sea la pantalla OLED 128x64 se debe cambiar la direccion I2C de esta. Esta funcion
    no necesita parametros de entrada ni devuelve ningun valor.
*/
void AMBOT::_init_OLED(){
    _OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    _OLED.clearDisplay();
    _OLED.setTextColor(SSD1306_WHITE);
    _OLED.setTextSize(2);
    _OLED.setRotation(2);
    _OLED.setCursor(32, 25);
    _OLED.write("AMBOT");
    _OLED.display();
    _OLED.setTextSize(1);
}

/*
    Funcion que inicializa los leds RGB presentes en la pcb. No recibe paramnetros 
    de entrada. No devuelve ningun valor
*/
void AMBOT::_init_RGB(){
    _LEDS_RGB.begin();
    _LEDS_RGB.setBrightness(15);
}

/*
    Esta funcion permite inicializar todos los sensores y o actuadores del AMBOT
    para poder ser utilizados posteriormente. No devuelve ningun valor y no requiere
    ningun parametro de entrada.
*/
void AMBOT::inicializarAMBot(){
    _SERVO_1.attach(_PIN_SERVO_1);
    _SERVO_2.attach(_PIN_SERVO_2);
    _SERVO_1.write(0);
    _SERVO_2.write(0);
    _init_OLED();
}

/*******************  Pulsadores  ********************/
/*
    Funcion que devuelve un estado de true o false en funcion de si el pulsador
    indicado ha sido pulsado. Recibe los siguientes parametros:
        - pulsador: pulsador sobre el cual se quiere conocer el estado.
*/
bool AMBOT::leerPulsador(uint8_t pulsador){
    uint16_t pulsador_value = analogRead(_PIN_BOTONERA);
    if(pulsador_value > 1000){
        return 0;
    }
    else{
        switch(pulsador){
            case 1:
                if((pulsador_value > (_AMBOT_BOT_1 - _AMBOT_BOT_DIF)) && (pulsador_value < (_AMBOT_BOT_1 + _AMBOT_BOT_DIF))){
                    return 1;
                }
                else{
                    return 0;
                }
                break;

            case 2:
                if((pulsador_value > (_AMBOT_BOT_2 - _AMBOT_BOT_DIF)) && (pulsador_value < (_AMBOT_BOT_2 + _AMBOT_BOT_DIF))){
                    return 1;
                }
                else{
                    return 0;
                }
                break;

            case 3:
                if((pulsador_value > (_AMBOT_BOT_3 - _AMBOT_BOT_DIF)) && (pulsador_value < (_AMBOT_BOT_3 + _AMBOT_BOT_DIF))){
                    return 1;
                }
                else{
                    return 0;
                }
                break;

            case 4:
                if((pulsador_value > (_AMBOT_BOT_4 - _AMBOT_BOT_DIF)) && (pulsador_value < (_AMBOT_BOT_4 + _AMBOT_BOT_DIF))){
                    return 1;
                }
                else{
                    return 0;
                }
                break;

            case 5:
                if((pulsador_value > (_AMBOT_BOT_5 - _AMBOT_BOT_DIF)) && (pulsador_value < (_AMBOT_BOT_5 + _AMBOT_BOT_DIF))){
                    return 1;
                }
                else{
                    return 0;
                }
                break;
            
            case 6:
                if((pulsador_value > (_AMBOT_BOT_6 - _AMBOT_BOT_DIF)) && (pulsador_value < (_AMBOT_BOT_6 + _AMBOT_BOT_DIF))){
                    return 1;
                }
                else{
                    return 0;
                }
                break;
            
            case 7:
                if((pulsador_value > (_AMBOT_BOT_7 - _AMBOT_BOT_DIF)) && (pulsador_value < (_AMBOT_BOT_7 + _AMBOT_BOT_DIF))){
                    return 1;
                }
                else{
                    return 0;
                }
                break;
        
            case 8:
                if((pulsador_value > (_AMBOT_BOT_8 - _AMBOT_BOT_DIF)) && (pulsador_value < (_AMBOT_BOT_8 + _AMBOT_BOT_DIF))){
                    return 1;
                }
                else{
                    return 0;
                }
                break;

            case 9:
                if((pulsador_value > (_AMBOT_BOT_9 - _AMBOT_BOT_DIF)) && (pulsador_value < (_AMBOT_BOT_9 + _AMBOT_BOT_DIF))){
                    return 1;
                }
                else{
                    return 0;
                }
                break;
        }
    }
}

/********************  Zumbador  *********************/
/*
    Funcion que emite un tono en el zumbador. Recibe los siguientes parametros
    de entrada:
        - frecuencia: frecuencia a la cual va a emitir el sonido el zumbador
        - tiempo: tiempo de emision del sonido en milisegundos
*/
void AMBOT::sonarTono(uint16_t frecuencia, uint16_t tiempo){
    tone(_PIN_ZUMBADOR, frecuencia, tiempo);
}

/**********************  LDR  ************************/
/*
    Funcion que devuelve el valor analogico de la LDR. Este valor va desde 0 
    hasta 1023. No recibe parametros de entrada.
*/
uint16_t AMBOT::leerLDR(){
    uint16_t value = analogRead(_PIN_LDR);
    return value;
}

/********************  Leds RGB  *********************/
/*
    Funcion que cambia el color de los leds RGB presentes en la pcb. Noi devuelve
    ningun valor. Recibe los siguientes parametros de entrada:
        - LED: Led sobre el cual se quiere cambiar el color mostrado
        - Red: Cantidad de color rojo que debe mostrar el led
        - Green: Cantidad de color verde que debe mostrar el led
        - Blue: Cantidad de color azul que debe mostrar el led
*/
void AMBOT::cambiarColorLeds(uint8_t LED, uint8_t Red, uint8_t Green, uint8_t Blue){
    _LEDS_RGB.setPixelColor(LED, Red, Green, Blue);
}

/*
    Funcion que cambia el brillo (intensidad luminica) de los leds RGB presentes
    en la pcb. No devuelve ningun valor. Recibe los siguientes parametros de entrada:   
        - Brillo: Cantidad de intensidad luminica que debe emitir el led, siendo 0 
                  el valor mas bajo y 255 el valor más alto.
*/
void AMBOT::cambiarBrillo(uint8_t Brillo){
    _LEDS_RGB.setBrightness(Brillo);
}

/*
    Funcion que actualiza todos los cambios hechos en los leds RGB, Esta funcion 
    no devuelve ningun valor. Tampoco requiere ningun parametro de entrada
*/
void AMBOT::actualizarLeds(){
    _LEDS_RGB.show();
}

/*******************  Servomotor  *******************/
/*
    Funcion que mueve el servo seleccionado a la posicion indicada. Esta funcion no
    devuelve ningun valor. Los parametros de entrada se muestran a continuacion
        - servo: Servo que se desea mover. Para seleccionar los servos se debe indicar
                 AMBOT.servo_motor_1 o AMBOT.servo_motor_2.
        - posicion: posicion a la que se desea mover el servo. Los servos admiten desde
                    los 0 grados hasta los 180 grados.
*/
void AMBOT::moverServo(uint8_t servo, int posicion){
    if(servo == servo_motor_1){
        _SERVO_1.write(posicion);
    }
    else if(servo == servo_motor_2){
        _SERVO_2.write(posicion);
    }
}

/*******************  Motores Dc  *******************/
/*
*/

void AMBOT::encenderMotores(uint8_t modo){

    if(modo == motores_alante){
        digitalWrite(_PIN_MOTOR_ENABLE, HIGH);
        digitalWrite(_PIN_MOTOR_IZQUIERDO, HIGH);
        digitalWrite(_PIN_MOTOR_DERECHO, HIGH); 
    }
    else if(modo == motores_atras){
        digitalWrite(_PIN_MOTOR_ENABLE, HIGH);
        digitalWrite(_PIN_MOTOR_IZQUIERDO, LOW);
        digitalWrite(_PIN_MOTOR_DERECHO, LOW);
    }
    else if(modo == sentido_horario){
        digitalWrite(_PIN_MOTOR_ENABLE, HIGH);
        digitalWrite(_PIN_MOTOR_IZQUIERDO, LOW);
        digitalWrite(_PIN_MOTOR_DERECHO, HIGH);
    }
    else if(modo == sentido_antihorario){
        digitalWrite(_PIN_MOTOR_ENABLE, HIGH);
        digitalWrite(_PIN_MOTOR_IZQUIERDO, HIGH);
        digitalWrite(_PIN_MOTOR_DERECHO, LOW);
    }
}

void AMBOT::apagarMotores(){
     digitalWrite(_PIN_MOTOR_ENABLE, LOW);
}

/*
    Funcion que desplaza el robot en una linea recta. Utiliza los encoders presentes
    en las ruedas para conocer la distancia caminada. ESta funcion no devuelve ningun 
    valor. Los parametros de entrada se muestran a continuaciuon:
        - sentido: indica si el robot debe desplazarse hacia delante o hacia detras. 
                   para indicarle el sentido se debe utilizar AMBOT.motores_alante o
                   AMBOT.motores_atras.
        - cantidad: con esta variagble se le indica al robot la distancia en milimetros 
                    que debe avanzar o retroceder.
*/
void AMBOT::moverRobot(uint8_t sentido, uint8_t cantidad){
    if(sentido == motores_alante){
        digitalWrite(_PIN_MOTOR_ENABLE, HIGH);
        digitalWrite(_PIN_MOTOR_IZQUIERDO, HIGH);
        digitalWrite(_PIN_MOTOR_DERECHO, HIGH);  
        uint8_t pasos = 0;
        bool repeticion = 1;
        cantidad = ( (cantidad) * 24 ) / 31;
        while(pasos <= cantidad){
            if((digitalRead(_PIN_ENCODER_IZQUIERDO)==HIGH)&&(repeticion==1)){
                pasos++;
                repeticion = 0;
            }
            else if((digitalRead(_PIN_ENCODER_IZQUIERDO)==LOW)&&(repeticion==0)){
                repeticion = 1;
            }
        }
       digitalWrite(_PIN_MOTOR_ENABLE, LOW);
    }
    else{
        digitalWrite(_PIN_MOTOR_ENABLE, HIGH);
        digitalWrite(_PIN_MOTOR_IZQUIERDO, LOW);
        digitalWrite(_PIN_MOTOR_DERECHO, LOW);
        uint8_t pasos = 0;
        bool repeticion = 1;
        cantidad = ( (cantidad) * 24 ) / 31;
        while(pasos <= cantidad){
            if((digitalRead(_PIN_ENCODER_IZQUIERDO)==HIGH)&&(repeticion==1)){
                pasos++;
                repeticion = 0;
            }
            else if((digitalRead(_PIN_ENCODER_IZQUIERDO)==LOW)&&(repeticion==0)){
                repeticion = 1;
            }
        }
       digitalWrite(_PIN_MOTOR_ENABLE, LOW);
    }
}

/*
    Esta funcion indica al robot que debe realizar un giro. Los encoder presentes
    en las ruedas permiten conocer la cantidad girada. Esta funcion no devuelve ningun 
    valor. Los parametros de entrada se muestran a continuacion:
        - sentido: indica el sentido en el cual debe girar el robot (horario o antihorario)
                   Para indicar el sentido de giro se debe dar AMBOT.sentido_horario o 
                   AMBOT.sentido_antihorario
        - cantidad: indica la cantidad de grados que debe girar el robot. El 
                    valor debe ser positivo
*/
void AMBOT::girarRobot(uint8_t sentido, uint8_t cantidad){
    if(sentido == sentido_horario){
        digitalWrite(_PIN_MOTOR_ENABLE, HIGH);
        digitalWrite(_PIN_MOTOR_IZQUIERDO, LOW);
        digitalWrite(_PIN_MOTOR_DERECHO, HIGH);
        uint8_t pasos = 0;
        bool repeticion = 1;
        cantidad = cantidad / 10;
        while(pasos <= cantidad){
            if((digitalRead(_PIN_ENCODER_IZQUIERDO)==HIGH)&&(repeticion==1)){
                pasos++;
                repeticion = 0;
            }
            else if((digitalRead(_PIN_ENCODER_IZQUIERDO)==LOW)&&(repeticion==0)){
                repeticion = 1;
            }
        }
       digitalWrite(_PIN_MOTOR_ENABLE, LOW);
    }
    else{
        digitalWrite(_PIN_MOTOR_ENABLE, HIGH);
        digitalWrite(_PIN_MOTOR_IZQUIERDO, HIGH);
        digitalWrite(_PIN_MOTOR_DERECHO, LOW);
        uint8_t pasos = 0;
        bool repeticion = 1;
        cantidad = cantidad / 10;
        while(pasos <= cantidad){
            if((digitalRead(_PIN_ENCODER_DERECHO)==HIGH)&&(repeticion==1)){
                pasos++;
                repeticion = 0;
            }
            else if((digitalRead(_PIN_ENCODER_DERECHO)==LOW)&&(repeticion==0)){
                repeticion = 1;
            }
        }
       digitalWrite(_PIN_MOTOR_ENABLE, LOW);
    }
}

/******************  Ultrasonidos  ******************/
/*
    Esta funcion devuelve el valor de la distancia a la cual esta un obstaculo frontal
    en mm con respecto al robot. Esta funcion no recibe parametros de entrada.
*/
uint8_t AMBOT::obtenerDistancia(){
    uint8_t value = _HC_SR.dist();
    return value;
}

/*******************  Encoders  ********************/
/*
    Esta funcion devuelve el estado actual de uno de los encoders. Devuelve un valor de 
    true oi false y requiere que se le indique el encoder.
*/
bool AMBOT::leerEncoders(uint8_t encoder){
    bool value; 
    if(encoder = encoder_izquierdo){
        value = digitalRead(_PIN_ENCODER_IZQUIERDO);
    }
    else{
        value = digitalRead(_PIN_ENCODER_DERECHO);
    }
    return value;
}

/******************  Siguelineas  *******************/
/*
    Funcion que devuelve el estado de uno de los dos sensores presentes en el sensor
    siguelineas. Se debe indicar el sensor sobre el cual se desea conocer el estado.
    Recibe los siguientes parametros como entrada:
        - siguelineas: indica el sensor del cual se quiere conocer el estado. Para
                       seleccionar uno de estos se usara AMBOT.siguelineas_izquierdo o
                       AMBOT.siguelineas_derecho
*/
bool AMBOT::leerSiguelineas(uint8_t siguelineas){
    if(siguelineas == siguelineas_izquierdo){
        return digitalRead(_PIN_SIGUELINEAS_IZQUIERDO);
    }
    else{
        return digitalRead(_PIN_SIGUELINEAS_DERECHO);
    }
}

/*****************  Pantalla OLED  ******************/
/*
    Esta funcion escribe texto en la pantalla OLED. No devuelve ningun valor. A continuacion
    se indican los parametros de entrada:
        - texto: String con los caracteres que se desean mostrar en la pantalla OLED    
*/
void AMBOT::escribirOled(String texto){
    _OLED.print(texto);
    _OLED.display();
}

/*
    Esta funcion permite mover el cursor donde se va a imprimir el texto en la pantalla. 
    Los parametros de entarda son los siguientes:  
        - posicion_x: posicion en x en donde se desea colocar el cursor
        - posicion_y: posicion en y en donde se desea colocar el cursor
*/
void AMBOT::seleccionarCursor(uint8_t posicion_x, uint8_t posicion_y){
    _OLED.setCursor(posicion_x, posicion_y);
}

/*
    Funcion que permite cambiar el tamaño del texto que se va a imprimir en la pantalla.
    Se debe utilizar antes de lña funcion especifica para imprimir el texto. 
    No devuelve ningun valor. Los parametros de entrada se muestran a continuacion:
        - text_size: Indica el tamaño del texto. El valor minimo es 1
*/
void AMBOT::cambiarSizeTexto(uint8_t text_size){
    _OLED.setTextSize(text_size); 
}

/*
    Funcion que dibuja una linea recta horizontal en la pantalla OLED. No devuelve ningun valor.
    A continuacion se indican los parametros de entrada:
        - x_inicial: posicion de inicio en x de la recta.
        - y_inicial: posicion de inicio en y de la recta.
        - distancia: cantidad de pixeles en el eje x que se deben dibujar
*/
void AMBOT::dibujarRectaX(uint8_t x_inicial, uint8_t y_inicial, uint8_t distancia){
    _OLED.drawFastHLine(x_inicial, y_inicial , distancia, SSD1306_WHITE);
    _OLED.display();
}

/*
    Funcion que dibuja una linea recta vertical en la pantalla OLED. No devuelve ningun valor.
    A continuacion se indican los parametros de entrada:
        - x_inicial: posicion de inicio en x de la recta.
        - y_inicial: posicion de inicio en y de la recta.
        - distancia: cantidad de pixeles en el eje y que se deben dibujar
*/
void AMBOT::dibujarRectaY(uint8_t x_inicial, uint8_t y_inicial, uint8_t distancia){
    _OLED.drawFastVLine(x_inicial, y_inicial, distancia, SSD1306_WHITE);
    _OLED.display();
}

/*
    Funcion que borra toda la pantalla OLED. No requiere ni devuelve ningun parametro.
*/
void AMBOT::limpiarOled(){
    _OLED.clearDisplay();
}

