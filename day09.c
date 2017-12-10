#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "day09.input"

void part1n2(char *line)
{
    char c;
    int i, garbage, ignore, group, score, garbage_score;
    garbage = ignore = group = score = garbage_score = 0;

    for (i = 0; i < strlen(line); i++) {
        c = line[i];
        if (garbage) {
            if (ignore)
                ignore = 0;
            else if (c == '!')
                ignore = 1;
            else if (c == '>')
                garbage = 0;
            else
                garbage_score += 1;
        } else {
            if (c == '<')
                garbage = 1;
            else if (c == '{')
                group += 1;
            else if (c == '}') {
                score += group;
                group -= 1;
            }
        }
    }

    printf("%d %d\n", score, garbage_score);
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
        part1n2(line);
    }

    return 0;
}
