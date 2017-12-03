#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "day03.input"

int part1(int goal)
{
    int x, y, dx, dy, step, dxtmp;
    x = y = dx = step = 0;
    dy = -1;

    for (;;) {
        step += 1;
        if (goal == step)
            return abs(x) + abs(y);

        if ((x == y) || ((x < 0) && (x == -y)) || ((x > 0) && (x == 1-y))) {
            dxtmp = dx;
            dx = -dy;
            dy = dxtmp;
        }
        x += dx;
        y += dy;
    }
}

int part2(int goal)
{
    int x, y, dx, dy, dxtmp, step, total, i, j, tx, ty;
    x = y = dx = 0;
    dy = -1;

    int array[1000][3];
    int coords[8][2] = {{1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}};

    for (i = 0; i < 1000; i++) {
        array[i][0] = 0;
        array[i][1] = 0;
        array[i][2] = 0;
    }

    for (;;) {
        total = 0;
        for (i = 0; i < 1000; i++) {
            tx = array[i][0];
            ty = array[i][1];
            for (j = 0; j < 8; j++) {
                if ((x+coords[j][0] == tx) && (y+coords[j][1] == ty))
                    total += array[i][2];
            }
        }
        if ((x == 0) && (y == 0)) {
            array[step][0] = 0;
            array[step][1] = 0;
            array[step][2] = 1;
        }
        else {
            array[step][0] = x;
            array[step][1] = y;
            array[step][2] = total;
        }

        if (total > goal) {
            return total;
        }

        step += 1;

        if ((x == y) || ((x < 0) && (x == -y)) || ((x > 0) && (x == 1-y))) {
            dxtmp = dx;
            dx = -dy;
            dy = dxtmp;
        }
        x += dx;
        y += dy;
    }
}

int main()
{
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
        printf("%d\n", part1(atoi(line)));
        printf("%d\n", part2(atoi(line)));
    }

    return 0;
}
