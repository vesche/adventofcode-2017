#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INPUT "day11.input"

int distance(int x, int y, int z) {
    int max_xy;

    x = abs(x);
    y = abs(y);
    z = abs(z);

    if (abs(x) > abs(y))
        max_xy = abs(x);
    else
        max_xy = abs(y);

    if (max_xy > abs(z))
        return max_xy;
    else
        return abs(z);
}

int main()
{
    int i, x, y, z, farthest, d;
    i = x = y = z = farthest = 0;

    FILE *fp;
    char *line = NULL;
    size_t len = 0;

    fp = fopen(INPUT, "r");
    if (fp == NULL) {
        perror(INPUT);
        exit(1);
    }

    while (getline(&line, &len, fp) != -1) {
        line[strcspn(line, "\r\n")] = 0;

        char *p = strtok(line, ",");

        while (p != NULL) {
            if (strcmp(p, "n") == 0) {
                x += 1;
                y -= 1;
            } else if (strcmp(p, "s") == 0) {
                x -= 1;
                y += 1;
            } else if (strcmp(p, "ne") == 0) {
                x += 1;
                z -= 1;
            } else if (strcmp(p, "nw") == 0) {
                y -= 1;
                z += 1;
            } else if (strcmp(p, "se") == 0) {
                y += 1;
                z -= 1;
            } else if (strcmp(p, "sw") == 0) {
                x -= 1;
                z += 1;
            }

            d = distance(x, y, z);
            if (d > farthest)
                farthest = d;
            p = strtok(NULL, ",");
        }
    }

    printf("%d %d\n", distance(x, y, z), farthest);
    return 0;
}
