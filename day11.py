#!/usr/bin/env python

with open('day11.input') as f:
    data = f.read().rstrip().split(',')

def distance(x, y, z):
    return max(abs(x), abs(y), abs(z))

def part1n2():
    x = y = z = 0
    farthest = 0

    for move in data:
        if move == 'n':
            x += 1
            y -= 1
        elif move == 's':
            x -= 1
            y += 1
        elif move == 'ne':
            x += 1
            z -= 1
        elif move == 'nw':
            y -= 1
            z += 1
        elif move == 'se':
            y += 1
            z -= 1
        elif move == 'sw':
            x -= 1
            z += 1

        d = distance(x, y, z)
        if d > farthest:
            farthest = d

    return distance(x, y, z), farthest

print(part1n2())
