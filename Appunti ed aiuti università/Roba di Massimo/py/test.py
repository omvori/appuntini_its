a = [3, -1, -4, -2, 10, 2]
b = sorted(a, key = lambda x : (1 if x < 0 else 0, abs(x)))
print(b)
