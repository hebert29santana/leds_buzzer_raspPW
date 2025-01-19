/*
    Tarefa 1 Unidade 4 - Aula Síncrona 14/01
    Grupo 7
    Subgrupo 6
    Hebert Costa Vaz Santana - TIC370101235
    Welton Almeida de Matos - TIC370100649
    Maria Valentina da Luz Mattos Baracat Habib - TIC370101020
    Gustavo Ferreira Santos - TIC370101484
    Igor Emanuel Soares Leal - TIC370101965
*/

#include "stdio.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "controle_buzzer.h"
#include "controle_leds.h"
#include "ler_tecla.h"
#include "teclado_init.h"

// Definições dos pinos dos LEDs e do buzzer
#define LED_VERDE_PIN 11
#define LED_AZUL_PIN 12
#define LED_VERMELHO_PIN 13
#define BUZZER_PIN 21

// Definições das teclas
#define TECLA_A 'A'
#define TECLA_B 'B'
#define TECLA_C 'C'
#define TECLA_D 'D'
#define TECLA_HASH '#'
#define TECLA_ESTRELA '*'

int main() {
    // Configura os pinos dos LEDs e do buzzer como saída
    gpio_init(LED_VERDE_PIN); gpio_set_dir(LED_VERDE_PIN, GPIO_OUT);
    gpio_init(LED_AZUL_PIN); gpio_set_dir(LED_AZUL_PIN, GPIO_OUT);
    gpio_init(LED_VERMELHO_PIN); gpio_set_dir(LED_VERMELHO_PIN, GPIO_OUT);
    gpio_init(BUZZER_PIN); gpio_set_dir(BUZZER_PIN, GPIO_OUT);

    // Inicializa o teclado
    teclado_init();

    // Desliga tudo no início
    gpio_put(LED_VERDE_PIN, 0);
    gpio_put(LED_AZUL_PIN, 0);
    gpio_put(LED_VERMELHO_PIN, 0);
    gpio_put(BUZZER_PIN, 0);

    // Loop principal
    while (true) {
        char tecla = ler_tecla();  // Lê a tecla pressionada

        if (tecla) {
            if (tecla == TECLA_ESTRELA) {
                gpio_put(LED_VERDE_PIN, 0);  
                gpio_put(LED_AZUL_PIN, 0);
                gpio_put(LED_VERMELHO_PIN, 0);
                gpio_put(BUZZER_PIN, 0);  
                printf("Programa finalizado\n");
                break;  
            }

            controle_leds(tecla);  // Controla os LEDs
            controle_buzzer(tecla);  // Controla o buzzer
        }

        sleep_ms(100);  // Aguarda um pouco antes de ler a próxima tecla
    }

    return 0;
}