#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *value;
    char *type;
}card;

int main() {
    srand(time(NULL));
    int i, r;
    char name[4][9] = {{"diamonds"},{"clubs"},{"hearts"},{"spades"}};
    char number[13][6] = {{"ace"},{"two"},{"three"},{"four"},{"five"},{"six"},{"seven"},{"eight"},{"nine"},{"ten"},{"jack"},{"queen"},{"king"}};

    card c[52];
    card temp;

    for (i = 0; i < 52; i++) {
        c[i].type = name[i / 13];
        c[i].value = number[i % 13];
    }

    for (i = 0; i < 52; i++) {
        r = rand() % 52;
        temp = c[i];
        c[i] = c[r];
        c[r] = temp;
    }

    for (i = 0; i < 52; i++) {
        printf("%s %s\n", c[i].type, c[i].value);
    }

}

