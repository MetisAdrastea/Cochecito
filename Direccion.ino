void direccion(){
  
 // -------------------- SERVO DIRECCION ------------------------------------
  servopos =  ps2x.Analog(PSS_RX);           // Leemos el valor del eje X del stick derecho
  servopos = map(servopos, 0, 255, 179, 0);  // lo escalamos para usarlo con servopos (de 0-255 a 179-0) (invertido por la mecanica de la direccion)
  if(ps2x.Button(PSB_L2)){             // Si R2 esta pulsado
  servopos = constrain(servopos, servominL2, servomaxL2);   // y lo restringimos porque la direccion del cochecito es una mierda
  }
  else {                               // Si no
  servopos = constrain(servopos, servomin, servomax);   // y lo restringimos porque la direccion del cochecito es una mierda
  }

  if(ps2x.Analog(PSS_RX) == 128)                        // Si el stick esta centrado
    servopos = centroservo;                  // Centramos la direccion
  vibrate = 0;
  if(servopos == servomax | servopos == servomin)
  vibrate = 200;
  Servo1.write(servopos);
  Servo1.refresh();
  delay(30);
}
