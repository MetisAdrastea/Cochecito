void configmode(){             // MODO CONFIGURACION 
 cfgpantalla = 0;              // Seteamos pantalla inicial (menu principal)
 analogWrite(PALANTE, 0);                     // Apagamos motores
 analogWrite(PATRAS, 0);
 vibrate = 0;                                 // Quitamos vibracion del mando
 Servo1.write(centroservo);                   // Centramos direccion
 Servo1.refresh();
 delay(15);
 ps2x.read_gamepad(false,vibrate);            // SUPER IMPORTANTE: Leer el estado de los botones (lo carga a un buffer o algo)
 if(ps2x.Button(PSB_PAD_DOWN)){
   pita();
   menupos = menupos +1;
 }
 if(ps2x.Button(PSB_PAD_UP)){
   pita();
   menupos = menupos -1;
 }
 if(menupos == 0)                          // Si estamos en el primero (1) y damos arriba (1-1=0)
   menupos = 6;                            // Pasamos al ultimo
 if(menupos == 7)                          // Si estamos en el ultimo (6) y damos abajo (6+1=7)
   menupos = 1;                            // Pasamos al primero
 if(ps2x.ButtonPressed(PSB_CROSS)){        // Cuando pulsamos X
   pita();
   if(menupos == 6){                       // Si aceptamos (boton X) estando en el menu VOLVER (6)
   cfgmode = false;                        // Salimos de configuracion
   return;
   }
   cfgpantalla = menupos;                  // Si estamos en otro menu, vamos a la pantalla correspondiente
 }
 if(ps2x.ButtonPressed(PSB_CIRCLE)){       // Si pulsamos Circulo
   pita();
   cfgmode = false;                        // Salimos de configuracion
   return;
 }

 pantallaconfig(cfgpantalla);              // Vamos a la pantalla asignada cuando hemos pulsado X

}

void pita(){                               // Funcion que hace pitar mediante el driver de motor
 analogWrite(PALANTE, 20);                 // Activamos un PWM bajo para que las ruedas no empujen
 delay(100);                               // durante 100 ms
 analogWrite(PALANTE, 0);                  // Apagamos el driver
 delay(100);                               // Esperamos otros 100 ms por si vuelven a llamar a la funcion 
}
