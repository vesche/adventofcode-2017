#!/usr/bin/env python

import itertools

with open('day02.input') as f:
    data = []
    for line in f.read().splitlines():
        data.append(list(map(int, line.split())))

def part1():
    checksum = 0
    for row in data:
        checksum += max(row) - min(row)
    return checksum

def part2():
    checksum = 0
    for row in data:
        combos = list(itertools.combinations(row, 2))
        for c in combos:
            a, b = max(c), min(c)
            if a % b == 0:
                checksum += a//b
    return checksum

print(part1())
print(part2())
