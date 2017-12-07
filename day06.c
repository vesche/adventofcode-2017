#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INPUT "day06.input"

// incomplete as of right now

int part1(int numbers[16])
{
    int i, start, biggest, count, blocks, reallocate[16], chunk, ri;
    float ratio;
    char seen[12288];

    biggest = count = 0;

    for (i = 0; i < 16; i++) {
        if (numbers[i] > biggest) {
            biggest = numbers[i];
            start = i;
        }
        reallocate[i] = 0;
    }

    // return round(7/(float)4);

    for (;;) {
        count += 1;
        blocks = numbers[start];

        ratio = blocks/16.0;
        if (ratio <= 1) {
            for (i = 0; i < blocks; i++) {
                reallocate[i] = 1;
            }
        } else {
            chunk = round(ratio);
            if (blocks != chunk*16) {
                for (i = 0; i < 15; i++) {
                    reallocate[i] = chunk;
                }
                reallocate[15] = chunk*16-blocks;
            } else {
                for (i = 0; i < 16; i++)
                    reallocate[i] = chunk;
            }
        }

        numbers[start] = 0;
        ri = start + 1;
        for (i = 0; i < 16; i++) {
            numbers[ri%16] += reallocate[i];
            ri += 1;
        }

        for (i = 0; i < 16; i++) {
            printf("%d ", numbers[i]);
        }
        break;

        //char *snumb;
        //for (i = 0; i < 16; i++ ) {
        //    
        //}

        //for (i = 0; i < count-1; i++) {
        //    if (numbers == 
        //}

    }

    return 0;
}

int part2(int numbers[16])
{
    return 0;
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

        printf("%d\n", part1(numbers));
    }

    return 0;
}
