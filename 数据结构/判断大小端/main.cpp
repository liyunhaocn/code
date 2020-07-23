#include <stdio.h>

int main() {

    int i = 0x87654321;
    char *p;
    p = (char *) &i;
    if (*p == 0x21) {
        printf("这是小端存储\n");
    }
    else {
        printf("这是大端存储\n");
    }
    return 0;
}
