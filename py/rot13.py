#!/bin/env python3
import sys


def rot13(line):
    return [chr(33+(ord(i)+13-33) % 94) for i in line]


if len(sys.argv) > 1:
    for filename in sys.argv[1:]:
        with open(filename) as f:
            for line in f:
                print(''.join(rot13(line)))
else:
    for line in sys.stdin:
        print(''.join(rot13(line)))
