#!/usr/bin/env python

with open('day08.input') as f:
    data = [line.split() for line in f.read().splitlines()]

def part1n2():
    d = {}
    for line in data:
        d[line[0]] = 0

    largest = 0
    for line in data:
        reg, opr, val, _, xreg, xopr, xval = line
        opr = '+=' if opr == 'inc' else '-='
        exec('if d["{}"] {} {}: d["{}"] {} {}'.format(
            xreg, xopr, xval, reg, opr, val))
        current_largest = d[max(d, key=d.get)]
        if current_largest > largest:
            largest = current_largest

    return d[max(d, key=d.get)], largest

print(part1n2())
