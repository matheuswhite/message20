#ifndef MESSAGE_20_H
#define MESSAGE_20_H

#ifdef DEBUG
#include <stdio.h>
#define debug(fmt, ...) printf("[%s] " fmt "\n", __FILE__, ## __VA_ARGS__);
#else
#define debug(fmt, ...)
#endif
#include <stdint.h>
#include <string.h>

typedef uint16_t command_t;

typedef enum {
    A1,
    A2,
    S1,
    S2
} device_t;

typedef union {
    uint8_t data[20];
    struct {
        unsigned int  enable_a1 :  1;
        unsigned int command_a1 :  8;
        unsigned int  enable_a2 :  1;
        unsigned int command_a2 :  1;
        unsigned int  enable_s1 :  1;
        unsigned int command_s1 :  8;
        unsigned int  enable_s2 :  1;
        unsigned int command_s2 : 10;
    } field;
} package_t;

void addCommand(package_t *pack, device_t dev, command_t cmd);
void decode(package_t *pack, uint8_t *raw);
void to_string(package_t *pack);

#endif //MESSAGE_20_H
