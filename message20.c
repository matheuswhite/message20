#include "message20.h"

void addCommand(package_t *pack, device_t dev, command_t cmd) {
    switch (dev) {
        case A1:
            pack->field.enable_a1  =   1;
            pack->field.command_a1 = cmd;
            break;
        case A2:
            pack->field.enable_a2  =   1;
            pack->field.command_a2 = cmd;
            break;
        case S1:
            pack->field.enable_s1  =   1;
            pack->field.command_s1 = cmd;
            break;
        case S2:
            pack->field.enable_s2  =   1;
            pack->field.command_s2 = cmd;
            break;
    }
}

void decode(package_t *pack, uint8_t *raw) {
    memcpy(pack->data, raw, 20);
}

void to_string(package_t *pack) {
    if (pack->field.enable_a1) {
        debug("CommandA1: %x", pack->field.command_a1);
    }
    if (pack->field.enable_a2) {
        debug("CommandA2: %x", pack->field.command_a2);
    }
    if (pack->field.enable_s1) {
        debug("CommandS1: %x", pack->field.command_s1);
    }
    if (pack->field.enable_s2) {
        debug("CommandS2: %x", pack->field.command_s2);
    }
}
