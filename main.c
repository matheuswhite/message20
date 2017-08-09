#include "message20.h"

int main() {
    package_t pack;
    addCommand(&pack, A1, 0b00000111);
    addCommand(&pack, A2, 0b1);
    addCommand(&pack, S1, 0x12);
    addCommand(&pack, S2, 0x1254);

    to_string(&pack);

    return 0;
}
