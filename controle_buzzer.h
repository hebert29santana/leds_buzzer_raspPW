#ifndef CONTROLE_BUZZER_H
#define CONTROLE_BUZZER_H

#include "pico/stdlib.h"

#define BUZZER_PIN 21
#define BUZZER_FREQ_HZ 3200

void start_buzzer(uint32_t duration_ms);
void controle_buzzer(char tecla);

#endif
