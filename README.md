# Libreria de AMBOT
Esta libreria ha sido creada por Academia Makerpara utilizar y programar el robot educativo "AMBOT". Esta libreria incorpora todos lo necesario para utilizar cada uno de los componentes disponibles en la pcb del robot.
## Modo de empleo
Una vez instalada la libreria en el IDE de Arduino, debes incluir esta libreria al comienzo del código, con la siguiente sentencia:
```cpp
# include <AMBOT.h>
```
### Constructor
Debes crear una instancia de la clase AMBOT con el nombre que quieras usar para identificar dicha clase. En el siguiente ejemplo se va a llamar "AMBot". En este caso particular no se debe dar ningun parametro de entrada. 
```cpp
AMBOT AMBot;
```
Ahora podemos acceder a todos los metodos y atributos de la clase AMBOT

### Metodos de la clase
| Nombre | Descripcion | Parametros |
| -------- | ----------- | ---------- |
|`void inicializarAMBot();`| Función que inicializa todos los componentes del AMBOT| Esta función no requiere parametros de entrada|
| `bool leerPulsador(pulsador);` | Función que devuelve el estado lógico de un pulsador | `uint8_t pulsador`: Pulsador del cual se desea conocer el estado (1 - 9)|
| `void sonarTono(frecuencia, tiempo);` | Función que emite un sonido a una frecuencia dada durante un tiempo |  `uint16_t frecuencia`: Frecuencia del sonido<br>`uint16_t tiempo`: Tiempo de emision del sonido |
| `uint16_t leerLDR();` | Función que devuelve el valor analógico de la LDR | Esta función no requiere parametros de entrada|
| `void cambiarColorLeds(LED, Red, Green, Blue);` | Función que cambia el color de un led RGB de la pcb | `uint8_t LED`: Led seleccionado<br> `uint8_t Red`: Cantidad de rojo (0 - 255)<br> `uint8_t Green`: Cantidad de verde (0 - 255)<br> `uint8_t Blue`: Cantidad de azul (0 - 255) |
|`void cambiarBrillo(Brillo);`| Función que permite cambiar el brillo de los leds RGB | `uint8_t Brillo`: Asigna la cantidad de brillo (0 - 255) |
| `void actualizarLeds();` | Función que actualiza todos los cambios hechos en los leds | Esta función no requiere parametros de entrada |
| `void moverServo(servo, posicion);` | Función que cmabia la posición del servo indicado | `uint8_t servo`: Servo que debe cambiar de posicion<br> `int posicion`: Posición en grados a la cual se quiere fijar el servo |
| `void moverRobot(sentido,  cantidad);` | Función que activa los motores para mover el AMBOT hacia adelante o hacia atras |  `uint8_t sentido`: Sentido de marcha del robot (alante o atras)<br> `uint8_t cantidad`: Cantidad de cm que debe moverse el robot. |
| `void girarRobot(sentido,  cantidad);` | Función que activa los motores para girar el AMBOT | `uint8_t sentido`: Sentido de giro del robot(horario o antihorario)<br> `uint8_t cantidad`: Cantidad de grados que debe girar el robot |
| `uint8_t obtenerDistancia();` | Función que devuelve la distancia a la cual hay un objeto | Esta función no requiere parametros de entrada |
| `leerSiguelineas(siguelineas);` | Función que devuelve el estado lógico de uno de los dos sensores siguelineas presentes en el robot. | `uint8_t siguelineas`: Selecciona el siguelineas que se desea evaluar |
| `void escribirOled(texto);` | Escribe el texto indicado en la pantalla OLED | `String texto`: Texto que se desa imprimir en la pantalla |
| `void seleccionarCursor(posicion_x, posicion_y);` | Indica la posición en la cual se va a colocar el cursor para imprimir el texto | `uint8_t posicion_x`: Posición en el eje x<br> `uint8_t posicion_y`: Posición en eje y | 
| `void cambiarSizeTexto(text_size);` | Función que cambia el tamaño del texto | `uint8_t text_size`: Tamaño del texto |
| `void dibujarRectaX(x_inicial, y_inicial, distancia);` | Función que dibuja una línea recta horizontal de un tamaño definido | `uint8_t x_inicial`: Posición en x del punto inicial<br> `uint8_t y_inicial`: Posición y del punto inicial<br> `uint8_t distancia`: Longitud de la linea horizontal |
| `void dibujarRectaY(x_inicial, y_inicial, distancia);` | Función que dibuja una línea recta vertical de un tamaño definido | `uint8_t x_inicial`: Posición en x del punto inicial<br> `uint8_t y_inicial`: Posición y del punto inicial<br> `uint8_t distancia`: Longitud de la linea vertical |
| `void limpiarOled();` | Función que borra toda la pantalla OLED | Esta función no requiere parametros de entrada|

### Atributos de la clase
| Nombre | Descripcion |
| ------ | ----------- |
| `AMBOT.servo_motor_1` | Este atributo indica que se debe seleccionar el servo 1 |
| `AMBOT.servo_motor_2` | Este atributo indica que se debe seleccionar el servo 2 |
| `AMBOT.motores_alante` | Este atributo indica que el robot debe moverse hacia delante | 
| `motores_atras` | Este atributo indica que el robot debe moverce hacia atrás | 
| `sentido_horario` | Este atributo indica que el robot debe girar en sentido horario | 
| `sentido_antihorario` | Este atributo indica que el robot debe girar en sentido antihorario |
| `siguelineas_izquierdo` | Este atributo indica que se debe evaluar el estado del siguelineas izquierdo |
| `siguelineas_derecho` | Este atributo indica que se debe evaluar el estado del siguelineas derecho |