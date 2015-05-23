void traccion(){
// -------------------- EMPUJE MOTOR ------------------------------------
  velocidad = ps2x.Analog(PSS_LY); // Leemos el valor del eje Y del stick izquierda
  if(ps2x.Button(PSB_R2)){             // Si R2 esta pulsado
    velocidadmax = velocidadmaxR2;     // Cambiamos el valor de velocidadmax
  }
  else {                               // Si no
    velocidadmax = 255;                // Ponemos el tope de velocidad a 255
  }

  if (velocidad == 127){               // Si soltamos el stick izquierdo
  velocidad = 0;                       // La velocidad del coche es 0
  analogWrite(PALANTE,0);              // Ni palante
  analogWrite(PATRAS,0);               // Ni patras :-)
  }
  else if (velocidad < 127){           // Si tiramos hacia atras del stick izquierdo 
    velocidad= map(velocidad, 127, 0, 0, velocidadmax); // Escalamos de 0-127 a 0-velocidadmax
    analogWrite(PALANTE,velocidad);
    analogWrite(PATRAS, 0);
  }
  else if (velocidad > 127){           // Si empujamos hacia adelante el stick izquierdo 
    velocidad= map(velocidad, 127, 255, 0, velocidadmax); // Escalamos de 127-255 a 0-velocidadmax 
    analogWrite(PALANTE, 0);
    analogWrite(PATRAS, velocidad);
  }
}
