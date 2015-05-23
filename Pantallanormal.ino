void pantallaNormal(){
 // -------------------- PANTALLA OLED ------------------------------------
  display.clearDisplay();                    // Limpiamos la pantalla
  display.setTextColor(WHITE);               // Color de texto blanco
  display.setTextSize(1);                    // Texto pequeñito
  display.setCursor(0, 0);                   // Empezamos arriba a la izquierda (x-y)
  puntitos();                                // Llamamos a la funcion de heartbeat de los puntitos
  display.print("servo: ");
  display.println(servopos);
  display.print("spd: ");
  if (ps2x.Analog(PSS_LY) == 127){           // Si soltamos el stick izquierdo
  }
  else if (ps2x.Analog(PSS_LY) < 127){       // Si tiramos hacia atras del stick izquierdo 
  display.print("+");
  }
  else if (ps2x.Analog(PSS_LY) > 127){       // Si empujamos hacia adelante el stick izquierdo 
  display.print("-");
  }
  display.println(velocidad);
  display.drawLine(0, 25, 127, 25, WHITE);
  display.drawLine(60, 0, 60, 25, WHITE);

  display.setCursor(64, 0);
  display.print("Sticks:");
  display.setCursor(64, 8);
  display.print(ps2x.Analog(PSS_LX), DEC);  // Valor de eje X de stick izquierdo  
  display.print(" ");
  display.print(ps2x.Analog(PSS_LY), DEC);  // Valor de eje Y de stick izquierdo 
  display.setCursor(64, 16);
  display.print(ps2x.Analog(PSS_RY), DEC);  // Valor de eje X de stick derecho
  display.print(" ");
  display.print(ps2x.Analog(PSS_RX), DEC);  // Valor de eje Y de stick derecho
  display.setCursor(0, 27);
  display.print("Error:");
  display.println(error);
  display.print("Type: ");
  display.println(type);
  display.print("Vibrate: ");
  display.println(vibrate);
  if(ps2x.Button(PSB_L1)){
    display.setCursor(115,27);
    display.print("L1");
  }
  if(ps2x.Button(PSB_R1)){
    display.setCursor(115,35);
    display.print("R1");
  }
  if(ps2x.Button(PSB_L2)){
    display.setCursor(115,43);
    display.print("L2");
  }
  if(ps2x.Button(PSB_R2)){
    display.setCursor(115,51);
    display.print("R2");
  }
  display.display();
}


void puntitos(){
    switch(contador) {
  case 0:
    display.println(".");
    break;
  case 1:
    display.println("..");
    break;
  case 2:
    display.println("...");
    break;
  case 3:
    display.println(" ...");
    break;
  case 4:
    display.println("  ...");
    break;
  case 5:
    display.println("   ...");
    break;
  case 6:
    display.println("    ...");
    break;
  case 7:
    display.println("     ...");
    break;
  case 8:
    display.println("      ..");
    break;
  case 9:
    display.println("       .");
    contador = 0;
    break;
  }
  contador = contador +1;  
}
