#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LED_GPIO 2


void app_main(void)
{
    gpio_pad_select_gpio(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    int pattern = 0;

    while(1) {
        switch(pattern) {
            case 0:
                gpio_set_level(LED_GPIO, 1);
                vTaskDelay(1000 / portTICK_PERIOD_MS);
                gpio_set_level(LED_GPIO, 0);
                vTaskDelay(4000 / portTICK_PERIOD_MS);
                break;
            case 1:
                gpio_set_level(LED_GPIO, 1);
                vTaskDelay(2000 / portTICK_PERIOD_MS);
                gpio_set_level(LED_GPIO, 0);
                vTaskDelay(3000 / portTICK_PERIOD_MS);
                break;
            case 2:
                gpio_set_level(LED_GPIO, 1);
                vTaskDelay(3000 / portTICK_PERIOD_MS);
                gpio_set_level(LED_GPIO, 0);
                vTaskDelay(2000 / portTICK_PERIOD_MS);
                break;
        }
        pattern = (pattern + 1) % 3;
    }
}

int main() {
    char *alphabet = malloc(27 * sizeof(char));
    strcpy(alphabet, "abcdefghijklmnopqrstuvwxyz");

    for (int i = 0; i < 10; i++) {
        printf("%s\n", alphabet);
        char temp = alphabet[0];
        memmove(alphabet, alphabet + 1, 25);
        alphabet[25] = temp;
    }

    free(alphabet);
    return 0;
}