#include <Arduino.h>
#include "soc/gpio_reg.h"
#include "driver/gpio.h"

#define LED_PIN 2
#define DELAY 1000  // Ajuste del delay a 1000 ms según la solicitud

void setup() {
    Serial.begin(115200);  // Iniciar la comunicación serie a 9600 baudios
    gpio_pad_select_gpio(LED_PIN);
    gpio_set_direction((gpio_num_t)LED_PIN, GPIO_MODE_OUTPUT);
}

void loop() {
    uint32_t *gpio_out = (uint32_t *)GPIO_OUT_REG; // Puntero al registro de salida
    *gpio_out |= (1 << LED_PIN);  // Encender LED
    Serial.println("ON");  // Enviar mensaje "ON" por el puerto serie
    delay(DELAY);  // Esperar 1000 ms
    
    *gpio_out &= ~(1 << LED_PIN);  // Apagar LED
    Serial.println("OFF");  // Enviar mensaje "OFF" por el puerto serie
    delay(DELAY);  // Esperar 1000 ms
}
