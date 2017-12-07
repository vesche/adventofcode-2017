#!/usr/bin/env python

import time

with open('day06.input') as f:
    data = map(int, f.read().rstrip().split())

def part1n2():
    seen = []

    while data not in seen:
        seen.append(data[:])
        largest = max(data)
        loc = data.index(largest)
        data[loc] = 0

        while largest:
            loc = (loc+1)%len(data)
            data[loc] += 1
            largest -= 1

    return len(seen), len(seen) - seen.index(data)

print(part1n2())
