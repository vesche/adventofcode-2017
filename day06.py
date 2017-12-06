#!/usr/bin/env python

from __future__ import division

with open('day06.input') as f:
    data = map(int, f.read().rstrip().split())

def part1():
    count = 0
    seen = []
    run = True

    while run:
        count += 1

        datalen = len(data)
        start = data.index(max(data))
        blocks = data[start]

        ratio = blocks/datalen
        if ratio <= 1:
            reallocate = [1 for i in range(blocks)]
        else:
            foo = int(round(ratio))
            if blocks != foo*datalen:
                reallocate = [foo for i in range(datalen-1)]
                reallocate.append(foo*datalen-blocks)
            else:
                reallocate = [foo for i in range(datalen)]

        data[start] = 0
        ri = start + 1
        for i in reallocate:
            data[ri%datalen] += i
            ri += 1

        for i in seen:
            if data == i:
                run = False
        seen.append(data[:])

    return count

def part2():
    pass

print(part1())
print(part2())
