#!/usr/bin/env python

with open('day05.input') as f:
    data1 = [int(i) for i in f.read().splitlines()]
    data2 = list(data1)

def part1(part2, data):
    current = 0
    steps = 0

    while True:
        try:
            move = data[current]
            if part2 and move >= 3:
                data[current] -= 1
            else:
                data[current] += 1
            current += move
            steps += 1
        except IndexError:
            break

    return steps

print(part1(0, data1))
print(part1(1, data2))
