#!/bin/env python3
import sys


def rot47(line):
    return ''.join([chr(33+(ord(i)+47-33) % 94) if ord(i) > 32 and ord(i) < 127 else i
            for i in line])


if __name__ == "__main__":
    if len(sys.argv) > 1:
        for filename in sys.argv[1:]:
            with open(filename) as f:
                for line in f:
                    print(rot47(line), end='')
    else:
        for line in sys.stdin:
            print(rot47(line), end='')
