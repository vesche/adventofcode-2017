#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "day05.input"

int part1(int numbers[1069], int part2)
{
    int current, steps, move;
    current = steps = 0;

    while (current <= 1069 && current >= 0) {
        move = numbers[current];
        if (part2 && move >= 3)
            numbers[current] -= 1;
        else
            numbers[current] += 1;
        current += move;
        steps += 1;
    }

    return steps;
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

    int i = 0;
    int numbers1[1069];
    int numbers2[1069];

    while (getline(&line, &len, fp) != -1) {
        line[strcspn(line, "\r\n")] = 0;
        numbers1[i] = atoi(line);
        numbers2[i] = atoi(line);
        i++;
    }

    printf("%d\n", part1(numbers1, 0));
    printf("%d\n", part1(numbers2, 1));

    return 0;
}
