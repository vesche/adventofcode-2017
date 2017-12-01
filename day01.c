#include <stdio.h>

int main()
{
    int c, count;
    char first, previous;

    count = 0;

    first = getchar();
    previous = first;

    for (;;) {
        c = getchar();
        if ((c == EOF) || (c == '\n'))
            break;
        if (c == previous)
            count += c - '0';
        previous = c;
    }

    if (previous == first) {
        count += previous - '0';
    }

    printf("%d\n", count);
    return 0;
}

