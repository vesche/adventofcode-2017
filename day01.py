#!/usr/bin/env python

with open('day01.input') as f:
    data = f.read().rstrip()

def part1():
    count = 0
    for i in range(len(data)):
        if data[i] == data[i-1]:
            count += int(data[i])
    return count

def part2():
    count = 0
    data_len = len(data)
    for i in range(data_len)[::-1]:
        if data[i] == data[int(i-(data_len/2))]:
            count += int(data[i])
    return count

print(part1())
print(part2())
