#!/usr/bin/env python

with open('day10.input') as f:
    raw_data = f.read().rstrip()
    data = map(int, raw_data.split(','))
    data2 = map(ord, raw_data) + [17, 31, 73, 47, 23]

def part1():
    size = 256
    li = range(size)
    pos = skip = 0

    for n in data:
        new_li = []
        for i in range(n):
            new_li.append(li[(pos+i)%size])

        new_li = new_li[::-1]
        for i in range(n):
            li[(pos+i)%size] = new_li[i]

        pos += (n + skip)
        skip += 1

    return li[0] * li[1]

def part2():
    size = 256
    li = range(size)
    pos = skip = 0

    for _ in range(64):
        for n in data2:
            new_li = []
            for i in range(n):
                new_li.append(li[(pos+i)%size])

            new_li = new_li[::-1]
            for i in range(n):
                li[(pos+i)%size] = new_li[i]

            pos += (n + skip)
            skip += 1

    h = [0]*16
    hi = 0
    for i in range(0, 256, 16):
        for j in range(i, i+16):
            h[hi] ^= li[j]
        hi += 1

    shex = ['%0.2x'%i for i in h]
    return ''.join(shex)

print(part1())
print(part2())
