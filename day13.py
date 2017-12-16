#!/usr/bin/env python

from collections import deque

with open('day13.input') as f:
    data = [map(int, i.split(': ')) for i in f.read().splitlines()]

def shift(li, direction):
    if list(li).index('S') == 0:
        li.rotate(1)
        return [li, True]
    if list(li).index('S')+1 == len(li):
        li.rotate(-1)
        return [li, False]
    if direction:
        li.rotate(1)
        return [li, direction]
    else:
        li.rotate(-1)
        return [li, direction]

def part1():
    d = {}
    for i in data:
        li = ['S'] + (i[1]-1)*['_']
        d[i[0]] = [deque(li), True]

    for i in range(data[-1][0]+1):
        if i not in d:
            d[i] = [['_'], False]

    damage = 0
    for i in range(data[-1][0]+1):
        if d[i][0][0] == 'S':
            damage += i*len(d[i][0])
        for i in data:
            d[i[0]] = shift(d[i[0]][0], d[i[0]][1])

    return damage

# this works, but it's ungodly slow
def part2():
    d = {}
    for i in data:
        li = ['S'] + (i[1]-1)*['_']
        d[i[0]] = [deque(li), True]

    for i in range(data[-1][0]+1):
        if i not in d:
            d[i] = [['_'], False]

    pico = 1
    highest = 0
    while True:
        print(pico)
        d2 = {}
        for k, v in d.items():
            d2[k] = [deque(list(v[0])), True]

        for p in range(pico):
            for i in data:
                d2[i[0]] = shift(d2[i[0]][0], d2[i[0]][1])

        gotem = True
        for i in range(data[-1][0]+1):
            if d2[i][0][0] == 'S':
                gotem=False
                if i > highest:
                    highest = i
                    print((highest, pico))
                break
            for i in data:
                d2[i[0]] = shift(d2[i[0]][0], d2[i[0]][1])

        if gotem:
            return pico
        pico += 1

print(part1())
print(part2())
