#!/usr/bin/env python

with open('day07.input') as f:
    data = f.read().splitlines()

def part1():
    li = []

    for line in data:
        if '->' in line:
            line = line.split()
            parent, weight, children = line[0], int(line[1][1:-1]), \
                ''.join(line[3:]).split(',')
            li.append([parent, children])

    for i in li:
        parent = i[0]
        count = 0
        for j in li:
            if parent in j[1]:
                break
            else:
                count += 1
        if count == len(li):
            return parent

def part2():
    pass

print(part1())
print(part2())
