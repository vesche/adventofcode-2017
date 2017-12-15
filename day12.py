#!/usr/bin/env python

with open('day12.input') as f:
    data = [line.split('<->') for line in f.read().splitlines()]

def fixlist(li):
    return list(set(li))

def part1n2():
    d = {}
    foo = []
    for line in data:
        d[int(line[0])] = map(int, line[1].split(','))

    count = 0
    count2 = 1
    for i in range(len(d)):
        all_values = []
        curr_values = d[i]
        tmp_values = d[i]

        for _ in range(20):
            all_values += curr_values
            curr_values = []
            for v in tmp_values:
                curr_values += d[v]
            tmp_values = curr_values[:]
            tmp_values = fixlist(tmp_values)
            all_values = fixlist(all_values)

        if 0 in all_values:
            count += 1
        else:
            new_group = True
            for bar in foo:
                for v in all_values:
                    if v in bar:
                        new_group = False
                        break
            if new_group:
                foo.append(all_values)
                count2 +=1

    return count, count2

print(part1n2())
