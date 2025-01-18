//aqui é atuação do metodo principal
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

        if (tecla) {  // Se uma tecla foi pressionada
            controle_leds(tecla);  // Controla os LEDs
            controle_buzzer(tecla);  // Controla o buzzer
        }

        sleep_ms(100);  // Aguarda um pouco antes de ler a próxima tecla
    }

    return 0;
}