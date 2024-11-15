#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'abbreviation' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. STRING a
#  2. STRING b
#

def abbreviation(a, b):
    lb, la = len(b), len(a)
    dp = [[False]*(la+1) for _ in range(la+1)]
    
    dp[0][0] = True
    for bi in range(lb+1):
        for ai in range(1, la+1):
            if a[ai-1] == b[bi-1]:
                dp[bi][ai] = dp[bi-1][ai-1]
            elif a[ai-1].upper() == b[bi-1]:
                dp[bi][ai] = dp[bi-1][ai-1] or dp[bi][ai-1]
            elif a[ai-1].islower():
                dp[bi][ai] = dp[bi][ai-1]
    
    if dp[lb][la]:
        return "YES"
    else:
        return "NO"
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        a = input()

        b = input()

        result = abbreviation(a, b)

        fptr.write(result + '\n')

    fptr.close()
98 
