#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "day04.input"

int part1(char words[12][8])
{
    int i, j;
    char *compare;

    for (i = 0; i <= sizeof(words); i++) {
        compare = words[i];
        for (j = 0; j <= sizeof(words); j++) {
            if (i == j) {
                continue;
            }
            if (strcmp(compare, words[j]) == 0) {
                return 0;
            }
        }
    }

    return 1;
}

int part2(char words[12][8])
{
    int i, j;
    char *word;

    for (i = 0; i <= sizeof(words); i++) {
        word = words[i];
        for (j = 0; j <= sizeof(words); j++) {
            if (i == j) {
                continue;
            }
            if (strcmp(word, words[j]) == 0) {
                return 0;
            }
        }
    }

    int h, n;
    char temp;
    char sortwords[12][8];

    // clear out sortwords, there's probably a better way of doing this...
    for (i = 0; i < 12; i++) {
        strcpy(sortwords[i], "\0\0\0\0\0\0\0\0");
    }

    for (i = 0; i <= sizeof(words); i++) {
        word = words[i];
        n = strlen(word);

        for (j = 0; j < n-1; j++) {
            for (h = j+1; h < n; h++) {
                int s = tolower(word[j]) - tolower(word[h]);
                if (s == 0)
                    s = word[j] - word[h];
                if (s > 0) {
                    temp = word[j];
                    word[j] = word[h];
                    word[h] = temp;
                }
            }
        }
        // add sorted word to new array
        strcpy(sortwords[i], word);
    }

    for (i = 0; i < 12; i++) {
        word = sortwords[i];
        for (j = 0; j < 8; j++) {
            if (i == j) {
                continue;
            }
            if (strcmp(word, sortwords[j]) == 0) {
                // printf("%s %s\n", word, sortwords[j]);
                return 0;
            }
        }
    }

    return 1;
}

int main()
{
    int count1 = 0;
    int count2 = 0;

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

        char words1[12][8];
        char words2[12][8];
        int i = 0;
        int i2 = 0;

        char *p = strtok(line, " ");

        while (p != NULL) {
            strcpy(words1[i++], p);
            strcpy(words2[i2++], p);
            p = strtok(NULL, " ");
        }

        count1 += part1(words1);
        count2 += part2(words2);
    }

    printf("%d\n", count1);
    printf("%d\n", count2);

    return 0;
}
