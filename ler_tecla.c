#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "ler_tecla.h"

// Função para ler o teclado matricial correspondente com o que pede a tarefa
char ler_tecla() {
    const char matriz[4][4] = {
        {'1', '2', '3', TECLA_A},
        {'4', '5', '6', TECLA_B},
        {'7', '8', '9', TECLA_C},
        {TECLA_ESTRELA, '0', TECLA_HASH, TECLA_D}
    };

    for (int c = 0; c < 4; c++) {
        gpio_put(COL1, c == 0);
        gpio_put(COL2, c == 1);
        gpio_put(COL3, c == 2);
        gpio_put(COL4, c == 3);

        if (gpio_get(ROW1)) {
            sleep_ms(200);  
            return matriz[0][c];
        }
        if (gpio_get(ROW2)) {
            sleep_ms(200);  
            return matriz[1][c];
        }
        if (gpio_get(ROW3)) {
            sleep_ms(200);  
            return matriz[2][c];
        }
        if (gpio_get(ROW4)) {
            sleep_ms(200);  
            return matriz[3][c];
        }
    }
    return 0;
}