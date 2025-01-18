#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "controle_leds.h"

void controle_leds(char tecla) {
    gpio_put(LED_VERDE_PIN, 0);
    gpio_put(LED_AZUL_PIN, 0);
    gpio_put(LED_VERMELHO_PIN, 0);

    if (tecla == TECLA_A) {
        gpio_put(LED_VERDE_PIN, 1);  // Liga o LED verde
    } else if (tecla == TECLA_B) {
        gpio_put(LED_AZUL_PIN, 1);   // Liga o LED azul
    } else if (tecla == TECLA_C) {
        gpio_put(LED_VERMELHO_PIN, 1);  // Liga o LED vermelho
    } else if (tecla == TECLA_D) {
        gpio_put(LED_VERDE_PIN, 1);  // Liga todos os LEDs
        gpio_put(LED_AZUL_PIN, 1);
        gpio_put(LED_VERMELHO_PIN, 1);
    }
}
