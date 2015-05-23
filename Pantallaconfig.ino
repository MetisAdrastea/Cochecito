void pantallaconfig(byte cfgpantalla){
 byte v2 = velocidadmaxR2;
 byte smin = servominL2;
 byte smax = servomaxL2;
 byte c2 = centroservo;
 bool bucle = true;
 display.clearDisplay();       // Limpiamos la pantalla
 display.setTextColor(WHITE);  // Color de texto blanco
 display.setTextSize(2);       // Texto grande
 display.setCursor(0, 0);      // Empezamos arriba a la izquierda (x-y)
 display.println("  CONFIG");
 display.setTextSize(1);
 switch(cfgpantalla){
   case 0: 
     if(menupos == 1)
       display.setTextColor(BLACK, WHITE);
     display.println("-Velocidad R2");
     display.setTextColor(WHITE);
     if(menupos == 2)
       display.setTextColor(BLACK, WHITE);
     display.println("-Minimo direccion R1"); 
     display.setTextColor(WHITE);
     if(menupos == 3)
       display.setTextColor(BLACK, WHITE);
     display.println("-Maximo direccion R1"); 
     display.setTextColor(WHITE);
     if(menupos == 4)
       display.setTextColor(BLACK, WHITE);
     display.println("-Centro de direccion");  
     display.setTextColor(WHITE) ;
     if(menupos == 5 )
       display.setTextColor(BLACK, WHITE);
     display.println("-Valores por defecto"); 
     display.setTextColor(WHITE);
     if(menupos == 6)
       display.setTextColor(BLACK, WHITE);
     display.println("- Volver"); 
     display.setTextColor(WHITE);
     display.display();
     break;
     
   case 1:  // Menu velocidad R2
     while(bucle){
       ps2x.read_gamepad(false,0);
       delay(100);
       display.clearDisplay();       // Limpiamos la pantalla
       display.setTextColor(WHITE);  // Color de texto blanco
       display.setTextSize(2);       // Texto grande
       display.setCursor(0, 0);      // Empezamos arriba a la izquierda (x-y)
       display.println("  CONFIG");
       display.setTextSize(1);
       display.println("");
       display.println("Velocidad MAX R2: ");
       display.println("");
       display.setTextSize(2);
       display.print("   ");
       display.println(v2);
       display.display();
       if(ps2x.Button(PSB_PAD_UP)){
         pita();
         if(v2 < 255){
           v2 = v2 + 1;
         }
       }
       if(ps2x.Button(PSB_PAD_DOWN)){
         pita();
         if(v2 != 0){
           v2 = v2 - 1;
         }
       }
       if(ps2x.ButtonPressed(PSB_CROSS)){
         pita();
         velocidadmaxR2 = v2;
         if(EEPROM.read(7) != velocidadmaxR2)
         EEPROM.write(7, velocidadmaxR2);
         bucle = false;
       }
       if(ps2x.ButtonPressed(PSB_CIRCLE)){
         pita();
         bucle = false;
       }
     }
     break;

   case 2:  // Menu Minimo Direccion L2
     Servo1.write(servominL2);
     Servo1.refresh();
     while(bucle){
       ps2x.read_gamepad(false,0);
       delay(100);
       display.clearDisplay();       // Limpiamos la pantalla
       display.setTextColor(WHITE);  // Color de texto blanco
       display.setTextSize(2);       // Texto grande
       display.setCursor(0, 0);      // Empezamos arriba a la izquierda (x-y)
       display.println("  CONFIG");
       display.setTextSize(1);
       display.println("");
       display.print("Giro MIN L2: ");
       display.println("");
       display.setTextSize(2);
       display.print("   ");
       display.println(smin);
       display.display();
       if(ps2x.Button(PSB_PAD_UP)){
         pita();
         if(smin < 180){
           smin = smin + 1;
           Servo1.write(smin);
           Servo1.refresh();
         }
       }
       if(ps2x.Button(PSB_PAD_DOWN)){
         pita();
         if(smin != 0){
           smin = smin - 1;
           Servo1.write(smin);
           Servo1.refresh();
         }
       }
       if(ps2x.ButtonPressed(PSB_CROSS)){
         pita();
         servominL2 = smin;
         if(EEPROM.read(3) != servominL2)
         EEPROM.write(3, servominL2);
         bucle = false;
       }
       if(ps2x.ButtonPressed(PSB_CIRCLE)){
         pita();
         bucle = false;
       }
     }
     break;

   case 3:  // Menu Maximo Direccion L2
     Servo1.write(servomaxL2);
     Servo1.refresh();
     while(bucle){
       ps2x.read_gamepad(false,0);
       delay(100);
       display.clearDisplay();       // Limpiamos la pantalla
       display.setTextColor(WHITE);  // Color de texto blanco
       display.setTextSize(2);       // Texto grande
       display.setCursor(0, 0);      // Empezamos arriba a la izquierda (x-y)
       display.println("  CONFIG");
       display.setTextSize(1);
       display.println("");
       display.print("Giro MAX L2: ");
       display.println("");
       display.setTextSize(2);
       display.print("   ");
       display.println(smax);
       display.display();
       if(ps2x.Button(PSB_PAD_UP)){
         pita();
         if(smax < 180){
           smax = smax + 1;
           Servo1.write(smax);
           Servo1.refresh();
         }
       }
       if(ps2x.Button(PSB_PAD_DOWN)){
         pita();
         if(smax != 0){
           smax = smax - 1;
           Servo1.write(smax);
           Servo1.refresh();
         }
       }
       if(ps2x.ButtonPressed(PSB_CROSS)){
         pita();
         servomaxL2 = smax;
         if(EEPROM.read(4) != servomaxL2)
         EEPROM.write(4, servomaxL2);
         bucle = false;
       }
       if(ps2x.ButtonPressed(PSB_CIRCLE)){
         pita();
         bucle = false;
       }
     }
     break;

   case 4:  // Menu centro de direccion
     Servo1.write(centroservo);
     Servo1.refresh();
     while(bucle){
       ps2x.read_gamepad(false,0);
       delay(100);
       display.clearDisplay();       // Limpiamos la pantalla
       display.setTextColor(WHITE);  // Color de texto blanco
       display.setTextSize(2);       // Texto grande
       display.setCursor(0, 0);      // Empezamos arriba a la izquierda (x-y)
       display.println("  CONFIG");
       display.setTextSize(1);
       display.println("");
       display.print("Centro de direccion: ");
       display.println("");
       display.setTextSize(2);
       display.print("   ");
       display.println(c2);
       display.display();
       if(ps2x.Button(PSB_PAD_UP)){
         pita();
         if(c2 < 180){
           c2 = c2 + 1;
           Servo1.write(c2);
           Servo1.refresh();
         }
       }
       if(ps2x.Button(PSB_PAD_DOWN)){
         pita();
         if(c2 != 0){
           c2 = c2 - 1;
           Servo1.write(c2);
           Servo1.refresh();
         }
       }
       if(ps2x.ButtonPressed(PSB_CROSS)){
         pita();
         centroservo = c2;
         if(EEPROM.read(0) != centroservo)
         EEPROM.write(0, centroservo);
         bucle = false;
       }
       if(ps2x.ButtonPressed(PSB_CIRCLE)){
         pita();
         bucle = false;
       }
     }
     break;

   case 5:  // Valores por defecto
       display.clearDisplay();       // Limpiamos la pantalla
       if(EEPROM.read(0) != 60)
       EEPROM.write(0, 60);  // centroservo
       if(EEPROM.read(1) != 10)
       EEPROM.write(1, 10);  // servomin
       if(EEPROM.read(2) != 120)
       EEPROM.write(2, 120);  //servomax
       if(EEPROM.read(3) != 40)
       EEPROM.write(3, 40);  //servominL2
       if(EEPROM.read(4) != 80)
       EEPROM.write(4, 80);  //servomaxL2
       if(EEPROM.read(5) != 128)
       EEPROM.write(5, 128);  // velocidad
       if(EEPROM.read(6) != 255)
       EEPROM.write(6, 255);  // velocidadmax
       if(EEPROM.read(7) != 128)
       EEPROM.write(7, 128);  // velocidadmaxR2
       centroservo = 60;
       servomin = 10;
       servomax = 120;
       servominL2 = 40;
       servomaxL2 = 80;
       velocidad = 128;
       velocidadmax = 255;
       velocidadmaxR2 = 128;
       display.display();
     break;

 }
}
