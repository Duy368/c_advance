#include <stdio.h>
#include "led_driver.h"

int main()
{
    if (led_init(10) != 0)
    {
        printf("Init failed\n");
        return 1;
    }

    const uint32_t *buf = led_get_buffer();

    printf("Initial buffer:\n");
    for (int i = 0; i < 10; i++)
        printf("[%d] = 0x%08X\n", i, buf[i]);

    led_set_pixel_color(0, 255, 0, 0);
    led_set_pixel_color(9, 0, 0, 255);
    led_set_pixel_color(4, 255, 255, 255);

    printf("\nAfter setting colors:\n");
    printf("Pixel 0 = 0x%08X\n", buf[0]);
    printf("Pixel 4 = 0x%08X\n", buf[4]);
    printf("Pixel 9 = 0x%08X\n", buf[9]);

    led_fill(0, 255, 0);

    printf("\nAfter fill green:\n");
    for (int i = 0; i < 10; i++)
        printf("[%d] = 0x%08X\n", i, buf[i]);

    led_shutdown();
    return 0;
}
