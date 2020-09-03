/*
  Analog input, analog output, serial output
  Reads an analog input pin, maps the result to a
  range from 0 to 255  and uses the result to set
  the pulsewidth modulation (PWM) of an output
  pin.  Also prints the results to the serial
  monitor.
  The circuit:
  * potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to the
    analog pin. side pins of the potentiometer go
    to +5V and ground
  * LED connected from digital pin 9 to ground
  created 29 Dec. 2008
  modified 9 Apr 2012
  by Tom Igoe
  This example code is in the public domain.
*/

/*Se inicializan variables:*/
int sensorValue = 0;

int outputValue = 0;

void setup()
{
  /*Se asignan los pines a utilizar como entrada y salida*/
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  /*Se establece la comunicación serial a la placa con una velocidad de 9600 bits por segundo*/
  Serial.begin(9600);
}

void loop()
{
  // read the analog in value:
  /*Se establece la variable (sensorValue) que contendrá la lectura analógica*/
  sensorValue = analogRead(A0);
  // map it to the range of the analog out:
  /*Se establece una variable (outputValue) que contendra al valor entregado por la función map de la variable sensorValue*/
  /*La función map transforma al sensorValue, comprendido entre los valores 0 y 1023, en su equivalente para un intervalo entre 0 y 255*/
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  /*Se cambia la salida analogica del pin 9 por el valor de outputValue*/
  analogWrite(9, outputValue);
  // print the results to the serial monitor:
  /*Por  pantalla son entregados los valores obtenidos en la lectura analógica y el resultado de pasar por la función map*/
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
  // wait 2 milliseconds before the next loop for the
  // analog-to-digital converter to settle after the
  // last reading:
  /*Se determina un tiempo de espera antes de repetir el código*/
  delay(2); // Wait for 2 millisecond(s)
}
