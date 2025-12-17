#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the bonAppetit function below.
def bonAppetit(bill, k, b):
    # Calculate total cost of items Anna ate (all items except the one at index k)
    total_cost = sum(bill) - bill[k]
    
    # Calculate Anna's fair share (half of what she actually ate)
    anna_share = total_cost // 2
    
    # Check if Brian's calculation is correct
    if b == anna_share:
        print("Bon Appetit")
    else:
        # Print the amount Brian owes Anna
        print(b - anna_share)

if __name__ == '__main__':
    # Read first line: n and k
    nk = input().rstrip().split()
    n = int(nk[0])
    k = int(nk[1])
    
    # Read second line: bill items
    bill = list(map(int, input().rstrip().split()))
    
    # Read third line: amount Brian charged Anna
    b = int(input().strip())
    
    # Call the function
    bonAppetit(bill, k, b)
