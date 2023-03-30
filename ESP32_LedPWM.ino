// Uso de PWM para encender un led

const int ledPin = 32; 

// Propiedades de PWM
const int freq = 5000;
const int CanalPWM = 0;
const int resolucion = 8;
 
void setup(){
  // configuro la funcionalidad del LED a controlar por PWM 
  // Estableceremos un canal, el 0 (se puede establecer desde el 0 al 15)
  // Todos los pines IO pueden actuar como salida (menos del 34 al 39)
  // La resolucion sera de 8 bits (256 valores)
  ledcSetup(CanalPWM, freq, resolucion);
  
  // Defino en que pin estara el LED
  ledcAttachPin(ledPin, CanalPWM);
}
 
void loop(){
  // incremento el brillo del LED
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    ledcWrite(CanalPWM, dutyCycle);
    delay(15);
  }

  // disminuyo el brillo del LED
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    ledcWrite(CanalPWM, dutyCycle);   
    delay(15);
  }
}
