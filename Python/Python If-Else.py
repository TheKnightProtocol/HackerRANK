n = int(input().strip())

if n % 2 == 1:  # n is odd
    print("Weird")
else:  # n is even
    if 2 <= n <= 5:
        print("Not Weird")
    elif 6 <= n <= 20:
        print("Weird")
    elif n > 20:
        print("Not Weird")
