#!/usr/bin/env python

with open('day09.input') as f:
    data = f.read().rstrip()

def part1n2():
    score = group = junk = 0
    garbage = ignore = False

    for i in range(len(data)):
        c = data[i]

        if garbage:
            if ignore:
                ignore = False
            elif c == '!':
                ignore = True
            elif c == '>':
                garbage = False
            else:
                junk += 1
        else:
            if c == '<':
                garbage = True
            elif c == '{':
                group += 1
            elif c == '}':
                score += group
                group -= 1

    return score, junk

print(part1n2())
