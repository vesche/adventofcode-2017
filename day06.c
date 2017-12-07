#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define INPUT "day06.input"

void part1n2(int numbers[16])
{
    int i, j, count, largest, loc, check;
    int seen[12288][16];

    count = largest = 0;

    while (count < 12288) {
        // check if the same
        for (i = 0; i < count; i++) {
            int equal = 0;
            for (j = 0; j < 16; j++)
                if (numbers[j] == seen[i][j])
                    equal++;
                else
                    break;
            if (equal == 16) {
                printf("%d %d\n", count, count-i);
                return;
            }
        }

        // fill seen with current numbers
        for (i = 0; i < 16; i++)
            seen[count][i] = numbers[i];
        count += 1;

        // find largest number and index
        for (i = 0; i < 16; i++) {
            if (numbers[i] > largest) {
                largest = numbers[i];
                loc = i;
            }
        }

        // increment array
        numbers[loc] = 0;
        while (largest != 0) {
            loc = (loc + 1) % 16;
            numbers[loc] += 1;
            largest -= 1;
        }
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

        int numbers[16];
        int i = 0;
        char *p = strtok(line, "\t");

        while (p != NULL) {
            numbers[i++] = atoi(p);
            p = strtok(NULL, "\t");
        }

        part1n2(numbers);
    }

    return 0;
}
