// ---------------------- COCHECITO VERSION 2 --------------------------
// - START, ENTRA EN MENU DE PARAMETROS (TRIMAR Y MODIFICAR VARIABLES)
// - VARIABLES CAMBIADAS DEL MENU SE GUARDAN EN EEPROM
// - REORGANIZACION DEL CODIGO
// - CAMBIAR SERVO DE PIN 4 A PIN 8 PARA ORGANIZAR
// - L2, MANTENER PULSADO HACE QUE EL COCHE GIRE MENOS
// - PINES LIBRES: 3, 4, 13 (led), A0, A1, A2, A3, TX, RX
// ---------------------- COCHECITO VERSION 1 --------------------------
// - CONTROL DE SERVO DE DIRECCION
// - CONTROL PWM DE MOTOR
// - MANDO PS2 FUNCIONANDO
// - OLED FUNCIONANDO
// - R2, MANTENER PULSADO HACE QUE EL COCHE VAYA MAS DESPACIO 
// ---------------------------------------------------------------------
#include <SPI.h>
#include <Wire.h>
#include <EEPROM.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_SoftServo.h>
#include <PS2X_lib.h>
//------------------ DEFINICION DE PINES DEL CIRCUITO -------------------
#define SERVOPIN 8         // Pin de señal del servo de la direccion
#define PALANTE 5          // Pin del PWM del motor hacia adelante
#define PATRAS  6          // Pin del PWM del motor hacia atras
#define PS2_ATT 9          // Att del receptor del mando PS2
#define PS2_CLK 10         // Clock del receptor del mando PS2
#define PS2_CMD 11         // Command del receptor del mando PS2
#define PS2_DAT 12         // Data del receptor del mando PS2
//#define PRESSURES true     // Activamos la lectura analogica de los botones del mando
#define PRESSURES false    // Desactivamos la lectura analogica de los botones del mando
#define RUMBLE true        // Activamos la vibracion del mando
//#define RUMBLE false       // Desactivamos la vibracion del mando

#define OLED_RESET 4       // Pin de reset del display
Adafruit_SSD1306 display(OLED_RESET);  // Creamos un objeto display

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

PS2X ps2x; // creamos un objeto ps2x     

Adafruit_SoftServo Servo1; // creamos un objeto SERVO

//---------------------------- DEFINICION DE VARIABLES -----------------
//---------------------------- VARIABLES DEL MANDO PS2 -----------------
byte error = 0; // Tipo de error de conexion del mando PS2
byte type = 0; // Tipo de mando PS2 (dualshock, guitar hero...)
byte vibrate = 0; // Velocidad de vibracion del mando
//----------------------------- VARIABLES GENERALES --------------------
byte contador = 0; // Para ir contando ciclos de programa y ponerlos en el oled (en plan debug)
byte centroservo = EEPROM.read(0);    // 60 - Valor en el cual la direccion se queda centrada (recta)
byte servopos = centroservo; // Posicion de la direccion
byte servomin = EEPROM.read(1);  // 10 - Valor minimo de la posicion del servo (minimo mecanico)
byte servomax = EEPROM.read(2);       // 120 - Valor maximo de la posicion del servo (maximo mecanico)
byte servominL2 = EEPROM.read(3);        // 40 - Valor minimo de la posicion del servo (minimo mecanico)
byte servomaxL2 = EEPROM.read(4);       // 80 - Valor maximo de la posicion del servo (maximo mecanico)
byte velocidad = EEPROM.read(5); // 128 - Velocidad del motor del coche
byte velocidadmax = EEPROM.read(6); // 255 - Velocidad maxima del coche
byte velocidadmaxR2 = EEPROM.read(7); //128 - velocidad maxima con R2 pulsado
bool cfgmode = false; // Menu de configuracion
byte cfgpantalla = 0;  // Pantalla en la que estamos en el menu
byte menupos = 1; // Posicion en el menu de configuracion

void setup(){
  Serial.begin(9600);
  //---------------------------- COSAS DEL OLED -------------------------
  //  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.clearDisplay();
  display.display();
  delay(300);  // añadimos delay para que los perifericos (servo, oled, mando...) se configuren a gusto
  //config_gamepad(clock, command, attention, data, Pressures, Rumble) check for error
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_ATT, PS2_DAT, PRESSURES, RUMBLE);
  /*  
   error = 0 -> Found Controller, configured successful
   error = 1 -> No controller found
   error = 2 -> Controller found but not accepting commands.
   error = 3 -> Controller refusing to enter Pressures mode, may not support it.
   */
  type = ps2x.readType(); 
  /*
   type 0 -> Unknown Controller type found
   type 1 -> DualShock Controller found
   type 2 -> GuitarHero Controller found
   type 3 -> Wireless Sony DualShock Controller found
   */
  if(error != 0 || type != 1){  // Si el mando da error de conexion, configuracion, o es del tipo que no toca 
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("Error ");
    display.println(error);
    display.print("Type ");
    display.println(type);
    display.print("Reconectando...");
    display.display();
    delay(2000);
    setup();  // volvemos al principio
  }
  Servo1.attach(SERVOPIN);   // Relacionamos el servo al pin 4
  Servo1.write(centroservo); // Centramos la direccion
  delay(15);                 // Esperamos 15ms para que la direccion se centre
  Servo1.refresh();          // Esto hay que hacerlo cada vez que cambiamos algo
}

void loop() {
  ps2x.read_gamepad(false,vibrate);          // SUPER IMPORTANTE: Leer el estado de los botones (lo carga a un buffer o algo)
  if(ps2x.ButtonPressed(PSB_START)){
    pita();
    if(cfgmode == false){
      cfgmode = true;
    }
    else {
      cfgmode = false;
    }
  }
  
  if(cfgmode == true){
    configmode();
  }
  else{
  direccion();
  traccion();
  pantallaNormal();
  }
}

