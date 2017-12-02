#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "day01.input"

int part1(char* seq)
{
    int i, count;
    char first, previous;

    count = 0;
    first = seq[0];
    previous = first;

    for (i = 1; i < strlen(seq); i++) {
        if (seq[i] == previous)
            count += seq[i] - '0';
        previous = seq[i];
    }

    if (previous == first) {
        count += previous - '0';
    }

    return count;
}

int part2(char* seq)
{
    int i, count, seqlen, pair;

    count = 0;
    seqlen = strlen(seq);

    for (i = 0; i < seqlen; i++) {
        if (i < seqlen/2)
            pair = i + seqlen/2;
        else
            pair = i - seqlen/2;
        if (seq[i] == seq[pair])
            count += seq[i] - '0';
    }

    return count;
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
        printf("%d\n", part1(line));
        printf("%d\n", part2(line));
    }

    return 0;
}
