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
            result = max(c) / min(c)
            if result == int(result):
                checksum += int(result)
    return checksum

print(part1())
print(part2())
