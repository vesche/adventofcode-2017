#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "day02.input"

int part1(int numbers[16])
{
    int i, largest, smallest, result;

    largest = 0;
    smallest = 1000;

    for (i = 0; i < 16; i++) {
        if (numbers[i] > largest)
            largest = numbers[i];
        if (numbers[i] < smallest)
            smallest = numbers[i];
    }

    result = largest - smallest;

    return result;
}

int part2(int numbers[16])
{
    int i, j, n1, n2, divisible, result;

    for (i = 0; i < 16; i++) {
        n1 = numbers[i];
        for (j = 0; j < 16; j++) {
            n2 = numbers[j];
            if (n1 == n2)
                continue;
            if (n1 > n2) {
                divisible = n1 % n2;
                result = n1 / n2;
            } else {
                divisible = n2 % n1;
                result = n2 / n1;
            }
            if (divisible == 0)
                return result;
        }
    }
}

int main()
{
    int checksum1 = 0;
    int checksum2 = 0;

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

        int numbers[16];
        int i = 0;
        char *p = strtok(line, "\t");

        while (p != NULL) {
            numbers[i++] = atoi(p);
            p = strtok(NULL, "\t");
        }

        checksum1 += part1(numbers);
        checksum2 += part2(numbers);
    }

    printf("%d\n", checksum1);
    printf("%d\n", checksum2);

    return 0;
}
