#!/usr/bin/env python

import adventapi

data = adventapi.getinput('1')

count = 0
for i in range(len(data)):
    if data[i] == data[i-1]:
        count += int(data[i])

print(count)
