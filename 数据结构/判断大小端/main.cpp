#include <stdio.h>

int main() {

    int i = 0x87654321;
    char *p;
    p = (char *) &i;
    if (*p == 0x21) {
        printf("����С�˴洢\n");
    }
    else {
        printf("���Ǵ�˴洢\n");
    }
    return 0;
}
