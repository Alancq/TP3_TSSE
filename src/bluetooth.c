#include "bluetooth.h"
#include <string.h>

bool bluetooth_init(void) {
    return true;
}

int bluetooth_send(const char *data, size_t length) {
    if (data == NULL) {
        return -1;
    }
    return (int)length;
}

bool bluetooth_close(void) {
    return true;
}
