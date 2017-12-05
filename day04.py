#!/usr/bin/env python

with open('day04.input') as f:
    data = [line.split() for line in f.read().splitlines() if line]

def part1():
    count = 0
    for words in data:
        if len(words) == len(set(words)):
            count += 1
    return count

def part2():
    count = 0
    for words in data:
        if len(words) != len(set(words)):
            continue
        li = [''.join(sorted(word)) for word in words]
        if len(li) == len(set(li)):
            count += 1
    return count

print(part1())
print(part2())
