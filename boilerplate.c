#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "day01.input"

void part1()
{
}

void part2()
{
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
        printf("%s", line);
    }

    return 0;
}
