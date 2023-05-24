//Defining Pins
#define ledPin 7      // Digital pin
#define ldrPin A0      // Analog pin
/*Defining Registers */
#define ADMUX_REG 0x7C  // ADC Multiplexer Selection Register
#define ADCSRA_REG 0x7A // ADC Control and Status Register A
#define ADCL_REG 0x78   // ADC Low Byte Result Register
#define ADCH_REG 0x79   // ADC High Byte Result Register

void setup() {
  Serial.begin(9600);
  DDRD |= (1 << DDD7); // Using DDRD register (Digital Pin 7 corresponds to PD7)
  ADMUX = (1 << REFS0);   // Configure ADC reference voltage 
  ADCSRA = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Configure ADC clock prescaler (prescaler of 128 for 16MHz clock)
  ADCSRA |= (1 << ADEN);  // Enable ADC
}

void loop() {
  uint16_t ldrValue = analogRead(ldrPin);  //To read ldr values
  //To print ldr value
  Serial.println("");
  Serial.print("Light sensor");
  Serial.print("Value = ");
  Serial.print(ldrValue);
  // If LDR value is below a certain threshold, turn on the LED
  if (ldrValue < 50) {
    PORTD |= (1 << PORTD7); // Set LED pin HIGH
  } else {
    PORTD &= ~(1 << PORTD7); // Set LED pin LOW
  }
}
